/*
 * my_spi.c
 *
 *  Created on: 2017年8月29日
 *      Author: LENOVO
 */
#include "my_spi.h"

void MY_SPI_DELAY(void)
{
	int i;
	for(i=0;i<100;i++);
}



void MY_SPI_INIT(void)
{
	//GP6[4] CS
	PINMUX19 = PINMUX19 & 0xFFFFF0FF;
	PINMUX19 = PINMUX19 | 0x00000800;

	//GP0[11] SCLK
	PINMUX0 = PINMUX0 & 0xFFF0FFFF;
	PINMUX0 = PINMUX0 | 0x00080000;

	//GP0[14] MOSI
	PINMUX0 = PINMUX0 & 0xFFFFFF0F;
	PINMUX0 = PINMUX0 | 0x00000080;

	//GP0[15] MISO
	PINMUX0 = PINMUX0 & 0xFFFFFFF0;
	PINMUX0 = PINMUX0 & 0xFFFFFFF8;

	SPI_CSN_H();			//SPIƬѡȡ��
	SPI_SCK(1);				//
	SPI_MOSI(1);
}


unsigned char MY_SPI_ReadWriteByte(unsigned char uc_data)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		MY_SPI_DELAY();
		SPI_MOSI(uc_data & 0x80);
		MY_SPI_DELAY();
		uc_data = (uc_data << 1);
		SPI_SCK(0);
		MY_SPI_DELAY();
		uc_data |= SPI_MISO_IN;
		SPI_SCK(1);
	}
	return uc_data;
}





