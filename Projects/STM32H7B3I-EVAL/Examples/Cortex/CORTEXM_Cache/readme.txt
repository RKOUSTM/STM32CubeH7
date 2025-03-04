/**
  @page CORTEXM_Cache Cortex-M7 Cache example

  @verbatim
  ******************** (C) COPYRIGHT 2018 STMicroelectronics *******************
  * @file    Cortex/CORTEXM_Cache/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the CORTEXM_Cache example.
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

This example provides a description of how to do Data-Cache maintenance on a shared memory buffer accessed by 2 masters (CPU and DMA).
This projects is configured for STM32H7B3xxQ devices using STM32CubeH7 HAL and running on
STM32H7B3I-EVAL board from STMicroelectronics.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32H7B3xxQ Devices :
The CPU at 280MHz
The HCLK for CD Domain AXI and AHB3 peripherals, CD Domain AHB1/AHB2 peripherals and SRD Domain AHB4 peripherals at 280MHz.
The APB clock dividers for CD Domain APB3 peripherals, CD Domain APB1 and APB2 peripherals and SRD Domain APB4 peripherals to run at 140MHz.

This example includes three MPU configurations of AXI-SRAM, and only one configuration
should be chosen in main.h:
- MPU_WRITE_THROUGH
- MPU_WRITE_BACK_WRITE_ALLOCATE
- MPU_WRITE_BACK_NO_WRITE_ALLOCATE

In this examples, two DMA transfers are configured using DMA1_Stream0:
1/ First Transfer:
   - From Flash to AXI-SRAM
   - Destination buffer is put in D-cache, before starting the transfer
2/ Second Transfer:
   - From AXI SRAM to SRD-SRAM (non-cacheable)
   - Source buffer modified by CPU in D-cache, before starting the transfer

Then, these 2 DMA transfers are started, then source and destination buffers are compared.
Leds colors will indicate the buffer comparison results.
In the first step, only one or two transfer comparison results could be wrong, depending
on the chosen MPU configuration.
Then, User has to press on Tamper button to do a Cache maintenance, in order to
ensure the cache coherency between CPU and DMA.
Thereafter, a new buffer comparison is done to indicate transfer status after Cache maintenance,
and leds colors should indicate the correct comparison status for the 2 transfers.

STM32H7B3I-EVAL board's LEDs can be used to monitor the transfer status:
 - Green LED is ON when the first transfer is completed and buffers comparison is correct.
 - Red LED is ON when transfer 1 buffers comparison is wrong.
 - Yellow LED is ON when transfer 2 buffers comparison is wrong.
 - Orange LED is ON when the second transfer is completed and buffers comparison is OK.

Cache Maintenance:
    - It is recommended to enable the cache and maintain its coherence, but depending
      on the use case, it is also possible to configure the MPU as "Write through",
      to guarantee the write access coherence.�In that case, the MPU must be configured
      as Cacheable/Not bufferable/Not Shareable.�Even though the user must manage
      the cache coherence for read accesses.
������Please refer to the AN4838 �Managing memory protection unit (MPU) in STM32 MCUs�
������Please refer to the AN4839 �Level 1 cache on STM32F7 Series and STM32H7 Series�.

    - The addresses of cacheable buffers (shared between CPU and other masters)
      should be properly�defined to be aligned to D-Cache line size (32 bytes).
      This can achieved by using a specific macro "ALIGN_32BYTES" when declaring buffers.
      Consequently, User can use Cache maintenance pre-defined APIs which are based on address:
      SCB_InvalidateDCache_by_Addr, SCB_CleanDCache_by_Addr and SCB_CleanInvalidateDCache_by_Addr.

    - Caution: When using SCB_InvalidateDCache_by_Addr API with a Write-Back MPU configuration,
      the buffer length should also be aligned to D-Cache line size (32 bytes).
      Moreover, a padding of 8 words (1 cache line) may be needed at the beginning
      and at the end of the buffer, especilally when accesses to the shared buffer
      content is not linear.

    - When User can�t ensure the Buffer Length Alignment, there are two possible solutions:
        * Use the SCB_CleanInvalidateDCache_by_Addr() instead of SCB_InvalidateDCache_by_Addr()
        * Use a Write-Through MPU configuration, so there is no need to make a Cache clean

    - Be careful before using the Invalidate all data cache in Write-Back policy:
        * Risk to lose all the modification which are not yet evicted
        * Use always Cache Clean before the Cache Invalidate.

    - Clean all Data-Cache shall not cause a coherency problem but will impact performance,
      since it will fetch all dirty lines in the D-cache and evicted even the non-shareable data.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@note Please refer to the SDEN-1068427 �Cortex-M7 (AT610) and Cortex-M7 with FPU (AT611) Software Developer Errata Notice"
      issued on 28-Nov-2018 (version 8.0) by ARM (erratum #1259864).

@par Keywords

System, Cortex, Memory regions, Cache, MPU, Write-Through, write-back, write-allocate, WBWA, Cache policy, CPU, DMA

@par Directory contents

  - CortexM/CORTEXM_Cache/Src/main.c                  Main program
  - CortexM/CORTEXM_Cache/Src/system_stm32h7xx.c      STM32H7xx system clock configuration file
  - CortexM/CORTEXM_Cache/Src/stm32h7xx_it.c          Interrupt handlers
  - CortexM/CORTEXM_Cache/Src/stm32_mpu.c             MPU configurations

  - CortexM/CORTEXM_Cache/Inc/main.h                  Main program header file
  - CortexM/CORTEXM_Cache/Inc/stm32h7b3i_eval_conf.h  STM32H7B3I_EVAL board configuration file.
  - CortexM/CORTEXM_Cache/Inc/stm32h7xx_hal_conf.h    HAL Configuration file
  - CortexM/CORTEXM_Cache/Inc/stm32h7xx_it.h          Interrupt handlers header file
  - CortexM/CORTEXM_Cache/Inc/stm32_mpu.h             MPU configurations


@par Hardware and Software environment

  - This example runs on STM32H7B3xxQ devices.

  - This example has been tested with STMicroelectronics STM32H7B3I-EVAL
    boards and can be easily tailored to any other supported device
    and development board.


@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
