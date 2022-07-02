/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <string.h>
#include "timers.h"
#include<stdio.h>
/* USER CODE END Includes */
extern UART_HandleTypeDef huart2;
extern I2C_HandleTypeDef hi2c1;
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct
{
	uint8_t payload[10]; /* stores data bytes of the command */
	uint32_t len ; /* command lenght */
}command_t;


/* application states */
typedef enum
{
	sMainMenu = 0 ,
	sLedEffect,
	sRtcMenu,
	sRtcTimeConfig,
	sRtcDateConfig,
	sRtcReport,
}state_t;

typedef struct
{
	uint8_t  seconds ;
	uint8_t minutes ;
	uint8_t hour ;
	uint8_t dayofweek ;
	uint8_t dayofmonth ;
	uint8_t month ;
	uint8_t year ;
}RTC_TIME;


/* USER CODE END ET */
#define LED1 GPIO_PIN_12
#define LED2 GPIO_PIN_11
#define LED3 GPIO_PIN_10
#define LED4 GPIO_PIN_2

#define DS3231_ADDRESS 0xd0
/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
//  Software timer handles.
extern TimerHandle_t  handle_led_timer[4];

extern TaskHandle_t  handle_menu_task ;
extern TaskHandle_t  hanlde_cmd_task  ;
extern TaskHandle_t handle_printf_task ;
extern TaskHandle_t handle_led_task ;
extern TaskHandle_t handle_rtc_task ;

extern QueueHandle_t q_data ;
extern QueueHandle_t q_printf ;

extern state_t curr_state ;


void menu_task ( void *param) ;
void cmd_hanlder_task ( void *param) ;
void printf_task ( void *param) ;
void led_task ( void *param) ;
void rtc_task ( void *param);

void led_effect_stop (void) ;
void led_effect ( int n) ;

void led_effect1(void);
void led_effect2(void);
void led_effect3(void);
void led_effect4(void);


uint8_t RTC_decToBcd(int val);
int RTC_bcdToDec(uint8_t val) ;
void RTC_Set_Time (RTC_TIME *time) ;
void RTC_Get_Time (RTC_TIME *time) ;
void show_time_date(RTC_TIME *time) ;
int validate_rtc_information (RTC_TIME *time) ;
void initTimer(void);
void led_effect_callback (TimerHandle_t xTimer);

/* USER CODE END EFP */
void Error_Handler(void);
/* Private defines -----------------------------------------------------------*/
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
