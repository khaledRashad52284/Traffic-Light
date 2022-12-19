/*
 * main.c
 *
 *  Created on: Dec 2, 2022
 *      Author: Khaled Rashad
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>

#include "DIO.h"
#include "SEV.h"

void main(void)
{

	DIO_voidInit();
	SEV_enuPowerOn(0);
	SEV_enuPowerOff(1);

	uint8 u8cntrLoc=0,u8RedCntlLoc,u8YellowCntlLoc,u8GreenCntlLoc;

	sint8 i=0,j;
	while(1)
	{
			i=4,j=1;
			LED_enuLedOn(DIO_PIN_NUM_13);//Red LED
		for(u8RedCntlLoc=0;u8RedCntlLoc<40;u8RedCntlLoc++)
		{
			j--;
			for(u8cntrLoc=0;u8cntrLoc<=10;u8cntrLoc++)
			{
				SEV_enuPowerOn(0);
				SEV_enuDisplay(0,i);
				_delay_ms(20);
				SEV_enuPowerOff(0);
				SEV_enuPowerOn(1);
				SEV_enuDisplay(1,j);
				_delay_ms(20);
				SEV_enuPowerOff(1);
			}
			if(i==0&&j==0)
			{
				break;
			}
			else if(j==0)
			{
				i--;
				j=10;
			}

		}
		LED_enuLedOff(DIO_PIN_NUM_13);
		i=2,j=1;
		LED_enuLedOn(DIO_PIN_NUM_14);//Yellow LED

	for(u8YellowCntlLoc=0;u8YellowCntlLoc<40;u8GreenCntlLoc++)
		{
			j--;
			for(u8cntrLoc=0;u8cntrLoc<=10;u8cntrLoc++)
			{
				SEV_enuPowerOn(0);
				SEV_enuDisplay(0,i);
				_delay_ms(20);
				SEV_enuPowerOff(0);
				SEV_enuPowerOn(1);
				SEV_enuDisplay(1,j);
				_delay_ms(20);
				SEV_enuPowerOff(1);
			}
			if(i==0&&j==0)
			{
				break;
			}
			else if(j==0)
			{
				i--;
				j=10;
			}
		}
	LED_enuLedOff(DIO_PIN_NUM_14);
	i=3,j=1;
	LED_enuLedOn(DIO_PIN_NUM_15);//Green LED

	for(u8YellowCntlLoc=0;u8YellowCntlLoc<10;u8GreenCntlLoc++)
		{
			j--;
			for(u8cntrLoc=0;u8cntrLoc<=25;u8cntrLoc++)
			{
				SEV_enuPowerOn(0);
				SEV_enuDisplay(0,i);
				_delay_ms(20);
				SEV_enuPowerOff(0);
				SEV_enuPowerOn(1);
				SEV_enuDisplay(1,j);
				_delay_ms(20);
				SEV_enuPowerOff(1);
			}
			if(i==0&&j==0)
			{
				break;
			}
			else if(j==0)
			{
				i--;
				j=10;
			}
		}
	LED_enuLedOff(DIO_PIN_NUM_15);




}
}
