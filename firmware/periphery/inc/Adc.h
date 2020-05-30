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
        static void SetOutputDivider (Divider divider);

        static void Init (void);

    private:
        const float voltageDivInput = 19.6078f;
        const float voltageDivOutput12V = 4.1667f;
        const float voltageDivOutput24V = 8.3333f;

    private:    
        static void GpioInit (void);
        static void StartCallibrationAdc (void);
        static void InitTimerEvent (void);
};

/********************************* END OF FILE **********************************/