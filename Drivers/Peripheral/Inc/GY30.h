/*
 * GY30.h
 *
 *  Created on: 2020年12月18日
 *      Author: hunterteaegg
 */

#ifndef PERIPHERAL_INC_GY30_H_
#define PERIPHERAL_INC_GY30_H_

#include <stdint.h>

//GY30 Slave Address
#define GY30_ADDR_L				(0x23 << 1)
#define GY30_ADDR_H				(0x5C << 1)

//GY30 Command
#define GY30_POWER_DOWN			0x00
#define GY30_POWER_ON			0x01
#define GY30_RESET				0x07

//GY30 Mode Candidate
#define GY30_CON_H_MODE			0x10
#define GY30_CON_H_MODE2		0x11
#define GY30_CON_L_MODE			0x13
#define GY30_ONETIME_H_MODE		0x20
#define GY30_ONETIME_H_MODE2	0x21
#define GY30_ONETIME_L_MODE		0x23

//GY30 Mode Selection
#define GY30_MODE				GY30_CON_H_MODE

void GY30_init(uint8_t addr);
double GY30_getData(uint8_t addr);

#endif /* PERIPHERAL_INC_GY30_H_ */
