/**
  @page CRC_Data_Reversing_16bit_CRC 16-bit CRC Computation With Data Reversal Options Enabled Example

  @verbatim
  ******************************************************************************
  * @file    CRC/CRC_Data_Reversing_16bit_CRC/readme.txt
  * @author  MCD Application Team
  * @brief   16-bit long CRC computation with data reversal options enabled.
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

How to configure the CRC using the HAL API. The CRC (cyclic
redundancy check) calculation unit computes a 16-bit CRC code derived from a
buffer of 32-bit data (words). Input and output data reversal features are
enabled. The user-defined generating polynomial is manually set to 0x1021,
that is, X^16 + X^12 + X^5 + 1 which is the CRC-CCITT generating polynomial.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32H735xx Devices :
The CPU at 520 MHz.
The HCLK for D1 Domain AXI and AHB3 peripherals, D2 Domain AHB1/AHB2 peripherals and D3 Domain AHB4 peripherals at 520 MHz/2.
The APB clock dividers for D1 Domain APB3 peripherals, D2 Domain APB1 and APB2 peripherals and D3 Domain APB4 peripherals to run at 520 MHz/4.

The CRC peripheral configuration is ensured by HAL_CRC_Init() function.
The latter is calling HAL_CRC_MspInit() function which core is implementing
the configuration of the needed CRC resources according to the used hardware (CLOCK).
You can update HAL_CRC_Init() input parameters to change the CRC configuration.

In this example, the user-defined generating polynomial is configured by
HAL_CRC_Init(). At the same time, input data reversal feature is set to bit
reversal on full word.
Output data reversal is enabled as well (only bit-level reversal option is available).
Additionally, the default init value is discarded and a user-defined one is used
instead.
It is specified finally that input data type is word.

The 16-bit long CRC is computed, stored in uwCRCValue variable then compared to the
CRC expected value stored in uwExpectedCRCValue_reversed variable.


For clarity's sake, a second CRC computation is then carried out with the input
and output data reversal options disabled, everything else being equal.

The input buffer used for this second CRC computation is derived from the
first input buffer by a bit-reversal operation carried out on full word (and vice versa).

It is checked that the same CRC is derived, taking into account that output data
reversal feature is disabled (i.e. the newly computed 16-bit CRC is equal to the
expected without reversal, whose value is stored in uwExpectedCRCValue variable).



STM32 board LEDs are used to monitor the example status:
  - LED2 (RED) is slowly blinking (1 sec. period) when an incorrect CRC value is calculated or in case of initialization error.
  - LED1 (GREEN) is ON when a correct CRC value is calculated.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
 to have correct HAL operation.
 
@Note If the  application is using the DTCM/ITCM memories (@0x20000000/ 0x0000000: not cacheable and only accessible
      by the Cortex M7 and the  MDMA), no need for cache maintenance when the Cortex M7 and the MDMA access these RAMs.
      If the application needs to use DMA(or other masters) based access or requires more RAM, then  the user has to:
              - Use a non TCM SRAM. (example : D1 AXI-SRAM @ 0x24000000)
              - Add a cache maintenance mechanism to ensure the cache coherence between CPU and other masters(DMAs,DMA2D,LTDC,MDMA).
              - The addresses and the size of cacheable buffers (shared between CPU and other masters)
                must be	properly defined to be aligned to L1-CACHE line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence.
      Depending on the use case it is also possible to configure the cache attributes using the MPU.
      Please refer to the AN4838 "Managing memory protection unit (MPU) in STM32 MCUs"
      Please refer to the AN4839 "Level 1 cache on STM32F7 Series"

@par Keywords

Security, CRC, CRC Polynomial, IEC 60870-5, hardware CRC, 16-bit 

@par Directory contents

  - CRC/CRC_Data_Reversing_16bit_CRC/Inc/stm32h7xx_hal_conf.h    HAL configuration file
  - CRC/CRC_Data_Reversing_16bit_CRC/Inc/stm32h7xx_it.h          Interrupt handlers header file
  - CRC/CRC_Data_Reversing_16bit_CRC/Inc/main.h                  Header for main.c module
  - CRC/CRC_Data_Reversing_16bit_CRC/Src/stm32h7xx_it.c          Interrupt handlers
  - CRC/CRC_Data_Reversing_16bit_CRC/Src/main.c                  Main program
  - CRC/CRC_Data_Reversing_16bit_CRC/Src/stm32h7xx_hal_msp.c     HAL MSP module
  - CRC/CRC_Data_Reversing_16bit_CRC/Src/system_stm32h7xx.c      STM32H7xx system source file


@par Hardware and Software environment

  - This example runs on STM32H735xx devices.
  - This example has been tested with STM32H735G-DK board and can be
    easily tailored to any other supported device and development board.

@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

