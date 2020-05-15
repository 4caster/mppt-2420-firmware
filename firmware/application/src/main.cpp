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

    Clock::Init();
    Led::Init();

    Hrpwm::InitHrpwm (Hrpwm::Channel::channelA, 45000);
    Hrpwm::SetDuty (Hrpwm::Channel::channelA, 18000);

    while(1) {
        Led::Toggle(Led::Color::YELLOW);
        delay(1000000);
    }

}

/********************************* END OF FILE **********************************/


