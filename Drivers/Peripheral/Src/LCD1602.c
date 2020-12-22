/*
 * lcd1602.c
 *
 *  Created on: Oct 13, 2020
 *      Author: hunterteaegg
 */

#include "lcd1602.h"
#include <stdbool.h>
#include "stm32f1xx_hal.h"

uint8_t CRC8_compute(const uint8_t *pdat, short len, const uint8_t factor);

static void LCD_write(uint8_t dat)
{
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, ((dat>>0)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, ((dat>>1)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, ((dat>>2)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, ((dat>>3)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, ((dat>>4)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, ((dat>>5)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, ((dat>>6)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, ((dat>>7)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
}

void LCD_writeCom(uint8_t com)
{
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RD_GPIO_Port, LCD_RD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_RESET);

	LCD_write(com);
	HAL_Delay(1);

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}

void LCD_writeData(uint8_t data)
{
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RD_GPIO_Port, LCD_RD_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_RESET);

	LCD_write(data);
	HAL_Delay(1);

	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}

void LCD_init(void)
{
	LCD_writeCom(0x38);
	LCD_writeCom(0x0c);
	LCD_writeCom(0x06);
	LCD_writeCom(0x01);
	LCD_writeCom(0X80);
}

void LCD_show_GY30(uint16_t result)
{
	LCD_writeData((result / 10000)+48);
	LCD_writeData((result % 10000 /1000)+48);
	LCD_writeData((result % 1000 / 100)+48);
	LCD_writeData((result % 100 / 10)+48);
	LCD_writeData((result % 10)+48);
	LCD_writeData('L');
	LCD_writeData('x');

	HAL_Delay(1000);
}

void LCD_show_SHT31(uint16_t temp, uint16_t humi)
{
	LCD_writeData((temp / 10000)+48);
	LCD_writeData((temp % 10000 /1000)+48);
	LCD_writeData('.');
	LCD_writeData((temp % 1000 / 100)+48);
	LCD_writeData((temp % 100 / 10)+48);
	LCD_writeData((temp % 10)+48);
	LCD_writeData(0xDF);
	LCD_writeData('C');
	LCD_writeData(' ');

	LCD_writeData((humi / 10000)+48);
	LCD_writeData((humi % 10000 /1000)+48);
	LCD_writeData('.');
	LCD_writeData((humi % 1000 / 100)+48);
	LCD_writeData((humi % 100 / 10)+48);
	LCD_writeData((humi % 10)+48);
	LCD_writeData('%');
	LCD_writeData(' ');


}

void LCD_showByte(uint8_t byte)
{
	LCD_writeData((byte / 100)+48);
	LCD_writeData((byte % 100 / 10)+48);
	LCD_writeData((byte % 10)+48);
	LCD_writeData(' ');
}

uint8_t CRC8_compute(const uint8_t *pdat, short len, const uint8_t factor)
{
    uint8_t j;
    uint8_t crc = 0xFF;

    while (len--)
    {
        crc ^= (*pdat++);
        for (j = 8; j > 0; j--)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ factor;
            }
            else
            {
                crc = (crc << 1);
            }
        }
    }

    return crc;
}
