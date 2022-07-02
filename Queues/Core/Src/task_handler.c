/*
 * task_handler.c
 *
 *  Created on: May 31, 2022
 *      Author: Truong
 */
#include "main.h"


int extract_cmmand ( command_t *cmd ) ;
void process_command ( command_t *cmd) ;


const char *msg_inv = "///// Invalid option ???? ///// \n" ;


uint8_t get_number(uint8_t *p , int len )
{
	int value ;
	if (len>1)
	{
		value = (((p[0]-48)*10) +(p[1]-48)) ;
	}
	else
	value = p[0]-48 ;
	return value ;
}

void menu_task ( void *param)
{
	uint32_t cmd_addr ;
	const char *msg_menu = "====================\n"
						  "|     MENU           |\n "
						   "====================\n"
								"LED	--> 0\n"
								"Date and Time  --> 1 \n"
								"Exit	--> 2 \n"
								"Enter  your choice here : " ;
	command_t *cmd ;
	int option ;

	while(1)
	{
		xQueueSend(q_printf,&msg_menu,portMAX_DELAY) ;
		// Wait for menu command
		xTaskNotifyWait(0,0,&cmd_addr,portMAX_DELAY) ;
		cmd = (command_t *) cmd_addr ;

		if (cmd->len == 1)
		{
			option = cmd->payload[0] - 48  ;  //  just convert ASCII to number by subtracting 48

			switch (option)
			{
			case 0:
					curr_state  = sLedEffect ;
					xTaskNotify(handle_led_task,0,eNoAction);
					break;
			case 1:
				curr_state  = sRtcMenu ;
					xTaskNotify(handle_rtc_task,0,eNoAction);
					break;
			case 2:  // Implement exit
					break;
			default:
				xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;
					continue;
			}
		}
		else
		{
			//invalid entry.
			xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;
			continue ;
		}


		// wait to run again when some other task notifies
		xTaskNotifyWait(0,0,NULL,portMAX_DELAY);

	} // while super loop.
}


void printf_task ( void *param)
{
	uint32_t *msg ;
	while(1)
	{
		xQueueReceive(q_printf,&msg, portMAX_DELAY);
		HAL_UART_Transmit(&huart2,(uint8_t*)msg, strlen((char*)msg), HAL_MAX_DELAY);
	}
}
void led_task ( void *param)
{
	uint32_t cmd_addr;
	command_t *cmd;
	const char* msg_led = "========================\n"
						  "|      LED Effect     |\n"
						  "========================\n"
						  "(s,e1,e2,e3,e4)\n"
						  "Enter your choice here : ";

	while(1){
		/*TODO: Wait for notification (Notify wait) */
		xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
		/*TODO: Print LED menu */
		xQueueSend(q_printf,&msg_led,portMAX_DELAY);
		/*TODO: wait for LED command (Notify wait) */
		xTaskNotifyWait(0,0,&cmd_addr,portMAX_DELAY) ;
		cmd = (command_t *) cmd_addr ;

		if(cmd->len <= 4)
		{
			if(! strcmp((char*)cmd->payload,"s"))
				led_effect_stop();
			else if (! strcmp((char*)cmd->payload,"e1"))
				led_effect(1);
			else if (! strcmp((char*)cmd->payload,"e2"))
				led_effect(2);
			else if (! strcmp((char*)cmd->payload,"e3"))
				led_effect(3);
			else if (! strcmp((char*)cmd->payload,"e4"))
				led_effect(4);
			else
				/*TODO: print invalid message */
				xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;
		}else
			/*TODO: print invalid message */
			xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;
		/*TODO : update state variable */
		curr_state = sMainMenu;

		/*TODO : Notify menu task */
		xTaskNotify(handle_menu_task,0,eNoAction);

	}
}

void rtc_task(void *param)
{
	const char* msg_rtc1 = "========================\n"
							"|         RTC          |\n"
							"========================\n";

	const char* msg_rtc2 = "Configure Time            ----> 0\n"
							"Configure Date            ----> 1\n"
							"Enable reporting          ----> 2\n"
							"Exit                      ----> 3\n"
							"Enter your choice here : ";


	const char *msg_rtc_hh = "Enter hour(1-24):";
	const char *msg_rtc_mm = "Enter minutes(0-59):";
	const char *msg_rtc_ss = "Enter seconds(0-59):";

	const char *msg_rtc_dd  = "Enter date(1-31):";
	const char *msg_rtc_mo  ="Enter month(1-12):";
	const char *msg_rtc_dow  = "Enter day(1-7 sun:1):";
	const char *msg_rtc_yr  = "Enter year(0-99):";

	const char *msg_conf = "Configuration successful\n";
	const char *msg_rtc_report = "Enable time&date reporting(y/n)?: ";


	uint32_t cmd_addr;
	command_t *cmd;
	int menu_code ;
	static int rtc_state = 0 ;
	 RTC_TIME time ;

#define HH_CONFIG	0
#define MM_CONFIG	1
#define SS_CONFIG	2

#define DATE_CONFIG		0
#define MONTH_CONFIG	1
#define DAY_CONFIG		2
#define YEAR_CONFIG		3

	while(1){
		/*TODO: Notify wait (wait till someone notifies) */
			xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
		/*TODO : Print the menu and show current date and time information */
			xQueueSend(q_printf,&msg_rtc1,portMAX_DELAY) ;
			show_time_date(&time);
			xQueueSend(q_printf,&msg_rtc2,portMAX_DELAY) ;

		while(curr_state != sMainMenu)
		{

			/*TODO: Wait for command notification (Notify wait) */
			xTaskNotifyWait(0,0,&cmd_addr,portMAX_DELAY);
			cmd = (command_t *)cmd_addr ;
			switch(curr_state)
			{
				case sRtcMenu:
					{
						/*process RTC menu commands */
						if (cmd->len == 1)
						{
							menu_code = cmd->payload[0]-48 ;
							switch(menu_code)
							{
							case 0:
								curr_state = sRtcTimeConfig ;
								xQueueSend(q_printf,&msg_rtc_hh,portMAX_DELAY) ;
								break ;
							case 1:
								curr_state = sRtcDateConfig ;
								xQueueSend(q_printf,&msg_rtc_dd,portMAX_DELAY) ;
								break ;
							case 2:
								curr_state = sRtcReport ;
								xQueueSend(q_printf,&msg_rtc_report,portMAX_DELAY) ;
								break ;
							case 3:
								curr_state = sMainMenu ;
								break ;
							default:
								curr_state = sMainMenu ;
								xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;
							}
						}
						else
						{
							curr_state = sMainMenu ;
							xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;
						}

						break;
					}

				case sRtcTimeConfig:
					{
					/* get hh, mm, ss infor and configure RTC */
						switch(rtc_state)
						{
						case HH_CONFIG:
							{
								uint8_t hour = get_number(cmd->payload, cmd->len) ;
								time.hour = hour ;
								rtc_state = MM_CONFIG ;
								xQueueSend(q_printf,&msg_rtc_mm,portMAX_DELAY) ;
								break;
							}
						case MM_CONFIG:
							{
								uint8_t min = get_number(cmd->payload, cmd->len) ;
								time.minutes = min ;
								rtc_state = SS_CONFIG ;
								xQueueSend(q_printf,&msg_rtc_ss,portMAX_DELAY) ;
								break;
							}

						case SS_CONFIG:
							{
								uint8_t sec = get_number(cmd->payload, cmd->len) ;
								time.seconds = sec ;
								if (!validate_rtc_information(&time))
								{
									RTC_Set_Time(&time) ;
									xQueueSend(q_printf,&msg_conf,portMAX_DELAY) ;
									show_time_date(&time);

								}
								else
									xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;

								curr_state = sMainMenu ;
								rtc_state = 0 ;
								break ;

							}
						} // switch(rtc_state)

					break;} // case sRtcTimeConfig:

				case sRtcDateConfig:
						{

							/* get date, month, day , year info and configure RTC */
							switch(rtc_state)
								{
								case DATE_CONFIG:
									{
										uint8_t d = get_number(cmd->payload, cmd->len) ;
										time.dayofmonth = d ;
										rtc_state = MONTH_CONFIG ;
										xQueueSend(q_printf,&msg_rtc_mo,portMAX_DELAY) ;
										break;
									}
								case MONTH_CONFIG:
									{
										uint8_t month = get_number(cmd->payload, cmd->len) ;
										time.month = month ;
										rtc_state = DAY_CONFIG ;
										xQueueSend(q_printf,&msg_rtc_dow,portMAX_DELAY) ;
										break;
									}
								case DAY_CONFIG:
								{
									uint8_t day = get_number(cmd->payload, cmd->len) ;
									time.dayofweek = day ;
									rtc_state = YEAR_CONFIG ;
									xQueueSend(q_printf,&msg_rtc_yr,portMAX_DELAY) ;
									break;
								}

								case YEAR_CONFIG:
									{
										uint8_t year = get_number(cmd->payload, cmd->len) ;
										time.year = year ;
										if (!validate_rtc_information(&time))
										{
											RTC_Set_Time(&time) ;
											xQueueSend(q_printf,&msg_conf,portMAX_DELAY) ;
											show_time_date(&time);

										}
										else
											xQueueSend(q_printf,&msg_inv,portMAX_DELAY) ;

										curr_state = sMainMenu ;
										rtc_state = 0 ;
										break ;

									}
								}
							break;
						}

				case sRtcReport:{
					/*TODO: enable or disable RTC current time reporting over ITM printf */
					curr_state = sMainMenu ;
					break;}

			}// switch end

		} //while end

		   /* Notify menu task */
		xTaskNotify(handle_menu_task,0,eNoAction);

		}//while super loop end
}

void cmd_hanlder_task ( void *param)
{
	BaseType_t ret ;
	command_t cmd ;
	while(1)
	{
			/* Implement notify wait */
		ret = xTaskNotifyWait(0,0,NULL,portMAX_DELAY);

		if (ret == pdTRUE)
		{
			/* process the user data ( command) stored  in input data  queue */
			process_command(&cmd) ;
		}


	}
}


void process_command ( command_t *cmd)
{
	extract_cmmand(cmd);

	switch (curr_state )
	{
	case sMainMenu:
			xTaskNotify(handle_menu_task,(uint32_t)cmd ,eSetValueWithOverwrite) ;
			break ;
	case sLedEffect:
			xTaskNotify(handle_led_task,(uint32_t)cmd ,eSetValueWithOverwrite) ;
			break ;
	case sRtcMenu:
	case sRtcTimeConfig:
	case sRtcDateConfig:
	case sRtcReport:
		xTaskNotify(handle_rtc_task,(uint32_t)cmd ,eSetValueWithOverwrite) ;
		break ;


	}


}


int extract_cmmand ( command_t *cmd )
{
	uint8_t item ;
	BaseType_t status ;
	status = uxQueueMessagesWaiting(q_data);
	if (!status) return  -1 ;

	uint8_t i = 0 ;
	do
	{
		status = xQueueReceive(q_data, &item, 0) ;
		if (status == pdTRUE) cmd->payload[i++] = item ;

	}
	while (item !='\n');
	cmd->payload[i-1] = '\0';
	cmd->len = i-1 ;

	return 0 ;
}


void initTimer(void)
{
	   for (int i = 0 ; i< 4 ; i ++)
	   {
		   handle_led_timer[i] =  xTimerCreate("led_timer", pdMS_TO_TICKS(500),pdTRUE,(void *)(i+1),led_effect_callback) ;
	   }
}
void led_effect_callback (TimerHandle_t xTimer)
{
	int id ;
	id = (uint32_t)pvTimerGetTimerID(xTimer) ;
	switch(id)
	{
	case 1:
		led_effect1();
		break ;
	case 2:
		led_effect2();
		break ;
	case 3:
		led_effect3();
		break ;
	case 4:
		led_effect4();
		break ;


	}

}




























