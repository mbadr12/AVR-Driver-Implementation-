/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	SPI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_8__SPI_SPI_INTERFACE_H_
#define COTS_1_MCAL_8__SPI_SPI_INTERFACE_H_

void SPI_voidInit(void);

u8 SPI_u8TransceiveSynch(u8 Copy_u8SentData,u8* Copy_pu8RecievedData);

u8 SPI_u8TransceiveASynch(u8 Copy_u8SentData,u8* Copy_pu8RecievedData, void(*Copy_pvNotificationFun)(void));

#endif /* COTS_1_MCAL_8__SPI_SPI_INTERFACE_H_ */
