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

void Led::init () {
    RCC->AHBENR  |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN;

    GPIOB->MODER &= ~GPIO_MODER_MODER5;
	GPIOB->MODER |= GPIO_MODER_MODER5_0;	                    // Output push-pull PB5

    GPIOA->MODER &= ~GPIO_MODER_MODER15;
	GPIOA->MODER |= GPIO_MODER_MODER15_0;	                    // Output push-pull PA15         
}

void Led::on (Color led) {
    if (led == Color::GREEN) { GPIOB->BSRR |= GPIO_BSRR_BS_5; }
    if (led == Color::YELLOW) { GPIOA->BSRR |= GPIO_BSRR_BS_15; }
}

void Led::off (Color led) {
    if (led == Color::GREEN) { GPIOB->BSRR |= GPIO_BSRR_BR_5; }
    if (led == Color::YELLOW) { GPIOA->BSRR |= GPIO_BSRR_BR_15; }
}

void Led::toggle (Color led) {
    if (led == Color::GREEN) { GPIOB->ODR ^= GPIO_ODR_5; }
    if (led == Color::YELLOW) { GPIOA->ODR ^= GPIO_ODR_15; }    
}
