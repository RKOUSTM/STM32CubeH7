﻿/**
  @page GFXMMU_DisplayCircularShape GFXMMU Display Circular Shape example

  @verbatim
  ******************** (C) COPYRIGHT 2018 STMicroelectronics *******************
  * @file    GFXMMU/GFXMMU_DisplayCircularShape/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the GFXMMU_DisplayCircularShape example.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

This example describe how to enable and use the GFXMMU functionality to display an image with circular shape.


At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32H7B3xxQ  Devices :
The CPU at 280MHz
The HCLK for CD Domain AXI and AHB3 peripherals, CD Domain AHB1/AHB2 peripherals and SRD Domain AHB4  peripherals at 280MHz.
The APB clock dividers for CD Domain APB3 peripherals, CD Domain APB1 and APB2 peripherals and SRD Domain APB4 peripherals to run at 140MHz.


 After LCD initialization,GFXMMU initialization and configuration, an image presenting ST Logo with round form
 of size 480x480 in ARGB8888 format is displayed on LCD.

@Note The GFXMMU shape is based on a Lookup Table witch gives a shape with escalator effect on curved limits.

STM32H7B3I Eval board's LED can be used to monitor the transfer status:
 - LED1 toggles in a forever loop when there is an error in Init process.

@note Some code parts can be executed in the ITCM-RAM (64 KB) which decrease critical task execution time, compared
      to code execution from Flash memory. This feature can be activated using '#pragma location = ".itcmram"' to be
      placed above function declaration, or using the toolchain GUI (file options) to execute a whole source file in
      the ITCM-RAM.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@Note If the  application is using the DTCM/ITCM memories (@0x20000000/ 0x0000000: not cacheable and only accessible
      by the Cortex M7 and the  MDMA), no need for cache maintenance when the Cortex M7 and the MDMA access these RAMs.
      If the application needs to use DMA(or other masters) based access or requires more RAM, then  the user has to:
              - Use a non TCM SRAM. (example : CD AXI-SRAM @ 0x24000000)
              - Add a cache maintenance mechanism to ensure the cache coherence between CPU and other masters(DMAs, DMA2D, LTDC, MDMA).
              - The addresses and the size of cacheable buffers (shared between CPU and other masters)
                must be properly defined to be aligned to L1-CACHE line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence.
              Please refer to the AN4838 "Managing memory protection unit (MPU) in STM32 MCUs"
              Please refer to the AN4839 "Level 1 cache on STM32F7 Series and STM32H7 Series"

@par Keywords

Graphics, GFXMMU, Display, Image, LCD, Circular shape, ARGB8888, Escalator effect


@par Directory contents

  - GFXMMU/GFXMMU_DisplayCircularShape/Src/main.c                 Main program
  - GFXMMU/GFXMMU_DisplayCircularShape/Src/system_stm32h7xx.c     STM32H7xx system clock configuration file
  - GFXMMU/GFXMMU_DisplayCircularShape/Src/stm32h7xx_it.c         Interrupt handlers
  - GFXMMU/GFXMMU_DisplayCircularShape/Src/stm32h7xx_hal_msp.c    HAL MSP module
  - GFXMMU/GFXMMU_DisplayCircularShape/Inc/main.h                 Main program header file
  - GFXMMU/GFXMMU_DisplayCircularShape/Inc/stm32h7xx_hal_conf.h   HAL Configuration file
  - GFXMMU/GFXMMU_DisplayCircularShape/Inc/stm32h7xx_it.h         Interrupt handlers header file
  - GFXMMU/GFXMMU_DisplayCircularShape/Inc/stm32h7b3i_eval_conf.h STM32H7B3I_EVAL board configuration file
  - GFXMMU/GFXMMU_DisplayCircularShape/Inc/ARGB_8888_480.h        Image of size 480x480 and format ARGB8888 to be displayed on LCD
@par Hardware and Software environment

  - This example runs on STM32H7B3xxQ devices.
  - This example has been tested with STMicroelectronics STM32H7B3I-EVAL
    board and can be easily tailored to any other supported device
    and development board.


@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example



 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
