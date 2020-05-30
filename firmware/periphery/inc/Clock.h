/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Clock.h                                                          *
 * author      Ila Galkin                                                       *
 * date        15.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       System clock system                                              *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"
#include "Gpio.h"

/********************************************************************************
 * Class Clock
 *
 * Initialization for the clock's system
 * Source - external crystall
 * Frequency external crystal   - 8 000 000 Hz
 * Frequency for system clock   - 72 000 000 Hz
 * Divider for ADC clock system - 10
 * 
 ********************************************************************************/

class Clock {

    public:
        enum class Status {
            disable, enable
        };

    public:
        static void Init (void);
        static void EnableMCO (Status status);
};