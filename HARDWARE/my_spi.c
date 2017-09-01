/*
 * my_spi.c
 *
 *  Created on: 2017年8月29日
 *      Author: LENOVO
 */
#include "my_spi.h"


/***********************************************************************************************
*函数名 ：MY_SPI_DELAY
*函数功能描述 ：模拟SPI延时
*函数参数 ：无
*函数返回值 ：无
*作者 ：yzb
*函数创建日期 ：2017.8.30
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：
*历史版本 ：
***********************************************************************************************/


void MY_SPI_DELAY(void)
{
	int i;
	for(i=0;i<100;i++);
}

/***********************************************************************************************
*函数名 ：MY_SPI_INIT
*函数功能描述 ：模拟SPI的GPIO初始化
*函数参数 ：无
*函数返回值 ：无
*作者 ：yzb
*函数创建日期 ：2017.8.30
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：
*历史版本 ：
***********************************************************************************************/


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

	SPI_CSN_H();
	SPI_SCK(1);
	SPI_MOSI(1);
}

/***********************************************************************************************
*函数名 ：MY_SPI_ReadWriteByte
*函数功能描述 ：模拟一个读写8位的SPI时序
*函数参数 ：要写的数据
*函数返回值 ：读出的数据
*作者 ：yzb
*函数创建日期 ：2017.8.30
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：
*历史版本 ：
***********************************************************************************************/

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





