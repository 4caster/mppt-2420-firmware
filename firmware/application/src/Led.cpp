/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Led.cpp                                                          *
 * author      Ila Galkin                                                       *
 * date        11.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       class Led                                                        *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Led.h"

/********************************************************************************
 * Class control LED indicators
 ********************************************************************************/

void Led::Init () {
    Gpio::Init<5>(GPIOB, Gpio::mode::output, Gpio::type::PP);
    Gpio::Init<15>(GPIOA, Gpio::mode::output, Gpio::type::PP);       
}

void Led::On (color led) {
    if (led == color::GREEN) { Gpio::Set<5>(GPIOB); }
    if (led == color::YELLOW) { Gpio::Set<15>(GPIOA); }
}

void Led::Off (color led) {
    if (led == color::GREEN) { Gpio::Reset<5>(GPIOB); }
    if (led == color::YELLOW) { Gpio::Reset<15>(GPIOA); }
}

void Led::Toggle (color led) {
    if (led == color::GREEN) { Gpio::Toggle<5>(GPIOB); }
    if (led == color::YELLOW) { Gpio::Toggle<15>(GPIOA); }    
}
