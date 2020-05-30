/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Hrpwm.h                                                          *
 * author      Ila Galkin                                                       *
 * date        13.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       High resolution PWM                                              *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"
#include "Gpio.h"

/********************************************************************************
 * Class HRPWM
 * 
 * Dead time - 104 ns
 * Complementary output
 * Channel A
 * 
 ********************************************************************************/

class Hrpwm {

    public:
        static void Init (uint16_t period);
        static void SetDuty (uint16_t duty);

    private:
        static void InitGpio (void);
};

/********************************* END OF FILE **********************************/