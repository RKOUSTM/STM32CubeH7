/**
  ******************************************************************************
  * @file    SD/SD_ReadWrite_IT/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
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
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "stm32h735g_discovery.h"
#include "stdio.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Size of buffers */
#define BUFFERSIZE                 (COUNTOF(aTxBuffer) - 1)
/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)        (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

/* Definition for SDMMC clock resources */
#define SDMMC_D0_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOC_CLK_ENABLE()        
#define SDMMC_D1_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOC_CLK_ENABLE()
#define SDMMC_D2_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOC_CLK_ENABLE()
#define SDMMC_D3_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOC_CLK_ENABLE()
#define SDMMC_CK_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOC_CLK_ENABLE()
#define SDMMC_CMD_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define SDMMC_D0_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOC_CLK_DISABLE()        
#define SDMMC_D1_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOC_CLK_DISABLE()
#define SDMMC_D2_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOC_CLK_DISABLE()
#define SDMMC_D3_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOC_CLK_DISABLE()
#define SDMMC_CK_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOC_CLK_DISABLE()
#define SDMMC_CMD_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOD_CLK_DISABLE()

/* Definition for SDMMC Pins */
#define SDMMC_D0_PIN               GPIO_PIN_8
#define SDMMC_D0_GPIO_PORT         GPIOC
#define SDMMC_D1_PIN               GPIO_PIN_9
#define SDMMC_D1_GPIO_PORT         GPIOC
#define SDMMC_D2_PIN               GPIO_PIN_10
#define SDMMC_D2_GPIO_PORT         GPIOC
#define SDMMC_D3_PIN               GPIO_PIN_11
#define SDMMC_D3_GPIO_PORT         GPIOC
#define SDMMC_CK_PIN               GPIO_PIN_12
#define SDMMC_CK_GPIO_PORT         GPIOC
#define SDMMC_CMD_PIN              GPIO_PIN_2
#define SDMMC_CMD_GPIO_PORT        GPIOD

/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */
#define USARTx                           USART3
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_8
#define USARTx_TX_GPIO_PORT              GPIOD
#define USARTx_TX_AF                     GPIO_AF7_USART3
#define USARTx_RX_PIN                    GPIO_PIN_9
#define USARTx_RX_GPIO_PORT              GPIOD
#define USARTx_RX_AF                     GPIO_AF7_USART3
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
