/*
 * rtc.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Truong
 */

#ifndef RTC_INC_RTC_H_
#define RTC_INC_RTC_H_

#include "main.h"
#include <string.h>
#include<stdio.h>
extern I2C_HandleTypeDef hi2c1;

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

#define DS3231_ADDRESS 0xd0


uint8_t RTC_decToBcd(int val);
int RTC_bcdToDec(uint8_t val) ;
void RTC_Set_Time (RTC_TIME *time) ;
void RTC_Get_Time (RTC_TIME *time) ;
void show_time_date(RTC_TIME *time) ;
int validate_rtc_information (RTC_TIME *time) ;
#endif /* RTC_INC_RTC_H_ */
