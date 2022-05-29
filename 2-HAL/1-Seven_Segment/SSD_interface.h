/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	SSD					*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_

#define SSD_u8COM_CATHOD  0
#define SSD_u8COM_ANOD    1

#define SSD_u8COM_ENABLE  1
#define SSD_u8COM_DISABLE 0

#define GROUND            8
#define VCC               9

typedef struct
{
	u8 com_type;
	u8 port;
	u8 Enable_Port;
	u8 Enable_Pin;
}SSD_t;

u8 SSD_u8SetNumber(SSD_t* Copy_PSSD_tSSD , u8 copy_u8Number);

u8 SSD_u8ComStateControl(SSD_t* Copy_PSSD_tSSD , u8 Copy_u8Comstate);

#endif
