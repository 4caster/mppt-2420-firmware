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
        static void Init () {
            Gpio::Init<5>(GPIOB, Gpio::Mode::output, Gpio::Type::PP);
            Gpio::Init<15>(GPIOA, Gpio::Mode::output, Gpio::Type::PP); 
        };

        static void On (Color led) {
            if (led == Color::green) { Gpio::Set<5>(GPIOB); }
            if (led == Color::yellow) { Gpio::Set<15>(GPIOA); }
        };

        static void Off (Color led) {
            if (led == Color::green) { Gpio::Reset<5>(GPIOB); }
            if (led == Color::yellow) { Gpio::Reset<15>(GPIOA); }
        };

        static void Toggle (Color led) {
            if (led == Color::green) { Gpio::Toggle<5>(GPIOB); }
            if (led == Color::yellow) { Gpio::Toggle<15>(GPIOA); }  
        };

    private:

};

/********************************* END OF FILE **********************************/