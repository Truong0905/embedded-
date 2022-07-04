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
static FIL fil; // File
FILINFO fno;
static FRESULT fresult = 1;  // result
UINT br, bw;  // File read/write count

/**** capacity related *****/
FATFS *pfs;
DWORD fre_clust;
uint32_t total, free_space;
static uint8_t checkDay = 32 ;
static uint8_t checkYear = 0 ;
static char timeBuffer[20];

int bufsize (char *buf)
{
	int i=0;
	while (*buf++ != '\0') i++;
	return i;
}

void clear_buffer (char *buffer , uint8_t len)
{
	for (int i=0; i<len; i++) buffer[i] = '\0';
}

void send_uart (const char *string)
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
const char *msg_time_error = "Time error \n" ;

void Start_task ( void *param)
{
	BaseType_t status ;
	uint32_t cmd_addr;
	command_t *cmd;
	 RTC_TIME time ;
	 const char *msg_start = "====================\n"
	  	  	  				"|     	START         |\n "
	   	  	  				"====================\n"
							"Run only			--> 0\n"
							"Run and save data  --> 1 \n"
							"Exit  				-->2  \n"
			 	 	 	 	"Enter  your choice here : " ;
	while(1)
	{

		status = xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
		if (status != pdTRUE) continue ;
		RTC_Get_Time(&time);
		if (time.year == 0)
		{
			send_uart(msg_time_error);
			send_uart(msg_menu);
			curr_state = sMenu ;
			checkYear = 0 ;
			continue ;
		}
		send_uart(msg_start);

		while(curr_state != sNone && curr_state != sRunAndSave && curr_state != sRunOnly )
		{
			xTaskNotifyWait(0,0,&cmd_addr,portMAX_DELAY);
			cmd = (command_t *)cmd_addr ;
			if (cmd->len == 1)
			{
				uint8_t menu_code = cmd->payload[0]-48 ;
				switch(menu_code)
				{
				case 0:
					curr_state = sRunOnly ;
					break ;
				case 1:
					curr_state = sRunAndSave ;
					break ;
				case 2:
					curr_state = sNone;
					send_uart(msg_menu);
					break ;
				default:
					send_uart(msg_inv);
					send_uart(msg_start);
				}
			}
			else
			{
				send_uart(msg_inv);
				send_uart(msg_start);
			}
		} // while curr_state
		if (curr_state == sNone)
		{
			continue ;
		}
		checkDay = time.dayofmonth ;
		clear_buffer(timeBuffer, 20);
		sprintf(timeBuffer,"%02d_%02d_%02ddata.txt",checkDay,time.month,time.year);

		//------------------ KIEM TRA HOAT DONG -----------------//
				fresult = f_mount(&fs, "/", 1);
				if (fresult != FR_OK)
				{
					send_uart ("LOI !!! KIEM TRA LAI SD CARD...\n\n");
					send_uart(msg_menu);
					curr_state = sMenu ;
					continue ;
				}
				else send_uart("KET NOI THANH CONG\n\n");
		if (curr_state == sRunAndSave)
		{
			int tempCheckDay = checkDay-1;
			char tempTimeBuffer[20];
			if (checkDay ==1 && time.month ==1 )
			{
					tempCheckDay = 31 ;
						while(tempCheckDay)
						{
							sprintf(tempTimeBuffer,"%02d_%02d_%02ddata.txt",tempCheckDay,12,time.year-1);
							fresult = f_open(&fil,tempTimeBuffer, FA_READ);
							if (fresult == FR_OK)
								break ;
							tempCheckDay -- ;
						}


			}
			else if ( checkDay ==1 )
			{
				if (time.month ==3 )
				{
					if (! (time.year % 4))
					{
						tempCheckDay = 29 ;
					}
					else
					{
						tempCheckDay = 28 ;
					}

				}
				if (time.month == 4 || time.month == 6 || time.month == 9 || time.month == 11)
				{
					tempCheckDay = 30 ;
				}
				else
				{
					tempCheckDay = 31 ;
				}
				while(tempCheckDay)
				{
					sprintf(tempTimeBuffer,"%02d_%02d_%02ddata.txt",tempCheckDay,time.month-1,time.year);
					fresult = f_open(&fil,tempTimeBuffer, FA_READ);
					if (fresult == FR_OK)
						break ;
					tempCheckDay -- ;
				}

			}
			else
			{
				while(tempCheckDay)
				{
					sprintf(tempTimeBuffer,"%02d_%02d_%02ddata.txt",tempCheckDay,time.month,time.year);
					fresult = f_open(&fil,tempTimeBuffer, FA_READ);
					if (fresult == FR_OK)
						break ;
					tempCheckDay -- ;
				}
			}

		}// if  (curr_state == sRunAndSave)
		char buffer[50]={};
		if (fresult == FR_OK)
		{
			while (f_gets(buffer, 50, &fil))
				{
					send_uart(buffer);
					clear_buffer(buffer,50);
				}
			f_close(&fil);
		}
	// ------------------------ TAO FILE MOI -----------------------//
		fresult = f_open(&fil,timeBuffer, FA_WRITE); // Nếu đã tạo thì không tạo nữa
		if (fresult != FR_OK)
		{
			fresult = f_open(&fil,timeBuffer, FA_CREATE_ALWAYS | FA_WRITE);
					if (fresult != FR_OK)
					{
						send_uart("Khong Tao duoc file\n");
						curr_state =sRun ;
						send_uart(msg_start);
					}
					else
					{
						send_uart("Tao file thanh cong\n");
						curr_state = sNone ;
						send_uart(msg_menu);
						f_close(&fil);
						xTaskNotify(handle_send_task,0,eNoAction);
					}
		}
		else
		{
				send_uart("File da duoc tao\n");
				curr_state = sNone ;
				send_uart(msg_menu);
				f_close(&fil);
				xTaskNotify(handle_send_task,0,eNoAction);

		}



	}// big while
}
void Send_task ( void *param)
{
	static uint8_t checkQ0_0 = 1;
	static uint8_t checkQ0_1 = 1;
	static uint8_t checkQ0_2 = 1;
	static char Buffer[50] ;
	clear_buffer(Buffer, 50) ;
	RTC_TIME time ;
	while(1)
	{
		if (curr_state == sRunAndSave || curr_state == sRtcDateConfig || curr_state == sRtcTimeConfig )
		{
			 xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
			continue ;
		}
		fresult = f_open(&fil,timeBuffer, FA_WRITE);
		fresult = f_lseek(&fil, f_size(&fil));
		if (fresult == FR_OK)
		{
			if (Q0_0 ==1 && checkQ0_0 ==1)
			{
				checkQ0_0 = 0 ;
				RTC_Get_Time(&time);
				sprintf(Buffer,"%02d-%02d-%02d :Xanh\n",time.hour,time.minutes,time.seconds);
				 f_puts(Buffer, &fil);

			}
			else if (Q0_0 == 0)
			{
				checkQ0_0 = 1 ;
			}

			if (Q0_1 ==1 && checkQ0_1 ==1)
			{
					checkQ0_1 = 0 ;
					RTC_Get_Time(&time);
					sprintf(Buffer,"%02d-%02d-%02d :Do\n",time.hour,time.minutes,time.seconds);
					f_puts(Buffer, &fil);
			}
			else if ( Q0_1 == 0 )
			{
				checkQ0_1 = 1 ;
			}

			if (Q0_2 ==1 && checkQ0_2 ==1)
			{
					checkQ0_2 = 0 ;
					RTC_Get_Time(&time);
					sprintf(Buffer,"%02d-%02d-%02d :Vang\n",time.hour,time.minutes,time.seconds);
					f_puts(Buffer, &fil);
			}
			else if (Q0_2 == 0)
			{
					checkQ0_2 = 1 ;
			}
			f_close(&fil);
		}
		vTaskDelay(pdMS_TO_TICKS(1000));
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
			//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc1, strlen(msg_rtc1), HAL_MAX_DELAY);
			send_uart(msg_rtc1);
			show_time_date(&time);
			//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
			send_uart(msg_rtc2);

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
								//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_hh, strlen(msg_rtc_hh), HAL_MAX_DELAY);
								send_uart(msg_rtc_hh);
								break ;
							case 1:
								curr_state = sRtcDateConfig ;
								//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_dd, strlen(msg_rtc_dd), HAL_MAX_DELAY);
								send_uart(msg_rtc_dd);
								break ;
							case 2:
								curr_state = sMenu;
								send_uart(msg_menu);
								break ;
							default:
								send_uart(msg_inv);
								//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
								send_uart(msg_rtc2);
							}
						}
						else
						{
							send_uart(msg_inv);
							//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
							send_uart(msg_rtc2);
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
								//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_mm, strlen(msg_rtc_mm), HAL_MAX_DELAY);
								send_uart(msg_rtc_mm);
								break;
							}
						case MM_CONFIG:
							{
								uint8_t min = get_number(cmd->payload, cmd->len) ;
								time.minutes = min ;
								rtc_state = SS_CONFIG ;
								//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_ss, strlen(msg_rtc_ss), HAL_MAX_DELAY);
								send_uart(msg_rtc_ss);
								break;
							}

						case SS_CONFIG:
							{
								uint8_t sec = get_number(cmd->payload, cmd->len) ;
								time.seconds = sec ;
								if (!validate_rtc_information(&time))
								{
									RTC_Set_Time(&time) ;
									//HAL_UART_Transmit(&huart3,(uint8_t*)msg_conf, strlen(msg_conf), HAL_MAX_DELAY);
									send_uart(msg_conf);
									show_time_date(&time);
									curr_state = sMenu ;
									send_uart(msg_menu);
								}
								else
								{
									send_uart(msg_inv);
									curr_state = sSetting ;
									//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
									send_uart(msg_rtc2);
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
										//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_mo, strlen(msg_rtc_mo), HAL_MAX_DELAY);
										send_uart(msg_rtc_mo);
										break;
									}
								case MONTH_CONFIG:
									{
										uint8_t month = get_number(cmd->payload, cmd->len) ;
										time.month = month ;
										rtc_state = DAY_CONFIG ;
										//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_dow, strlen(msg_rtc_dow), HAL_MAX_DELAY);
										send_uart(msg_rtc_dow);
										break;
									}
								case DAY_CONFIG:
								{
									uint8_t day = get_number(cmd->payload, cmd->len) ;
									time.dayofweek = day ;
									rtc_state = YEAR_CONFIG ;
								//	HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc_yr, strlen(msg_rtc_yr), HAL_MAX_DELAY);
									send_uart(msg_rtc_yr);
									break;
								}

								case YEAR_CONFIG:
									{
										uint8_t year = get_number(cmd->payload, cmd->len) ;
										time.year = year ;
										if (!validate_rtc_information(&time))
										{
											RTC_Set_Time(&time) ;
										//	HAL_UART_Transmit(&huart3,(uint8_t*)msg_conf, strlen(msg_conf), HAL_MAX_DELAY);
											send_uart(msg_conf);
											show_time_date(&time);
											curr_state = sMenu ;
											send_uart(msg_menu);
										}
										else
										{
											 send_uart(msg_inv);
											curr_state = sSetting ;
											//HAL_UART_Transmit(&huart3,(uint8_t*)msg_rtc2, strlen(msg_rtc2), HAL_MAX_DELAY);
											send_uart(msg_rtc2);
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
	send_uart(msg_menu);
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
		case sRunOnly:
		case sRunAndSave:
		case sRun:
				xTaskNotify(handle_start_task,(uint32_t)cmd ,eSetValueWithOverwrite) ;
				break ;
		 default:
			 send_uart(msg_inv);
			 send_uart(msg_menu);

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

