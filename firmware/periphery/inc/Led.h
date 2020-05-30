/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Led.h                                                            *
 * author      Ila Galkin                                                       *
 * date        11.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       class Led                                                        *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"
#include "Gpio.h"

/********************************************************************************
 * Class
 ********************************************************************************/

class Led {

    public:
        enum class Color:int {
            green, yellow
        };

    public:
        static void Init (void);
        static void On (Color led);
        static void Off (Color led);
        static void Toggle (Color led);
};

/********************************* END OF FILE **********************************/