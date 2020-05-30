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

    Clock::Init();
    Led::Init();

    Hrpwm::InitHrpwm (45000);
    Hrpwm::SetDuty (18000);

    Adc::SetOutputDivider(Adc::Divider::div12V);
    Adc::Init();

    Led::On(Led::Color::yellow);

    while(1) {}

}

/********************************* END OF FILE **********************************/

void ADC1_2_IRQHandler (void) {

	ADC1->ISR |= ADC_ISR_JEOS;
    Led::Toggle(Led::Color::yellow);
}

/*
void TIM6_DAC1_IRQHandler (void) {

	TIM6->SR &= ~TIM_SR_UIF;
    Led::Toggle(Led::Color::yellow);
}
*/