/*
 * rtc.c
 *
 *  Created on: May 31, 2022
 *      Author: Truong
 */

#include"main.h"



// Convert normal decimal numbers to binary coded decimal
uint8_t RTC_decToBcd(int val)
{
  return (uint8_t)( (val/10*16) + (val%10) );
}

// Convert binary coded decimal to normal decimal numbers
int RTC_bcdToDec(uint8_t val)
{
  return (int)( (val/16*10) + (val%16) );
}

//void RTC_Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year)
void RTC_Set_Time (RTC_TIME *time)
{
	uint8_t set_time[7];
	set_time[0] = RTC_decToBcd(time->seconds);
	set_time[1] = RTC_decToBcd(time->minutes);
	set_time[2] = RTC_decToBcd(time->hour);
	set_time[3] = RTC_decToBcd(time->dayofweek);
	set_time[4] = RTC_decToBcd(time->dayofmonth);
	set_time[5] = RTC_decToBcd(time->month);
	set_time[6] = RTC_decToBcd(time->year);

	HAL_I2C_Mem_Write(&hi2c1, DS3231_ADDRESS, 0x00, 1, set_time, 7, portMAX_DELAY);

}

void RTC_Get_Time (RTC_TIME *time)
{
	uint8_t get_time[7];
	HAL_I2C_Mem_Read(&hi2c1, DS3231_ADDRESS, 0x00, 1, get_time, 7, portMAX_DELAY);
	time->seconds = RTC_bcdToDec(get_time[0]);
	time->minutes = RTC_bcdToDec(get_time[1]);
	time->hour = RTC_bcdToDec(get_time[2]);
	time->dayofweek = RTC_bcdToDec(get_time[3]);
	time->dayofmonth = RTC_bcdToDec(get_time[4]);
	time->month = RTC_bcdToDec(get_time[5]);
	time->year = RTC_bcdToDec(get_time[6]);
}


void show_time_date(RTC_TIME *time)
{
	//static char buffer[60];
	// static char *rtc_time = buffer ;
//	memset(&rtc_time,0,sizeof(rtc_time)) ;
	RTC_Get_Time(time) ;
	// sprintf ((char *)buffer, "Time&Date :  %02d:%02d:%02d     %02d-%02d-20%02d \n",  time->hour, time->minutes, time->seconds ,time->dayofmonth, time->month, time->year);
	// xQueueSend(q_printf,&rtc_time,portMAX_DELAY) ;

}


int validate_rtc_information (RTC_TIME *time)
{
	if ( time->hour > 24 || time->minutes > 59 || time->seconds > 59 || time->dayofweek > 7 || time->dayofmonth > 31 || time->month > 12 || time->year > 99 )
	{
		return 1 ;
	}
	return 0 ;
}


