/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Adc.h                                                            *
 * author      Ila Galkin                                                       *
 * date        20.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       ADC converter                                                    *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"
#include "Gpio.h"

/********************************************************************************
 * Class ADC
 * 
 * Divider input voltage: 100 kOhm / 5.1 kOhm = 19.6078
 * Divider output voltage to 12V: 100 kOhm / 24 kOhm = 4.1667
 * Divider output voltage to 24V: 100 kOhm / 12 kOhm = 8.3333
 * 
 * Pin control divider - PB14
 * 
 * Pin voltage input    - PA0   - ADC1 IN1
 * Pin current input    - PA1   - ADC1 IN2
 * Pin current output   - PA2   - ADC1 IN3
 * Pin voltage output   - PA3   - ADC1 IN4
 * Pin temperature      - PA5   - ADC2 IN2
 * 
 ********************************************************************************/

class Adc {

    public:
        enum class Divider {
            div12V, div24V
        };

    public:
        static void SetOutputDivider (Divider divider) {
            if (divider == Divider::div12V) { GPIOB->BSRR |= GPIO_BSRR_BR_14; }
            if (divider == Divider::div24V) { GPIOB->BSRR |= GPIO_BSRR_BS_14; }
        }

        static void Init () {
            RCC->AHBENR |= RCC_AHBENR_ADC12EN;     

            Adc::GpioInit();
            Adc::InitTimerEvent();
            Adc::StartCallibrationAdc();

            ADC1->JSQR |= 0x10308167;               // Lenght = 4, Trigger = event 9, Type trigger = rising edge, Channel = IN1, IN2, IN3 and IN4

            ADC1->IER |= ADC_IER_JEOSIE;            // Interrupt enable
            NVIC_EnableIRQ(ADC1_2_IRQn);            // Enable interrupt ADC1 and ADC2

            ADC1->CR |= ADC_CR_ADEN;                // Enable ADC1
            while(!(ADC1->ISR & ADC_ISR_ADRDY));    // Wait ready ADC1

            ADC1->CR |= ADC_CR_JADSTART;            // Enable injector conversion       
        }

    private:
        const float voltageDivInput = 19.6078f;
        const float voltageDivOutput12V = 4.1667f;
        const float voltageDivOutput24V = 8.3333f;

    private:    
        static void GpioInit() {
            Gpio::Init<14>(GPIOB, Gpio::Mode::output, Gpio::Type::PP);
            Gpio::Init<0,1,2,3,5>(GPIOA, Gpio::Mode::input);
        }

        static void StartCallibrationAdc() {
            ADC1->CR &= ~ADC_CR_ADVREGEN;
	        ADC1->CR |= ADC_CR_ADVREGEN_0;		// Enable Vref
	        ADC1->CR &= ~ADC_CR_ADCALDIF;

            ADC1->CR |= ADC_CR_ADCAL;           // Start calibration
            while (ADC1->CR & ADC_CR_ADCAL);    // Wait end calibration
        }

        static void InitTimerEvent (void) {
            RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;    

	        TIM6->PSC = 36000-1;					
	        TIM6->ARR = 1000;			            

	        TIM6->DIER |= TIM_DIER_UIE;			// Enable interrupt
	        TIM6->CR1  |= TIM_CR1_CEN;			// Enable counter

	        NVIC_EnableIRQ(TIM6_DAC1_IRQn);		
        }
};

/********************************* END OF FILE **********************************/