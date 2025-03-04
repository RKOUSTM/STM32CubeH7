/**
  @page TIM_PWMOutput TIM example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/TIM/TIM_PWMOutput/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM_PWMOutput example.
  ******************************************************************************
  *
  * Copyright (c) 2019 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

Use of a timer peripheral to generate a 
PWM output signal and update the PWM duty cycle. This example is based on the 
STM32H7xx TIM LL API. The peripheral initialization uses 
LL unitary service functions for optimization purposes (performance and size).

At the beginning of the main program the SystemClock_Config() function is called to configure the system clock for STM32H7A3xxQ Devices :
The CPU at 280 MHz.
The HCLK for CD Domain AXI and AHB3 peripherals, CD Domain AHB1/AHB2 peripherals and SRD Domain AHB4 peripherals at 280 MHz.
The APB clock dividers for CD Domain APB3 peripherals, CD Domain APB1 and APB2 peripherals and SRD Domain APB4 peripherals to run at 280 MHz/2.

In this example TIM3 input clock (TIM3CLK) frequency is set to APB1 clock (PCLK1),
since APB1 pre-scaler is equal to 2 and it is twice PCLK1.
    TIM3CLK = 2*PCLK1
    PCLK1 = HCLK/2
    => TIM3CLK = (2/2)*HCLK = SystemCoreClock (280 Mhz)

To set the TIM3 counter clock frequency to 10 KHz, the pre-scaler (PSC) is
calculated as follows:
PSC = (TIM3CLK / TIM3 counter clock) - 1
PSC = (SystemCoreClock /10 KHz) - 1

SystemCoreClock is set to 280 MHz for STM32H7xx Devices.

Auto-reload (ARR) is calculated to get a time base period of 10 ms,
meaning a time base frequency of 100 Hz.
ARR = (TIM3 counter clock / time base frequency) - 1
ARR = (TIM3 counter clock / 100) - 1

Initially, the capture/compare register (CCR3) of the output channel is set to
half the auto-reload value meaning a initial duty cycle of 50%.
Generally speaking this duty cycle is calculated as follows:
Duty cycle = (CCR3 / ARR) * 100

The timer output channel is mapped on the pin PB.00 (connected to LED1 on board
NUCLEO-H7A3ZI-Q).
Thus LED1 status (on/off) mirrors the timer output level (active v.s. inactive).

User push-button can be used to change the duty cycle from 0% up to 100% by
steps of 10%. Duty cycle is periodically measured. It can be observed through
the debugger by watching the variable uwMeasuredDutyCycle.

Initially the output channel is configured in output compare toggle mode.
@note The LED1 is not toggling. In fact, if the dutycycle is 0% so the LED1 is OFF. When pushing 
successively the user button, the LED1 is ON and its luminosity rises as the dutycycle value keeps 
increasing.

@Note If the  application is using the DTCM/ITCM memories (@0x20000000/0x0000000: not cacheable and only accessible
      by the Cortex M7 and the MDMA), no need for cache maintenance when the Cortex M7 and the MDMA access these RAMs.
      If the application needs to use DMA(or other masters) based access or requires more RAM, then the user has to:
              - Use a non TCM SRAM. (example : CD AXI-SRAM @ 0x24000000)
              - Add a cache maintenance mechanism to ensure the cache coherence between CPU and other masters (DMAs, DMA2D, LTDC, MDMA).
              - The addresses and the size of cacheable buffers (shared between CPU and other masters)
                must be properly defined to be aligned to L1-CACHE line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence.
              Please refer to the AN4838 "Managing memory protection unit (MPU) in STM32 MCUs"
              Please refer to the AN4839 "Level 1 cache on STM32F7 Series and STM32H7 Series"

@par Keywords

Timers, PWM, Frequency, Duty Cycle, Waveform, Oscilloscope, Output, Signal

@par Directory contents 

  - TIM/TIM_PWMOutput/Inc/stm32h7xx_it.h          Interrupt handlers header file
  - TIM/TIM_PWMOutput/Inc/main.h                  Header for main.c module
  - TIM/TIM_PWMOutput/Inc/stm32_assert.h          Template file to include assert_failed function
  - TIM/TIM_PWMOutput/Src/stm32h7xx_it.c          Interrupt handlers
  - TIM/TIM_PWMOutput/Src/main.c                  Main program
  - TIM/TIM_PWMOutput/Src/system_stm32h7xx.c      STM32H7xx system source file


@par Hardware and Software environment

  - This example runs on STM32H7A3xxQ devices.
    
  - This example has been tested with NUCLEO-H7A3ZI-Q board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
