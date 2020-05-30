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
        static void Init (void);
        static void SetDuty (uint16_t duty);

    private:
        static void InitGpio (void);

    private:
        static const uint16_t periodHrpwm = 45000;     // Fsw = 100 kHz
};

/********************************* END OF FILE **********************************/