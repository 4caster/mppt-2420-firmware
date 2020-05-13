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
    Gpio::Init<5>(GPIOB, Gpio::Mode::output, Gpio::Type::PP);
    Gpio::Init<15>(GPIOA, Gpio::Mode::output, Gpio::Type::PP);       
}

void Led::On (Color led) {
    if (led == Color::GREEN) { Gpio::Set<5>(GPIOB); }
    if (led == Color::YELLOW) { Gpio::Set<15>(GPIOA); }
}

void Led::Off (Color led) {
    if (led == Color::GREEN) { Gpio::Reset<5>(GPIOB); }
    if (led == Color::YELLOW) { Gpio::Reset<15>(GPIOA); }
}

void Led::Toggle (Color led) {
    if (led == Color::GREEN) { Gpio::Toggle<5>(GPIOB); }
    if (led == Color::YELLOW) { Gpio::Toggle<15>(GPIOA); }    
}

/********************************* END OF FILE **********************************/