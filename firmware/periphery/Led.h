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
            GREEN, YELLOW
        };

    public:
        static void Init () {
            Gpio::Init<5>(GPIOB, Gpio::Mode::output, Gpio::Type::PP);
            Gpio::Init<15>(GPIOA, Gpio::Mode::output, Gpio::Type::PP); 
        };

        static void On (Color led) {
            if (led == Color::GREEN) { Gpio::Set<5>(GPIOB); }
            if (led == Color::YELLOW) { Gpio::Set<15>(GPIOA); }
        };

        static void Off (Color led) {
            if (led == Color::GREEN) { Gpio::Reset<5>(GPIOB); }
            if (led == Color::YELLOW) { Gpio::Reset<15>(GPIOA); }
        };

        static void Toggle (Color led) {
            if (led == Color::GREEN) { Gpio::Toggle<5>(GPIOB); }
            if (led == Color::YELLOW) { Gpio::Toggle<15>(GPIOA); }  
        };

    private:

};

/********************************* END OF FILE **********************************/