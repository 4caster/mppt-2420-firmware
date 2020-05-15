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
 * Class HRPWM
 ********************************************************************************/

class Clock {

    public:
        enum class Status {
            disable, enable
        };

    public:
        static void Init();
        static void EnableMCO (Status status);

};