/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Hrpwm.h                                                          *
 * author      Ila Galkin                                                       *
 * date        13.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       High resolution PWM                                              *
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

class Hrpwm {

    public:
        enum class Channel:int {
            channelA, channelB, channelC, channelD
        };

    public:
        static void InitHrpwm (Channel channel, uint16_t period);
        static void SetDuty (Channel channel, uint16_t duty);

    private:
        static void InitGpio (Channel channel);
        static void SelectEventForExternalGeneration (uint16_t compare);

};

/********************************* END OF FILE **********************************/