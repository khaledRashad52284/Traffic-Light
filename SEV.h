/**************************************/
/* Description : SEV interface file   */
/* Author      : Khaled Rashad           */
/* Version     : 0.1v                 */
/* Date        : 2 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef SEV_H
#define SEV_H

tenuErrorStatus SEV_enuDisplay(uint8 u8SevIndxCpy , uint8 u8NumCpy);
tenuErrorStatus SEV_enuPowerOn(uint8 u8SevIndxCpy);
tenuErrorStatus SEV_enuPowerOff(uint8 u8SevIndxCpy);


#endif
