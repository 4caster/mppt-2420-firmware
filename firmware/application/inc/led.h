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

/********************************************************************************
 * Class
 ********************************************************************************/

class Led {

    public:
        enum class Color {
            GREEN, YELLOW
        };

    public:
        static void init ();
        static void on (Color led);
        static void off (Color led);
        static void toggle (Color led);

    private:

};

/********************************* END OF FILE **********************************/