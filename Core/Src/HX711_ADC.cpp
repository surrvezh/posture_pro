#include "stm32l4xx_hal.h"


#include "HX711_ADC.h"





HX711_ADC::HX711_ADC(GPIO_TypeDef* doutPort, uint16_t doutPin, GPIO_TypeDef* sckPort, uint16_t sckPin)
{
	this->doutPort_ = doutPort;
	    this->doutPin_ = doutPin;
	    this->sckPort_ = sckPort;
	    this->sckPin_ = sckPin;
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Configure DOUT pin
    GPIO_InitStruct.Pin = doutPin_;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(doutPort_, &GPIO_InitStruct);

    // Configure SCK pin
    GPIO_InitStruct.Pin = sckPin_;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(sckPort_, &GPIO_InitStruct);
}



void HX711_ADC::setGain(uint8_t gain)
{
	if(gain < 64) GAIN = 2; //32, channel B
	else if(gain < 128) GAIN = 3; //64, channel A
	else GAIN = 1; //128, channel A
}

void HX711_ADC::begin()
{
	setGain(128);
	powerUp();
}


void HX711_ADC::begin(uint8_t gain)
{

	setGain(gain);
	powerUp();
}


void HX711_ADC::start(unsigned long t)
{
    t += 400;
    lastDoutLowTime = HAL_GetTick();

    while (HAL_GetTick() < (lastDoutLowTime + t))
    {
        update();
        HAL_Delay(1);
    }

    tare();
    tareStatus = 0;
}



void HX711_ADC::start(unsigned long t, bool dotare)
{
    t += 400;
    lastDoutLowTime = HAL_GetTick();

    while (HAL_GetTick() < t)
    {
        update();

        HAL_Delay(1);
    }

    if (dotare)
    {
        tare();
        tareStatus = 0;
    }
}


int HX711_ADC::startMultiple(unsigned long t)
{
    tareTimeoutFlag = 0;
    lastDoutLowTime = HAL_GetTick();

    if (startStatus == 0)
    {
        if (isFirst)
        {
            startMultipleTimeStamp = HAL_GetTick();
            if (t < 400)
            {
                startMultipleWaitTime = t + 400;
            }
            else
            {
                startMultipleWaitTime = t;
            }
            isFirst = 0;
        }

        if ((HAL_GetTick() - startMultipleTimeStamp) < startMultipleWaitTime)
        {
            update();
             HAL_Delay(1);
            return 0;
        }
        else
        {
            static unsigned long timeout = HAL_GetTick() + tareTimeOut;
            doTare = 1;
            update();

            if (convRslt == 2)
            {
                doTare = 0;
                convRslt = 0;
                startStatus = 1;
            }

            if (!tareTimeoutDisable)
            {
                if (HAL_GetTick() > timeout)
                {
                    tareTimeoutFlag = 1;
                    return 1;
                }
            }
        }
    }

    return startStatus;
}


int HX711_ADC::startMultiple(unsigned long t, bool dotare)
{
    tareTimeoutFlag = 0;
    lastDoutLowTime = HAL_GetTick();

    if (startStatus == 0)
    {
        if (isFirst)
        {
            startMultipleTimeStamp = HAL_GetTick();
            if (t < 400)
            {
                startMultipleWaitTime = t + 400;
            }
            else
            {
                startMultipleWaitTime = t;
            }
            isFirst = 0;
        }

        if ((HAL_GetTick() - startMultipleTimeStamp) < startMultipleWaitTime)
        {
            update();
            HAL_Delay(1);
            return 0;
        }
        else
        {

            if (dotare)
            {
                static unsigned long timeout = HAL_GetTick() + tareTimeOut;
                doTare = 1;
                update();

                if (convRslt == 2)
                {
                    doTare = 0;
                    convRslt = 0;
                    startStatus = 1;
                }

                if (!tareTimeoutDisable)
                {
                    if (HAL_GetTick() > timeout)
                    {
                        tareTimeoutFlag = 1;
                        return 1;
                    }
                }
            }
            else
            {
                return 1;
            }
        }
    }

    return startStatus;
}


void HX711_ADC::tare()
{
    uint8_t rdy = 0;
    doTare = 1;
    tareTimes = 0;
    tareTimeoutFlag = 0;
    unsigned long timeout = HAL_GetTick() + tareTimeOut;

    while (rdy != 2)
    {
        rdy = update();

        if (!tareTimeoutDisable)
        {
            if (HAL_GetTick() > timeout)
            {
                tareTimeoutFlag = 1;
                break;
            }
        }

        HAL_Delay(1);
    }
}

void HX711_ADC::tareNoDelay() 
{
	doTare = 1;
	tareTimes = 0;
	tareStatus = 0;
}

void HX711_ADC::setCalFactor(float cal) 
{
	calFactor = cal;
	calFactorRecip = 1/calFactor;
}

bool HX711_ADC::getTareStatus() 
{
	bool t = tareStatus;
	tareStatus = 0;
	return t;
}
float HX711_ADC::getCalFactor() 
{
	return calFactor;
}


uint8_t HX711_ADC::update()
{

    uint8_t dout = HAL_GPIO_ReadPin(doutPort_, doutPin_);

    if (!dout)
    {
        conversion24bit();
        lastDoutLowTime = HAL_GetTick();
        signalTimeoutFlag = 0;
    }
    else
    {
    	if (HAL_GetTick() > (lastDoutLowTime + SIGNAL_TIMEOUT))
    		if (HAL_GetTick() - lastDoutLowTime > SIGNAL_TIMEOUT)
        {
            signalTimeoutFlag = 1;
            convRslt = 0;
        }
    }

    return convRslt;
}


bool HX711_ADC::dataWaitingAsync()
{
    if (dataWaiting)
    {
        lastDoutLowTime = HAL_GetTick();
        return true;
    }

    uint8_t dout = HAL_GPIO_ReadPin(doutPort_, doutPin_); // Check if conversion is ready

    if (!dout)
    {
        dataWaiting = true;
        lastDoutLowTime = HAL_GetTick();
        signalTimeoutFlag = 0;
        return true;
    }
    else
    {
        if (HAL_GetTick() - lastDoutLowTime > SIGNAL_TIMEOUT)
        {
            signalTimeoutFlag = 1;
            convRslt = 0;
        }
    }

    return false;
}

bool HX711_ADC::updateAsync() 
{
	if (dataWaiting) { 
		conversion24bit();
		dataWaiting = false;
		return true;
	}
	return false;

}

float HX711_ADC::getData()
{
	long data = 0;
	lastSmoothedData = smoothedData();
	data = lastSmoothedData - tareOffset ;
	float x = (float)data * calFactorRecip;
	return x;
}

long HX711_ADC::smoothedData() 
{
	long data = 0;
	long L = 0xFFFFFF;
	long H = 0x00;
	for (uint8_t r = 0; r < (samplesInUse + IGN_HIGH_SAMPLE + IGN_LOW_SAMPLE); r++) 
	{
		#if IGN_LOW_SAMPLE
		if (L > dataSampleSet[r]) L = dataSampleSet[r];
		#endif
		#if IGN_HIGH_SAMPLE
		if (H < dataSampleSet[r]) H = dataSampleSet[r];
		#endif
		data += dataSampleSet[r];
	}
	#if IGN_LOW_SAMPLE 
	data -= L;
	#endif
	#if IGN_HIGH_SAMPLE 
	data -= H;
	#endif

	return (data >> divBit);

}



void HX711_ADC::conversion24bit()
{
    conversionTime = HAL_GetTick() - conversionStartTime;
    conversionStartTime = HAL_GetTick();
    uint32_t data = 0;
    uint8_t dout;
    convRslt = 0;
    __disable_irq();

    for (uint8_t i = 0; i < (24 + GAIN); i++)
    {
        HAL_GPIO_WritePin(sckPort_, sckPin_, GPIO_PIN_SET);
        if(SCK_DELAY) HAL_Delay(1);

        HAL_GPIO_WritePin(sckPort_, sckPin_, GPIO_PIN_RESET);
        if (i < 24)
        {
            dout = HAL_GPIO_ReadPin(doutPort_, doutPin_);
            data = (data << 1) | dout;
        }
        else
        {
            if(SCK_DELAY) HAL_Delay(1);
        }
    }
    __enable_irq();

    data ^= 0x800000;

    if (data > 0xFFFFFF)
    {
        dataOutOfRange = 1;
    }

    if (reverseVal)
    {
        data = 0xFFFFFF - data;
    }

    if (readIndex == samplesInUse + IGN_HIGH_SAMPLE + IGN_LOW_SAMPLE - 1)
    {
        readIndex = 0;
    }
    else
    {
        readIndex++;
    }

    if(data > 0)
    {
        convRslt++;
        dataSampleSet[readIndex] = static_cast<long>(data);
        if(doTare)
        {
            if (tareTimes < DATA_SET)
            {
                tareTimes++;
            }
            else
            {
                tareOffset = smoothedData();
                tareTimes = 0;
                doTare = 0;
                tareStatus = 1;
                convRslt++;
            }
        }
    }
}




void HX711_ADC::powerDown() 
{
    HAL_GPIO_WritePin(sckPort_, sckPin_, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(sckPort_, sckPin_, GPIO_PIN_SET);
}


void HX711_ADC::powerUp() 
{

	HAL_GPIO_WritePin(sckPort_, sckPin_, GPIO_PIN_RESET);
}


long HX711_ADC::getTareOffset() 
{
	return tareOffset;
}

void HX711_ADC::setTareOffset(long newoffset)
{
	tareOffset = newoffset;
}

int HX711_ADC::getReadIndex()
{
	return readIndex;
}

float HX711_ADC::getConversionTime()
{
	return conversionTime/1000.0;
}


float HX711_ADC::getSPS()
{
	float sps = 1000000.0/conversionTime;
	return sps;
}

bool HX711_ADC::getTareTimeoutFlag() 
{
	return tareTimeoutFlag;
}

void HX711_ADC::disableTareTimeout()
{
	tareTimeoutDisable = 1;
}

long HX711_ADC::getSettlingTime() 
{
	long st = getConversionTime() * DATA_SET;
	return st;
}


void HX711_ADC::setSamplesInUse(int samples)
{
	int old_value = samplesInUse;
	
	if(samples <= SAMPLES)
	{
		if(samples == 0)
		{
			divBit = divBitCompiled;
		} 
		else
		{
			samples >>= 1;
			for(divBit = 0; samples != 0; samples >>= 1, divBit++);
		}
		samplesInUse = 1 << divBit;
		if(samplesInUse != old_value) 
		{
			for (uint8_t r = 0; r < samplesInUse + IGN_HIGH_SAMPLE + IGN_LOW_SAMPLE; r++) 
			{
				dataSampleSet[r] = lastSmoothedData;
			}
			readIndex = 0;
		}
	}
}

int HX711_ADC::getSamplesInUse()
{
	return samplesInUse;
}

void HX711_ADC::resetSamplesIndex()
{
	readIndex = 0;
}


bool HX711_ADC::refreshDataSet()
{
    int s = getSamplesInUse() + IGN_HIGH_SAMPLE + IGN_LOW_SAMPLE; // get number of samples in dataset
    resetSamplesIndex();
    while (s > 0)
    {
        update();

        if (HAL_GPIO_ReadPin(doutPort_, doutPin_) == GPIO_PIN_RESET)
        {
            getData();
            s--;
        }
    }
    return true;
}

bool HX711_ADC::getDataSetStatus()
{
	bool i = false;
	if (readIndex == samplesInUse + IGN_HIGH_SAMPLE + IGN_LOW_SAMPLE - 1) 
	{
		i = true;
	}
	return i;
}

float HX711_ADC::getNewCalibration(float known_mass)
{
	float readValue = getData();
	float exist_calFactor = getCalFactor();
	float new_calFactor;
	new_calFactor = (readValue * exist_calFactor) / known_mass;
	setCalFactor(new_calFactor);
    return new_calFactor;
}

bool HX711_ADC::getSignalTimeoutFlag()
{
	return signalTimeoutFlag;
}

void HX711_ADC::setReverseOutput() {
	reverseVal = true;
}
