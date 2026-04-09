/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN1_Pin GPIO_PIN_13
#define BTN1_GPIO_Port GPIOC
#define BTN1_EXTI_IRQn EXTI13_IRQn
#define BTN2_Pin GPIO_PIN_14
#define BTN2_GPIO_Port GPIOC
#define BTN2_EXTI_IRQn EXTI14_IRQn
#define BTN3_Pin GPIO_PIN_15
#define BTN3_GPIO_Port GPIOC
#define BTN3_EXTI_IRQn EXTI15_IRQn
#define B_IN2_Pin GPIO_PIN_0
#define B_IN2_GPIO_Port GPIOC
#define B_IN1_Pin GPIO_PIN_1
#define B_IN1_GPIO_Port GPIOC
#define A_IN1_Pin GPIO_PIN_2
#define A_IN1_GPIO_Port GPIOC
#define A_IN2_Pin GPIO_PIN_3
#define A_IN2_GPIO_Port GPIOC
#define SPI2_CS_Pin GPIO_PIN_12
#define SPI2_CS_GPIO_Port GPIOB
#define XST_Pin GPIO_PIN_11
#define XST_GPIO_Port GPIOA
#define GPIO1_Pin GPIO_PIN_12
#define GPIO1_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_15
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_10
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_11
#define LED3_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
