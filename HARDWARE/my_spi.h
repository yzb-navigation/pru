/*
 * my_spi.h
 *
 *  Created on: 2017Äê8ÔÂ29ÈÕ
 *      Author: LENOVO
 */

#ifndef HARDWARE_MY_SPI_H_
#define HARDWARE_MY_SPI_H_


#include "gpio.h"
#include "omapl138addr.h"
#include "soc_OMAPL138.h"




volatile register unsigned int __R30;
volatile register unsigned int __R31;


//PRU0_R30[8]   CS
#define SPI_CSN_H()		__R30 = __R30  |  0x00000100
#define SPI_CSN_L()		__R30 = __R30 & 0xFFFFFEFF


//PRU0_R30[12]     SCLK
#define SPI_SCK(a)  if (a) __R30 = __R30  |  0x00001000;  else __R30 = __R30 & 0xFFFFEFFF;

//PRU0_R30[10]  MOSI
#define SPI_MOSI(a)  if (a) __R30 = __R30  |  0x00000400;  else __R30 = __R30 & 0xFFFFFBFF;

//PRU0_R31[11] MISO
#define SPI_MISO_IN ((__R31>>11) | 0x01)


void MY_SPI_DELAY(void);
void MY_SPI_INIT(void);
unsigned char MY_SPI_ReadWriteByte(unsigned char uc_data);


#endif /* HARDWARE_MY_SPI_H_ */
