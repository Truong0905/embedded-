/*
 * led_effect.c
 *
 *  Created on: May 31, 2022
 *      Author: Truong
 */

#include "main.h"


void led_effect_stop (void)
{
	HAL_GPIO_WritePin(GPIOC, LED1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, LED4, GPIO_PIN_RESET);
	for ( int i = 0  ; i< 4 ; i++)
	{
		xTimerStop(handle_led_timer[i], portMAX_DELAY);

	}
}

void led_effect ( int n)
{
	led_effect_stop();
	xTimerStart (handle_led_timer[n-1], portMAX_DELAY);
}

void turn_off_all_leds (void)
{
	HAL_GPIO_WritePin(GPIOC, LED1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, LED4, GPIO_PIN_RESET);

}


void turn_on_all_leds (void)
{
	HAL_GPIO_WritePin(GPIOC, LED1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, LED4, GPIO_PIN_SET);

}

void turn_on_even_leds(void)
{
	HAL_GPIO_WritePin(GPIOC, LED1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, LED4, GPIO_PIN_SET);

}
void turn_on_odd_leds(void)
{
	HAL_GPIO_WritePin(GPIOC, LED1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, LED4, GPIO_PIN_RESET);
}

void Led_Control (int value)
{
	static uint8_t a = 0 ;
	static uint8_t b = 0 ;
	HAL_GPIO_WritePin(GPIOC, LED1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED3, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(GPIOD, LED4) ;
	if (value == 1)
	{
		b = 0 ;
		HAL_GPIO_WritePin(GPIOC,LED3<<a,GPIO_PIN_SET);
		a = (a+1) %4 ;
	}
	else
	{
		a = 0 ;
		HAL_GPIO_WritePin(GPIOC,LED1>>b,GPIO_PIN_SET);
		b = (b + 1) % 4 ;
	}
}

void led_effect1(void)
{
	static int flag = 1 ;
	(flag ^=1) ? turn_off_all_leds() : turn_on_all_leds() ;
}

void led_effect2(void)
{
	static int flag = 1 ;
	(flag ^=1) ? turn_on_even_leds() : turn_on_odd_leds() ;

}
void led_effect3(void)
{
	Led_Control(1);
}
void led_effect4(void)
{
	Led_Control(0);
}



