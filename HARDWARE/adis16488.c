/*
 * adis16488.c
 *
 *  Created on: 2017年8月30日
 *      Author: LENOVO
 */

#include "adis16488.h"
#include "my_spi.h"


/***********************************************************************************************
*函数名 ：ADIS16488_IRQ_INIT
*函数功能描述 ：
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


void ADIS16488_IRQ_INIT(void)
{
	//GP6[2] IRQ
	PINMUX19 = PINMUX19 & 0xFFF0FFFF;
	PINMUX19 = PINMUX19 | 0x00080000;
}





/***********************************************************************************************
*函数名 ：ADIS_16488_INIT
*函数功能描述 ：初始化16488
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
short temp;
void ADIS_16488_INIT(void)
{
	//首先初始化SPI
	MY_SPI_INIT();

	//读16488ID
	temp = ADIS_16488_Read_ID();

}
//读单字节
short ADIS_16488_Read_ID(void)
{
	short ADIS_ID;
	SPI_CSN_L();
	MY_SPI_ReadWriteByte(0x7E);
	MY_SPI_ReadWriteByte(0x00);
	ADIS_ID = MY_SPI_ReadWriteByte(0x7E);
	ADIS_ID = ADIS_ID<<8;
	ADIS_ID = ADIS_ID | MY_SPI_ReadWriteByte(0x00);
	SPI_CSN_H();
	return ADIS_ID;
}

