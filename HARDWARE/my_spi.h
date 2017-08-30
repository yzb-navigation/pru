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

#define SPI_CSN_H()		GPIOPinWrite(SOC_GPIO_0_REGS, 101, GPIO_PIN_HIGH)
#define SPI_CSN_L()		GPIOPinWrite(SOC_GPIO_0_REGS, 101, GPIO_PIN_LOW)



#define SPI_SCK(a)  if (a) GPIOPinWrite(SOC_GPIO_0_REGS, 12, GPIO_PIN_HIGH);  else GPIOPinWrite(SOC_GPIO_0_REGS, 12, GPIO_PIN_HIGH);

#define SPI_MOSI(a) if (a) GPIOPinWrite(SOC_GPIO_0_REGS, 15, GPIO_PIN_HIGH);  else GPIOPinWrite(SOC_GPIO_0_REGS, 15, GPIO_PIN_HIGH);

#define SPI_MISO_IN GPIOPinRead(SOC_GPIO_0_REGS,16);


void MY_SPI_DELAY(void);
void MY_SPI_INIT(void);
unsigned char MY_SPI_ReadWriteByte(unsigned char uc_data);


#endif /* HARDWARE_MY_SPI_H_ */
