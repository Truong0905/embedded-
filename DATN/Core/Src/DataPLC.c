#include "DataPLC.h"
#include "ff.h"

int extract_command ( command_t *cmd ) ;
void process_command ( command_t *cmd) ;
void checkState( command_t *cmd );
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

volatile static uint8_t I[2][8] = {};
volatile static uint8_t Q[2][8] = {};
volatile static uint8_t M[10][2] = {};
volatile static uint8_t T37 = 0;
volatile static uint32_t countT37 = 0;
volatile static uint32_t T37reset = 0;
volatile static uint8_t C1 = 0;
volatile static uint32_t countC1 = 0;
volatile static uint8_t C2 = 0;
volatile static uint32_t countC2 = 0;

FATFS fs;  // file system
FIL fil; // File
FILINFO fno;
FRESULT fresult;  // result
UINT br, bw;  // File read/write count

/**** capacity related *****/
FATFS *pfs;
DWORD fre_clust;
uint32_t total, free_space;

#define BUFFER_SIZE 128
char buffer[BUFFER_SIZE];  // to store strings..

int i=0;

int bufsize (char *buf)
{
	int i=0;
	while (*buf++ != '\0') i++;
	return i;
}

void clear_buffer (void)
{
	for (int i=0; i<BUFFER_SIZE; i++) buffer[i] = '\0';
}

void send_uart (char *string)
{
	uint8_t len = strlen (string);
	HAL_UART_Transmit(&huart3, (uint8_t *) string, len, HAL_MAX_DELAY);  // transmit in blocking mode
}



void read_Pin_Input()
{
	I0_0 = HAL_GPIO_ReadPin(I0_0_PORT, I0_0_PIN);
}
void write_Pin_Output()
{
	if (Q0_0 >= 1)
	{
		HAL_GPIO_WritePin(Q0_0_PORT, Q0_0_PIN, ENABLE);
	}
	else
	{
		HAL_GPIO_WritePin(Q0_0_PORT, Q0_0_PIN, DISABLE);
	}
	if (Q0_1 >= 1)
	{
		HAL_GPIO_WritePin(Q0_1_PORT, Q0_1_PIN, ENABLE);
	}
	else
	{
		HAL_GPIO_WritePin(Q0_1_PORT, Q0_1_PIN, DISABLE);
	}
	if (Q0_2 >= 1)
	{
		HAL_GPIO_WritePin(Q0_2_PORT, Q0_2_PIN, ENABLE);
	}
	else
	{
		HAL_GPIO_WritePin(Q0_2_PORT, Q0_2_PIN, DISABLE);
	}
}
void Main_task(void *param)
{
	volatile static uint8_t vaoT37 = 0;
	volatile static const uint32_t datT37 = 10;
	volatile static uint8_t checkT37 = 0;
	volatile static uint8_t vaoC1 = 0;
	volatile static uint8_t resetC1 = 0;
	volatile static const uint32_t datC1 = 50;
	volatile static uint8_t startC1 = 0;
	volatile static uint8_t checkC1 = 0;
	volatile static uint8_t vaoC2 = 0;
	volatile static uint8_t resetC2 = 0;
	volatile static const uint32_t datC2 = 2;
	volatile static uint8_t startC2 = 0;
	volatile static uint8_t checkC2 = 0;
	while (1)
	{
		read_Pin_Input();
		/*--------------NetWork 1 -----------*/

		volatile uint8_t tempC2_0 = 0;
		if (countC2 < 2)
		{
			tempC2_0 = 1;
		}
		M0_0 = ((I0_0 + M0_0) * tempC2_0);
		if (M0_0 > 0)
		{
			M0_0 = 1;
		}
		else
		{
			M0_0 = 0;
		}
		/*--------------NetWork 2 -----------*/

		if (!T37reset)
		{
			vaoT37 = (M0_0);
			T37;
			if (vaoT37)
			{
				if (countT37 >= datT37)
					T37 = 1;

				if ((T37 == 0) && (checkT37 == 0))
				{
					xTimerStart(handle_timerPLC[0], portMAX_DELAY);
					checkT37 = 1;
				}
			}
			else
			{
				if (checkT37 == 1)
				{
					xTimerStop(handle_timerPLC[0], portMAX_DELAY);
					checkT37 = 0;
				}
				T37 = 0;
				countT37 = 0;
			}
		}
		else
		{
			xTimerStop(handle_timerPLC[0], portMAX_DELAY);
			countT37 = 0;
			T37 = 0;
			checkT37 = 0;
		}
		/*--------------NetWork 3 -----------*/

		volatile uint8_t T37sl0 = T37;
		volatile static uint8_t checkEU0 = 0;
		if (!(T37))
		{
			checkEU0 = 0;
		}
		if ((!checkEU0) && (T37))
		{
			checkEU0 = 0;
			T37sl0 = 1;
		}
		volatile uint8_t tempC1_1 = 0;
		if (countC1 >= 50)
		{
			tempC1_1 = 1;
		}
		vaoC1 = (T37sl0);
		resetC1 = (tempC1_1 + (!M0_0));
		if (resetC1)
		{
			countC1 = 0;
			C1 = 0;
			startC1 = 1;
		}
		else
		{
			if (vaoC1)
			{
				if (((checkC1 == 1) || (startC1 == 1)) && (countC1 <= 4294967295))
				{
					countC1++;
					startC1 = 0;
				}
				if (countC1 >= datC1)
				{
					C1 = 1;
				}
			}
			else
			{
				checkC1 = 1;
			}
		}
		/*--------------NetWork 4 -----------*/

		volatile uint8_t tempC1_2 = 0;
		if (countC1 <= 20)
		{
			tempC1_2 = 1;
		}
		Q0_0 = (tempC1_2 * M0_0);
		if (Q0_0 > 0)
		{
			Q0_0 = 1;
		}
		else
		{
			Q0_0 = 0;
		}
		/*--------------NetWork 5 -----------*/

		volatile uint8_t tempC1_3 = 0;
		if (countC1 > 20)
		{
			tempC1_3 = 1;
		}
		volatile uint8_t tempC1_4 = 0;
		if (countC1 <= 25)
		{
			tempC1_4 = 1;
		}
		Q0_2 = (tempC1_3 * tempC1_4 * M0_0);
		if (Q0_2 > 0)
		{
			Q0_2 = 1;
		}
		else
		{
			Q0_2 = 0;
		}
		/*--------------NetWork 6 -----------*/

		volatile uint8_t tempC1_5 = 0;
		if (countC1 > 25)
		{
			tempC1_5 = 1;
		}
		Q0_1 = (tempC1_5 * M0_0);
		if (Q0_1 > 0)
		{
			Q0_1 = 1;
		}
		else
		{
			Q0_1 = 0;
		}
		/*--------------NetWork 7 -----------*/

		volatile uint8_t T37sl1 = T37;
		volatile static uint8_t checkEU1 = 0;
		if (!(T37))
		{
			checkEU1 = 0;
		}
		if ((!checkEU1) && (T37))
		{
			checkEU1 = 0;
			T37sl1 = 1;
		}
		T37reset = (T37sl1);
		if (T37reset > 0)
		{
			T37reset = 1;
		}
		else
		{
			T37reset = 0;
		}
		/*--------------NetWork 8 -----------*/

		vaoC2 = (I0_0);
		resetC2 = (C2);
		if (resetC2)
		{
			countC2 = 0;
			C2 = 0;
			startC2 = 1;
		}
		else
		{
			if (vaoC2)
			{
				if (((checkC2 == 1) || (startC2 == 1)) && (countC2 <= 4294967295))
				{
					countC2++;
					startC2 = 0;
				}
				if (countC2 >= datC2)
				{
					C2 = 1;
				}
			}
			else
			{
				checkC2 = 1;
			}
		}
		write_Pin_Output();
		vTaskDelay(2);
	}
}
void TimerCallBack(TimerHandle_t xTimer)
{
	int id;
	id = (uint32_t)pvTimerGetTimerID(xTimer);
	switch (id)
	{
	case 1:
		countT37++;
		break;
	}
}
void initTimer(void)
{
	handle_timerPLC[0] = xTimerCreate("timerTONT37", pdMS_TO_TICKS(100), pdTRUE, (void *)(0 + 1), TimerCallBack);
}

const char *msg_menu =  "====================\n"
		  	  	  	  	"|     MENU           |\n "
		   	   	  	  	"====================\n"
							"Run	--> 0\n"
							"Setting  --> 1 \n"
						"Enter  your choice here : " ;
const char *msg_inv = "///// Invalid option ???? ///// \n" ;

#define MENU_MESS HAL_UART_Transmit(&huart3,(uint8_t*)msg_menu, strlen(msg_menu), HAL_MAX_DELAY)
#define INVALID_MESS HAL_UART_Transmit(&huart3,(uint8_t*)msg_inv, strlen(msg_inv), HAL_MAX_DELAY)


void Start_task ( void *param)
{
	BaseType_t status ;
	while(1)
	{
		status = xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
		if (status != pdTRUE) continue ;
		curr_state = sNone ;

	}
}
void Send_task ( void *param)
{
	while(1)
	{
		if (curr_state != sNone)
		{
			 xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
			continue ;
		}
	}
}
void Setting_task( void *param)
{
	const char* msg_rtc1 = "========================\n"
							"|         Setting     |\n"
							"========================\n";

	const char* msg_rtc2 = "Configure Time            ----> 0\n"
							"Configure Date            ----> 1\n"
							"Exit                      ----> 2\n"
							"Enter your choice here : ";


	const char *msg_rtc_hh = "Enter hour(1-24):";
	const char *msg_rtc_mm = "Enter minutes(0-59):";
	const char *msg_rtc_ss = "Enter seconds(0-59):";

	const char *msg_rtc_dd  = "Enter date(1-31):";
	const char *msg_rtc_mo  ="Enter month(1-12):";
	const char *msg_rtc_dow  = "Enter day(1-7 sun:1):";
	const char *msg_rtc_yr  = "Enter year(0-99):";

	const char *msg_conf = "Configuration successful\n";

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
BaseType_t status ;
	while(1)
	{
			status = xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
			if (status != pdTRUE) continue ;
			HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc1, strlen(msg_rtc1), HAL_MAX_DELAY);
			show_time_date(&time);
			HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);

		while(curr_state != sMenu )
		{

			xTaskNotifyWait(0,0,&cmd_addr,portMAX_DELAY);
			cmd = (command_t *)cmd_addr ;
			switch(curr_state)
			{
				case sSetting:
					{
						/*process RTC menu commands */
						if (cmd->len == 1)
						{
							menu_code = cmd->payload[0]-48 ;
							switch(menu_code)
							{
							case 0:
								curr_state = sRtcTimeConfig ;
								//xQueueSend(q_printf,&msg_rtc_hh,portMAX_DELAY) ;
								HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_hh, strlen(msg_rtc_hh), HAL_MAX_DELAY);
								break ;
							case 1:
								curr_state = sRtcDateConfig ;
								HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_dd, strlen(msg_rtc_dd), HAL_MAX_DELAY);
								break ;
							case 2:
								curr_state = sMenu;
								MENU_MESS ;
								break ;
							default:
								INVALID_MESS ;
								HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
							}
						}
						else
						{
							INVALID_MESS ;
							HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
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
								HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_mm, strlen(msg_rtc_mm), HAL_MAX_DELAY);
								break;
							}
						case MM_CONFIG:
							{
								uint8_t min = get_number(cmd->payload, cmd->len) ;
								time.minutes = min ;
								rtc_state = SS_CONFIG ;
								HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_ss, strlen(msg_rtc_ss), HAL_MAX_DELAY);
								break;
							}

						case SS_CONFIG:
							{
								uint8_t sec = get_number(cmd->payload, cmd->len) ;
								time.seconds = sec ;
								if (!validate_rtc_information(&time))
								{
									RTC_Set_Time(&time) ;
									HAL_UART_Transmit(&huart3,(uint8_t*)msg_conf, strlen(msg_conf), HAL_MAX_DELAY);
									show_time_date(&time);
									curr_state = sMenu ;
									MENU_MESS ;

								}
								else
								{
									INVALID_MESS ;
									curr_state = sSetting ;
									HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
								}
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
										HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_mo, strlen(msg_rtc_mo), HAL_MAX_DELAY);
										break;
									}
								case MONTH_CONFIG:
									{
										uint8_t month = get_number(cmd->payload, cmd->len) ;
										time.month = month ;
										rtc_state = DAY_CONFIG ;
										HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_dow, strlen(msg_rtc_dow), HAL_MAX_DELAY);
										break;
									}
								case DAY_CONFIG:
								{
									uint8_t day = get_number(cmd->payload, cmd->len) ;
									time.dayofweek = day ;
									rtc_state = YEAR_CONFIG ;
									HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_yr, strlen(msg_rtc_yr), HAL_MAX_DELAY);
									break;
								}

								case YEAR_CONFIG:
									{
										uint8_t year = get_number(cmd->payload, cmd->len) ;
										time.year = year ;
										if (!validate_rtc_information(&time))
										{
											RTC_Set_Time(&time) ;
											HAL_UART_Transmit(&huart3,(uint8_t*)msg_conf, strlen(msg_conf), HAL_MAX_DELAY);
											show_time_date(&time);
											curr_state = sMenu ;
											MENU_MESS ;

										}
										else
										{
											INVALID_MESS ;
											curr_state = sSetting ;
											HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
										}
										rtc_state = 0 ;
										break ;

									}
								}
							break;
						}


			}// switch end

		} //while end

		}//while super loop end
}
void Command_task( void *param)
{

	BaseType_t status ;
	command_t cmd ;
	MENU_MESS ;
	while(1)
	{
			/* Implement notify wait */
		status = xTaskNotifyWait(0,0,NULL,portMAX_DELAY);

		if (status == pdTRUE)
		{
			/* process the user data ( command) stored  in input data  queue */
			if (curr_state == sNone)
			{
				curr_state = sMenu ;
			}
			process_command(&cmd) ;
		}


	}
}

void process_command ( command_t *cmd)
{
	extract_command(cmd);

	if (curr_state != sNone)
	{
		if (curr_state == sMenu)
		checkState(cmd);
		switch (curr_state )
		{

		case sRtcDateConfig:
		case sRtcTimeConfig:
		case sSetting:
				xTaskNotify(handle_setting_task,(uint32_t)cmd ,eSetValueWithOverwrite) ;
				break ;
		case sRunToStart:
		case sRunToRestart:
		case sRun:
				xTaskNotify(handle_start_task,(uint32_t)cmd ,eSetValueWithOverwrite) ;
				break ;
		 default:
			 INVALID_MESS ;
			 MENU_MESS ;


		}
	}



}

int extract_command ( command_t *cmd )
{
	uint8_t item ;
	BaseType_t status ;
	status = uxQueueMessagesWaiting(q_data); // trả về số phần tử có sẵn trong hàng đợi
	if (!status) return  -1 ; // nếu không có phần tử nào

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

void checkState( command_t *cmd )
{
	uint8_t option ;
	if (cmd->len == 1 )
	{
		option = get_number(cmd->payload, cmd->len);
		switch(option)
		{
		case 0:
			curr_state = sRun;
			break;
		case 1:
			curr_state = sSetting ;
		}
	}
}

