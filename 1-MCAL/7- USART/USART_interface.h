/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	USART 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_7__USART_USART_INTERFACE_H_
#define COTS_1_MCAL_7__USART_USART_INTERFACE_H_

void USART_voidInit(void);

u8 USART_voidSendCharSynch(u16 Copy_u16Data);

u8 USART_voidSendCharAsynch(u16 Copy_u16Data, void (*Copy_pvNotificationFunc)(void));

u8 USART_u8SendStringSynch(const char* Copy_pcharString);

u8 USART_u8SendStringASynch(const char* Copy_pcharString, void(* Copy_pvNotificationFunc)(void));

u8 USART_u8ReceiveCharSynch(u8 *Copy_pu8Data);

u8 USART_u8ReceiveCharASynch(u8 *Copy_pu8Data, void (*Copy_pvNotificationFunc)(void));

u8 USART_u8ReceiveBufferSynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize);

u8 USART_u8ReceiveBufferASynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize, void (*Copy_pvNotificationFunc)(void));

#endif /* COTS_1_MCAL_7__USART_USART_INTERFACE_H_ */
