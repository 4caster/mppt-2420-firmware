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

uint16_t resultVoltageInput = 0;
uint16_t resultCurrentInput = 0;
uint16_t resultCurrentOutput = 0;
uint16_t resultVoltageOutput = 0;

int main (void) {

    Periphery::Init();

    Hrpwm::SetDuty(18000);
    Adc::SetOutputDivider(Adc::Divider::div12V);

    while(1) {}

}

/********************************* END OF FILE **********************************/

void ADC1_2_IRQHandler (void) {

	ADC1->ISR |= ADC_ISR_JEOS;

    resultVoltageInput = ADC1->JDR1;
    resultCurrentInput = ADC1->JDR2;
    resultCurrentOutput = ADC1->JDR3;
    resultVoltageOutput = ADC1->JDR4;

    Led::Toggle(Led::Color::yellow);
}