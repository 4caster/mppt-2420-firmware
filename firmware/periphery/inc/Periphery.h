/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Periphery.h                                                      *
 * author      Ila Galkin                                                       *
 * date        30.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       Setting periphery MCU                                            *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Led.h"
#include "Hrpwm.h"
#include "Clock.h"
#include "Adc.h"

/********************************************************************************
 * Class Periphery
 ********************************************************************************/

class Periphery {
    public:
        static void Init (void) {
            Clock::Init();
            Led::Init();
            Hrpwm::Init();
            Adc::Init();
        }
};

/********************************* END OF FILE **********************************/