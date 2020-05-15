/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Hrpwm.cpp                                                        *
 * author      Ila Galkin                                                       *
 * date        13.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       High resolution PWM                                              *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Hrpwm.h"

/********************************************************************************
 * Class HRPWM
 ********************************************************************************/

void Hrpwm::InitGpio (Channel channel) {

    switch (channel) {
        
        case (Hrpwm::Channel::channelA):
            Gpio::Init<8,9>(GPIOA, Gpio::Mode::outputAF, Gpio::Type::PP, Gpio::Speed::veryHigh, Gpio::Pupd::pullDown, Gpio::AF::af13);
            break;

        case (Hrpwm::Channel::channelB):
            Gpio::Init<10,11>(GPIOA, Gpio::Mode::outputAF, Gpio::Type::PP, Gpio::Speed::veryHigh, Gpio::Pupd::pullDown, Gpio::AF::af13);
            break;

        case (Hrpwm::Channel::channelC):
            Gpio::Init<12,13>(GPIOB, Gpio::Mode::outputAF, Gpio::Type::PP, Gpio::Speed::veryHigh, Gpio::Pupd::pullDown, Gpio::AF::af13);
            break;

        case (Hrpwm::Channel::channelD):
            Gpio::Init<14,15>(GPIOB, Gpio::Mode::outputAF, Gpio::Type::PP, Gpio::Speed::veryHigh, Gpio::Pupd::pullDown, Gpio::AF::af13);
            break;
    
        default:
            break;
    }
}

void Hrpwm::SelectEventForExternalGeneration (uint16_t compare) {
    
    HRTIM1->sTimerxRegs[1].CMP2xR = compare / 10;       // Samples in 10% of period PWM
    HRTIM1->sCommonRegs.CR1 |= HRTIM_CR1_ADC2USRC_1;    // ADC trigger 2 update: Timer B 
    HRTIM1->sCommonRegs.ADC2R |= HRTIM_ADC2R_AD2TBC2;   // ADC trigger 2 event: Timer B compare 2 
}

void Hrpwm::InitHrpwm (Channel channel, uint16_t period) {

    uint16_t numerChannel = static_cast<uint16_t>(channel);
    Hrpwm::InitGpio (channel);

    RCC->CFGR3   |= RCC_CFGR3_HRTIM1SW_PLL;     // Enable multiplier x2 for PLL frequency
    RCC->APB2ENR |= RCC_APB2ENR_HRTIM1EN;       // Enable clock for HRPWM

    HRTIM1->sCommonRegs.DLLCR |= HRTIM_DLLCR_CAL | HRTIM_DLLCR_CALEN;   // Start timer's calibration 
    while ((HRTIM1->sCommonRegs.ISR & HRTIM_ISR_DLLRDY) == RESET);      // Waiting for the end fo calibration 

    HRTIM1->sTimerxRegs[numerChannel].PERxR = period;  // Set period for timer B
    HRTIM1->sTimerxRegs[numerChannel].CMP1xR = 0;              // Set starting duty for timer B

    HRTIM1->sTimerxRegs[numerChannel].OUTxR |= HRTIM_OUTR_DTEN;                                        // Enable dead-time
    HRTIM1->sTimerxRegs[numerChannel].DTxR  |= (3 << HRTIM_DTR_DTPRSC_Pos);                            // Set Tdtg = (2^3) * 868 ps = 6.94 ns
    HRTIM1->sTimerxRegs[numerChannel].DTxR  |= (15 << HRTIM_DTR_DTR_Pos) | (15 << HRTIM_DTR_DTF_Pos);  // Set dead-time rising and falling = 15 * Ttg = 104 ns 	
    HRTIM1->sTimerxRegs[numerChannel].DTxR  |= HRTIM_DTR_DTFSLK | HRTIM_DTR_DTRSLK;                    // Lock value dead-time

    Hrpwm::SelectEventForExternalGeneration (period);

    HRTIM1->sTimerxRegs[numerChannel].SETx1R |= HRTIM_SET1R_PER;	                // Event forces the output to active state for TB1
    HRTIM1->sTimerxRegs[numerChannel].RSTx1R |= HRTIM_RST1R_CMP1;                  // Event forces the output to inactive state for TB1

    HRTIM1->sCommonRegs.OENR |= HRTIM_OENR_TA1OEN | HRTIM_OENR_TA2OEN;  // Enable output PWM for TB1 and TB2
    HRTIM1->sTimerxRegs[numerChannel].TIMxCR |= HRTIM_TIMCR_CONT;                  // Continuous mode

    HRTIM1->sMasterRegs.MPER = period;                       // Period for master timer
    HRTIM1->sMasterRegs.MCR |= HRTIM_MCR_MCEN | HRTIM_MCR_TACEN;        // Enable counter for Master and timer B
}

void Hrpwm::SetDuty (Channel channel, uint16_t duty) {

    uint16_t numerChannel = static_cast<uint16_t>(channel);
    HRTIM1->sTimerxRegs[numerChannel].CMP1xR = duty;
}

/********************************* END OF FILE **********************************/