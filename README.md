# POSTURE PRO

## Introduction

Posture Pro is a health monitoring system designed to combat sedentary lifestyles, particularly among wheelchair users. Using IoT technology and machine learning, it continuously monitors posture and transmits health data to caregivers in real-time, aiming to prevent pressure ulcers. It collects posture and health data, integrates sensors, and processes information for proactive healthcare management.

## Hardware Setup

### Load Cells

- **Left Load Cell:** 
  - SCK pin: PC3 
  - DT pin: PA4 
  - Calibration value: 43.06
- **Front Load Cell:** 
  - SCK pin: PC4 
  - DT pin: PB1 
  - Calibration value: -46.38
- **Right Load Cell:** 
  - SCK pin: PC2 
  - DT pin: PA3 
  - Calibration value: -45.18
- **Back Load Cell:** 
  - SCK pin: PC5 
  - DT pin: PB4 
  - Calibration value: -53.89

## Software Setup

Kindly ensure that the project is configured as a C++ project.

### Edge Impulse SDK

We have used Edge Impulse to create the machine learning model. To add the package, kindly find it in the submitted drive folder (.pack file). The pack file should be added to software packs.

### HX711 Library

We have created our own library to process data from load cells. Library files `HX711_ADC.cpp`, `config.h`, `HX711_ADC.h` can be found within the project folder.

## Working

The model takes four inputs from four HX711 ADCs and predicts the output from one of the output classes: `bent forward`, `bent right`, `bent left`, `correct posture`.
