/*
 * SHT31.h
 *
 *  Created on: Dec 18, 2020
 *      Author: hunterteaegg
 */

#ifndef PERIPHERAL_INC_SHT31_H_
#define PERIPHERAL_INC_SHT31_H_

#include "stdint.h"

#define SHT31_SINGLESHOT_MODE		0x01
#define SHT31_PERIODIC_MODE			0x02
#define SHT31_MODE					SHT31_SINGLESHOT_MODE

#define SHT31_SLAVE_ADDRESS			(0x44 << 1)

//SHT31 Single_Shot Mode Command
#define SHT31_COM_CS                0x2C    //Clock stretching (MSB)
#define SHT31_COM_CS_H              0x06    //Clock stretching with high repeatability
#define SHT31_COM_CS_M              0x0D    //Clock stretching with medium repeatability
#define SHT31_COM_CS_L              0x10    //Clock stretching with low repeatability
#define SHT31_COM_N_CS              0x24    //non-Clock stretching (MSB)
#define SHT31_COM_N_CS_H            0x00    //non-Clock stretching with high repeatability
#define SHT31_COM_N_CS_M            0x0B    //non-Clock stretching with medium repeatability
#define SHT31_COM_N_CS_L            0x16    //non-Clock stretching with low repeatability

//SHT31 Periodic Data Acquisition Mode Command
#define SHT31_COM_0_5               0x20    //0.5 mps (MSB)
#define SHT31_COM_0_5_H             0x32    //0.5 mps with high repeatability
#define SHT31_COM_0_5_M             0x24    //0.5 mps with medium repeatability
#define SHT31_COM_0_5_L             0x2F    //0.5 mps with low repeatability
#define SHT31_COM_1                 0x21    //1 mps (MSB)
#define SHT31_COM_1_H               0x30
#define SHT31_COM_1_M               0x26
#define SHT31_COM_1_L               0x2D
#define SHT31_COM_2                 0x22    //2 mps (MSB)
#define SHT31_COM_2_H               0x36
#define SHT31_COM_2_M               0x20
#define SHT31_COM_2_L               0x2B
#define SHT31_COM_4                 0x23    //4 mps (MSB)
#define SHT31_COM_4_H               0x34
#define SHT31_COM_4_M               0x22
#define SHT31_COM_4_L               0x29
#define SHT31_COM_10                0x27    //10 mps (MSB)
#define SHT31_COM_10_H              0x37
#define SHT31_COM_10_M              0x21
#define SHT31_COM_10_L              0x2A
#define SHT31_COM_FETCH_DATA_M      0xE0    //fetch data command (MSB)
#define SHT31_COM_FETCH_DATA_L      0x00    //fetch data command (LSB)
#define SHT31_COM_ART_M             0x2B    //ART command (MSB)
#define SHT31_COM_ART_L             0x32    //ART command (LSB)

//SHT31 Control Command
#define SHT31_COM_BREAK_M           0x30    //break Command (MSB)
#define SHT31_COM_BREAK_L           0x93    //break Command (LSB)
#define SHT31_COM_RESET_M           0x30    //reset Command (MSB)
#define SHT31_COM_RESET_L           0xA2    //reset Command (LSB)

typedef struct {
	double temp;
	double humi;
} SHT31_DATA_T;

/*
void SHT31_init(void);
SHT31_DATA_T SHT31_readData(void);
void SHT31_deinit(void);
*/

#endif /* PERIPHERAL_INC_SHT31_H_ */
