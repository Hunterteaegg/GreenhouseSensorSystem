/*
 * HC-05.c
 *
 *  Created on: Dec 22, 2020
 *      Author: hunterteaegg
 */

#include <string.h>
#include "HC-05.h"
#include "stm32f1xx_hal.h"

extern UART_HandleTypeDef huart2;
static char *uartEnd = "\r\n";

void HC05_transmit(char *pdata,int len)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)pdata, len, 0xFF);
	HAL_UART_Transmit(&huart2, (uint8_t*)uartEnd, strlen(uartEnd), 0xFF);	//transmit blank characters to end transmission
}
