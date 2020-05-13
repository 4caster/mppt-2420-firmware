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

    RCC->CR |= RCC_CR_HSEON;                                    // Enable system for external crystall
	while (!(RCC->CR & RCC_CR_HSERDY));                         // Waiting flag about enable

    FLASH->ACR |= FLASH_ACR_LATENCY_1;                          // Latency for internal flash memory

    RCC->CFGR  |= RCC_CFGR_PLLMUL9;                             // Select multiplier frequency for PLL

    RCC->CFGR  |= RCC_CFGR_PLLSRC;                              // Select source external crystall
    RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV10;                     // Select divider for ADC = AHB/10

    RCC->CR |= RCC_CR_PLLON;                                    // Enable PLL system
	while((RCC->CR & RCC_CR_PLLRDY) == 0){}                     // Waiting flag about enable

    RCC->CFGR |= RCC_CFGR_SW_PLL;                               // Select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {}      // Waiting flag about enable

    Led::Init();

    Hrpwm::InitHrpwm (Hrpwm::Channel::channelA, 45000);
    Hrpwm::SetDuty (Hrpwm::Channel::channelA, 18000);

    while(1) {
        Led::Toggle(Led::Color::YELLOW);
        delay(500000);
    }

}

/********************************* END OF FILE **********************************/


