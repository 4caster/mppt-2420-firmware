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

/********************************************************************************
 * Main program body
 ********************************************************************************/

int main (void) {

    RCC->AHBENR  |= RCC_AHBENR_GPIOBEN;     // Clock enable for GPIO port B
    RCC->AHBENR  |= RCC_AHBENR_GPIOAEN;     

	GPIOB->MODER &= ~GPIO_MODER_MODER5;     // Output push-pull
	GPIOB->MODER |= GPIO_MODER_MODER5_0;	

    GPIOA->MODER &= ~GPIO_MODER_MODER15;
	GPIOA->MODER |= GPIO_MODER_MODER15_0;	

    GPIOB->BSRR |= GPIO_BSRR_BS_5;
    GPIOA->BSRR |= GPIO_BSRR_BS_15;

    while(1) {}

}

/********************************* END OF FILE **********************************/


