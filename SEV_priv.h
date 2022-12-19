/**************************************/
/* Description : SEV private file     */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 2 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef SEV_PRIV_H
#define SEV_PRIV_H

#define COMMON_ANODE     0
#define COMMON_CATHODE   1


typedef struct 
{
	uint8 au8SevCon[7];
	uint8 u8Common    ;
	uint8 u8ConMode   ;
}tstrconfigSet;

extern tstrconfigSet  SEV_strConfigSet[SEV_MAX_NUM];
static void SEV_PutOnBus(uint8 u8SevIndxCpy , uint8 u8NumCpy);



#endif
