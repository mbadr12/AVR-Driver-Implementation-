/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	CLCD				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendString(const char* Copy_Pcstring);

void CLCD_void_SendNumber(s8* Copy_ps8String , s32 Copy_s32Number);

void CLCD_voidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos);

void CLCD_void_Init(void);

void CLCD_voidCLR(void);

void CLCD_void_WriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos);

#endif
