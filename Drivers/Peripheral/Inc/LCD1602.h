/*
 * lcd1602.h
 *
 *  Created on: Oct 13, 2020
 *      Author: hunterteaegg
 */

#ifndef INC_LCD1602_H_
#define INC_LCD1602_H_

#include "main.h"
#include <stm32f1xx_hal.h>

void LCD_init(void);
void LCD_write(uint8_t dat);
void LCD_writeCom(uint8_t com);
void LCD_writeData(uint8_t data);
void LCD_show_dht11(uint8_t *result);
void LCD_show_GY30(uint16_t result);
void LCD_show_SHT31(uint16_t result);
void LCD_show_bmp280_temp(uint32_t result);
void LCD_show_bmp280_press(uint32_t result);

#endif /* INC_LCD1602_H_ */
