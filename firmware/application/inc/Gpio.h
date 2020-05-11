/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        Gpio.h                                                           *
 * author      Ila Galkin                                                       *
 * date        11.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       class Gpio                                                       *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"

/********************************************************************************
 * Class Gpio
 ********************************************************************************/

class Gpio {

    public:
        enum class mode:int {
	        analog = 0b11, input = 0b00, output = 0b01, outputAF = 0b10
        };

        enum class type:int {
	        PP = 0, OD = 1
        };
        
        enum class speed:int {
	        low = 0, medium = 0b01, high = 0b10, veryHigh = 0b11
        };

        enum class pupd:int {
	        noPull = 0, pullUp = 0b01, pullDown = 0b10
        };

        enum class af:int {
	        af0 = 0, af1, af2, af3, af4, af5, af6, af7, af8, af9, af10, af11, af12, af13, af14, af15
        };
        
        enum class pins:int {
	        pin0 = 0, pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15
        };

    public:
        template<uint8_t ... pins>
        static inline void Init (GPIO_TypeDef * port = GPIOA, mode m = mode::input, type t = type::PP, speed s = speed::low, pupd p = pupd::noPull, af a = af::af0) {

	        if (port == GPIOA)
		        RCC->AHBENR  |= RCC_AHBENR_GPIOAEN;
	        if (port == GPIOB)
		        RCC->AHBENR  |= RCC_AHBENR_GPIOBEN;
	        if (port == GPIOC)
		        RCC->AHBENR  |= RCC_AHBENR_GPIOCEN;
	        if (port == GPIOD)
		        RCC->AHBENR  |= RCC_AHBENR_GPIODEN;
	        if (port == GPIOF)
		        RCC->AHBENR  |= RCC_AHBENR_GPIOFEN;


	        uint32_t temp1 = 0, temp2 = 0;
	        ((temp1 |= (0b11 << (2*pins))), ... );
	        port->MODER &= ~(temp1);
	        temp1 = 0;
	        ((temp1 |= int(m) << (2*pins)), ... );
	        port->MODER |= temp1;

	        temp1 = 0;
	        ((temp1 |= (0b1 << (pins))), ... );
	        port->OTYPER &= ~(temp1);
	        temp1 = 0;
	        ((temp1 |= (int(t) << (pins))), ... );
	        port->OTYPER |= temp1;

	        temp1 = 0;
	        ((temp1|=(0b11 << (2*pins))), ... );
	        port->OSPEEDR &= ~(temp1);
	        temp1 = 0;
	        ((temp1 |= (int(s) << (2*pins))), ... );
	        port->OSPEEDR |= temp1;

	        temp1 = 0;
	        ((temp1 |= (0b11 << (2*pins))), ... );
	        port->PUPDR &= ~(temp1);
	        temp1 = 0;
	        ((temp1 |= (int(p) << (2*pins))), ... );
	        port->PUPDR |= temp1;

	        temp1 = 0;
	        (((pins < 8?temp1:temp2) |= (0b11 << (4*(pins-(pins<8?0:8))))), ... );
	        port->AFR[0] &= ~temp1;
	        port->AFR[1] &= ~temp2;

	        temp1 = 0;
	        temp2 = 0;
	        (((pins < 8?temp1:temp2) |= (int(a) << (4*(pins-(pins<8?0:8))))), ... );
	        port->AFR[0] |= temp1;
	        port->AFR[1] |= temp2;

        }

        template<uint32_t ... pins>
        static inline void Set (GPIO_TypeDef* port) {
	        uint32_t t = 0;
	        ((t |= 1<<pins), ...);
	        port->BSRR = t;
        }

        template<uint32_t ... pins>
        static inline void Toggle (GPIO_TypeDef* port) {
	        uint32_t t = 0;
	        ((t |= 1<<pins), ...);
	        port->ODR ^= t;
        }

        template<uint32_t ... pins>
        static inline void Reset (GPIO_TypeDef* port) {
	        uint32_t t = 0;
	        ((t |= 1<<(pins+16)), ...);
	        port->BSRR = t;
        }

    private:

};