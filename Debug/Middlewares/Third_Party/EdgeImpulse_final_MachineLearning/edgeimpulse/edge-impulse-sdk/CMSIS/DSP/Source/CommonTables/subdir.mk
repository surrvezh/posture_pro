################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.c \
../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.c \
../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.c \
../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.c \
../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.c \
../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.c 

C_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.d \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.d \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.d \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.d \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.d \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.d 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.o \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.o \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.o \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.o \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.o \
./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/%.o Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/%.su Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/%.cyclo: ../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/%.c Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_final_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-DSP-2f-Source-2f-CommonTables

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_final_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-DSP-2f-Source-2f-CommonTables:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.cyclo ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.d ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.o ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.su ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.cyclo ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.d ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.o ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.su ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.cyclo ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.d ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.o ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.su ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.cyclo ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.d ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.o ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.su ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.cyclo ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.d ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.o ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.su ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.cyclo ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.d ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.o ./Middlewares/Third_Party/EdgeImpulse_final_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_final_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-DSP-2f-Source-2f-CommonTables

