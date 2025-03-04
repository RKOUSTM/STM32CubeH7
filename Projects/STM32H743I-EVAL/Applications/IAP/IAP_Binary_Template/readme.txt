/**
  @page IAP_Binary_Template AN4657 IAP Binary Template Readme file
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    IAP/IAP_Binary_Template/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the IAP_Binary_Template directory.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  @endverbatim

@par Application Description

 This directory contains a set of sources files that build the application to be
 loaded into Flash memory using In-Application Programming (IAP) through USART.

 At the beginning of the main program the HAL_Init() function is called to reset 
 all the peripherals, initialize the Flash interface and the systick.
 The SystemClock_Config() function is used to configure the system clock for STM32H743xx Devices :
 The CPU at 400MHz 
 The HCLK for D1 Domain AXI and AHB3 peripherals , D2 Domain AHB1/AHB2 peripherals and D3 Domain AHB4  peripherals at 200MHz.
 The APB clock dividers for D1 Domain APB3 peripherals, D2 Domain APB1 and APB2 peripherals and D3 Domain APB4 peripherals to  run at 100MHz.  

 Applicaion start toggling LED1 and LED3 alternatively with LED2 and LED4.
 
 To build such application, some special configuration has to be performed:
 1. Set the program load address at 0x08020000, using your toolchain linker file
 2. Relocate the vector table at address 0x08020000, using the "NVIC_SetVectorTable"
    function.
 
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
              - Use a non TCM SRAM. (example : D1 AXI-SRAM @ 0x24000000)
              - Add a cache maintenance mechanism to ensure the cache coherence between CPU and other masters(DMAs,DMA2D,LTDC,MDMA).
              - The addresses and the size of cacheable buffers (shared between CPU and other masters)
                must be	properly defined to be aligned to L1-CACHE line size (32 bytes). 
 
@Note It is recommended to enable the cache and maintain its coherence.
      Depending on the use case it is also possible to configure the cache attributes using the MPU.
      Please refer to the AN4838 "Managing memory protection unit (MPU) in STM32 MCUs"
      Please refer to the AN4839 "Level 1 cache on STM32F7 Series"

@par Keywords

In-Application Programming, Template, IAP, Flash, USART

@par Directory contents 

 - IAP/IAP_Binary_Template/Inc/stm32h7xx_hal_conf.h  Library Configuration file
 - IAP/IAP_Binary_Template/Inc/stm32h7xx_it.h        Header for stm32h7xx_it.c
 - IAP/IAP_Binary_Template/Inc/main.h                Header for main.c
 - IAP/IAP_Binary_Template/Src/main.c                Main program
 - IAP/IAP_Binary_Template/Src/stm32h7xx_it.c        Interrupt handlers
 - IAP/IAP_Binary_Template/Src/system_stm32h7xx.c    STM32H7xx system source file
 - IAP/IAP_Binary_Template/Utilities:                Axf (Keil) conversion script to BIN format.

@par Hardware and Software environment

  - This application runs on STM32H7xx Devices.
  
  - This application has been tested with STMicroelectronics STM32H743I-EVAL evaluation board
    and can be easily tailored to any other supported device and development board.

@par How to use it ?  

In order to load the SysTick application with the IAP, you must do the following:

 - Open your preferred toolchain 
 - Rebuild all projects files
 - A binary file "STM32H743I-EVAL_SysTick.bin" will be generated in build output folder.  
   - For Keil an extract conversion step is required using "axftobin.bat"
 - Finally load this image with IAP application

 * <h2><center>&copy; COPYRIGHT 2017 STMicroelectronics</center></h2>
 */
