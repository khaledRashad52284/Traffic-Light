/**************************************/
/* Description : SEV program file .c  */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 3 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"

#include "LED.h"
#include "LED_cfg.h"
#include "LED_priv.h"


tenuErrorStatus LED_enuLedOn(uint8 u8PinNumCpy)
{
	tenuErrorStatus enuReturnLoc = EOK ;

	if(u8ConnectTypeGLOB==SOURCE)
	{
		DIO_enuWritePin(u8PinNumCpy,LED_LOW);

	}
	else if (u8ConnectTypeGLOB==SINK)
	{
		DIO_enuWritePin(u8PinNumCpy,LED_HIGH);

	}
	else
	{
		enuReturnLoc = PARAM_OUT_RANGE ;
	}
	
}
tenuErrorStatus LED_enuLedOff(uint8 u8PinNumCpy)
{
	tenuErrorStatus enuReturnLoc = EOK ;

	if(u8ConnectTypeGLOB==SOURCE)
	{
		DIO_enuWritePin(u8PinNumCpy,LED_HIGH);

	}
	else if (u8ConnectTypeGLOB==SINK)
	{
		DIO_enuWritePin(u8PinNumCpy,LED_LOW);

	}
	else
	{
		enuReturnLoc = PARAM_OUT_RANGE ;
	}
}


