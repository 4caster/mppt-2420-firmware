/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        main.cpp                                                         *
 * author      Ila Galkin                                                       *
 * date        07.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       Main program body                                                *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "main.h"

void delay(uint32_t time_delay)
{	
    volatile uint32_t i;
    for(i = 0; i < time_delay; i++);
}

/********************************************************************************
 * Main program body
 ********************************************************************************/

int main (void) {

    Gpio::init<15>(GPIOA, Gpio::mode::output, Gpio::type::PP);
    Gpio::set<15>(GPIOA);

//    Led::init();

    while(1) {
//        Led::toggle(Led::Color::YELLOW);
//        delay(200000);
    }

}

/********************************* END OF FILE **********************************/


