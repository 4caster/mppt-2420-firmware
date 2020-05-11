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
        enum class color:int {
            GREEN, YELLOW
        };

    public:
        static void Init ();
        static void On (color led);
        static void Off (color led);
        static void Toggle (color led);

    private:

};

/********************************* END OF FILE **********************************/