/**************************************/
/* Description : SEV program file .c  */
/* Author      : Khaled Rashad          */
/* Version     : 0.1v                 */
/* Date        : 3 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"

#include "SEV.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"



tenuErrorStatus SEV_enuDisplay(uint8 u8SevIndxCpy , uint8 u8NumCpy)
{
	tenuErrorStatus enuReturnLoc = EOK ;
	uint8 au8CathodLoc[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F} ;
	
	if (u8SevIndxCpy < SEV_MAX_NUM)
	{
		if (u8NumCpy <10)
		{
			if (SEV_strConfigSet[u8SevIndxCpy].u8ConMode == COMMON_CATHODE)
			{
				SEV_PutOnBus(u8SevIndxCpy , au8CathodLoc[u8NumCpy]);
			}
			else
			{	
				SEV_PutOnBus(u8SevIndxCpy ,~au8CathodLoc[u8NumCpy] );
			}
		}
		else
		{
			enuReturnLoc = PARAM_OUT_RANGE ;
		}
	}
	else 
	{
		enuReturnLoc = PARAM_OUT_RANGE ;
	}
	
	
	return enuReturnLoc ;
}

tenuErrorStatus SEV_enuPowerOn(uint8 u8SevIndxCpy)
{
	tenuErrorStatus enuReturnLoc = EOK ;
	
	if (u8SevIndxCpy < SEV_MAX_NUM)
	{
		if (SEV_strConfigSet[u8SevIndxCpy].u8ConMode == COMMON_CATHODE)
		{
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SevIndxCpy].u8Common ,DIO_LOW);
		}
		else
		{
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SevIndxCpy].u8Common,DIO_HIGH);
		}
	}
	else 
	{
		enuReturnLoc = PARAM_OUT_RANGE ;
	}
	
	return enuReturnLoc ;
	
}

tenuErrorStatus SEV_enuPowerOff(uint8 u8SevIndxCpy)
{
	
	tenuErrorStatus enuReturnLoc = EOK ;
	
	if (u8SevIndxCpy < SEV_MAX_NUM)
	{
		if (SEV_strConfigSet[u8SevIndxCpy].u8ConMode == COMMON_ANODE)
		{
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SevIndxCpy].u8Common ,DIO_LOW);
		}
		else
		{
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SevIndxCpy].u8Common,DIO_HIGH);
		}
	}
	else 
	{
		enuReturnLoc = PARAM_OUT_RANGE ;
	}
	
	return enuReturnLoc ;
	
}

static void SEV_PutOnBus(uint8 u8SevIndxCpy , uint8 u8NumCpy)
{
	uint8 au8PinValuesLoc[7] ;
	uint8 u8CntLoc ;
	for (u8CntLoc = 0 ; u8CntLoc < 7 ; u8CntLoc++)
	{
		au8PinValuesLoc[u8CntLoc]= GET_BIT(u8NumCpy, u8CntLoc);
	}
	DIO_enuWriteGroup(SEV_strConfigSet[u8SevIndxCpy].au8SevCon,au8PinValuesLoc,7);
}
