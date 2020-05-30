/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Adc.cpp                                                          *
 * author      Ila Galkin                                                       *
 * date        20.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       ADC converter                                                    *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Adc.h"

/********************************************************************************
 * Class ADC
 ********************************************************************************/

void Adc::SetOutputDivider (Divider divider) {
    if (divider == Divider::div12V) { GPIOB->BSRR |= GPIO_BSRR_BR_14; }
    if (divider == Divider::div24V) { GPIOB->BSRR |= GPIO_BSRR_BS_14; }
}

void Adc::Init (void) {
    RCC->AHBENR |= RCC_AHBENR_ADC12EN;     

    Adc::GpioInit();
    Adc::InitTimerEvent();
    Adc::StartCallibrationAdc();

    ADC1->JSQR |= 0x1030817B;               // Lenght = 4, Trigger = event 14, Type trigger = rising edge, Channel = IN1, IN2, IN3 and IN4

    ADC1->IER |= ADC_IER_JEOSIE;            // Interrupt enable
    NVIC_EnableIRQ(ADC1_2_IRQn);            // Enable interrupt ADC1 and ADC2

    ADC1->CR |= ADC_CR_ADEN;                // Enable ADC1
    while(!(ADC1->ISR & ADC_ISR_ADRDY));    // Wait ready ADC1

    ADC1->CR |= ADC_CR_JADSTART;            // Enable injector conversion       
}

void Adc::GpioInit (void) {
    Gpio::Init<14>(GPIOB, Gpio::Mode::output, Gpio::Type::PP);
    Gpio::Init<0,1,2,3,5>(GPIOA, Gpio::Mode::input);
}

void Adc::StartCallibrationAdc (void) {
    ADC1->CR &= ~ADC_CR_ADVREGEN;
	ADC1->CR |= ADC_CR_ADVREGEN_0;		// Enable Vref
	ADC1->CR &= ~ADC_CR_ADCALDIF;

    ADC1->CR |= ADC_CR_ADCAL;           // Start calibration
    while (ADC1->CR & ADC_CR_ADCAL);    // Wait end calibration
}

void Adc::InitTimerEvent (void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;    
	TIM6->PSC = 36000-1;					
	TIM6->ARR = 1000;	
    TIM6->CR2 |= TIM_CR2_MMS_1;     // Enable generation TRGO for ADC		            
	TIM6->CR1  |= TIM_CR1_CEN;				
}