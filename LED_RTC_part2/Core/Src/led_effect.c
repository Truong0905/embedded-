/*
 * led_effect.c
 *
 *  Created on: May 31, 2022
 *      Author: Truong
 */

#include "main.h"


void led_effect_stop (void)
{
	for ( int i ; i< 4 ; i++)
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
	if (value == 1)
	{
		for (int i = 0 ; i< 4 ; i++)
		{
			if ( i< 3)
			{
				HAL_GPIO_WritePin(GPIOC,(LED1<<i),GPIO_PIN_SET) ;
			}
			else
				HAL_GPIO_WritePin(GPIOD, LED4, GPIO_PIN_RESET);
		}
	}
	else
	{
		for (int i = 3 ; i >=0 ; i--)
		{
			if ( i > 0)
			{
				HAL_GPIO_WritePin(GPIOC,(LED3>>i),GPIO_PIN_SET) ;
			}
			else
				HAL_GPIO_WritePin(GPIOD, LED4, GPIO_PIN_RESET);
		}
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



