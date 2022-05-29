/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	SSD					*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

u8 SSD_u8SSDArrCC[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
u8 SSD_u8SetNumber(SSD_t* Copy_PSSD_tSSD , u8 copy_u8Number)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_PSSD_tSSD->com_type)
	{
	case SSD_u8COM_CATHOD: DIO_u8SetPortValue(Copy_PSSD_tSSD->port , SSD_u8SSDArrCC[copy_u8Number]);
	DIO_u8SetPinValue(Copy_PSSD_tSSD->Enable_Port , Copy_PSSD_tSSD->Enable_Pin ,DIO_u8Pin_LOW); break;
	case SSD_u8COM_ANOD: DIO_u8SetPortValue(Copy_PSSD_tSSD->port , (~SSD_u8SSDArrCC[copy_u8Number]));
	DIO_u8SetPinValue(Copy_PSSD_tSSD->Enable_Port , Copy_PSSD_tSSD->Enable_Pin ,DIO_u8Pin_HIGH); break;
	default: Local_u8ErrorState=1; break;
	}

	return Local_u8ErrorState;
}

u8 SSD_u8ComStateControl(SSD_t* Copy_PSSD_tSSD , u8 Copy_u8Comstate)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Comstate == SSD_u8COM_ENABLE)
	{
		switch(Copy_PSSD_tSSD->com_type)
		{
		case SSD_u8COM_CATHOD: DIO_u8SetPinValue(Copy_PSSD_tSSD->Enable_Port , Copy_PSSD_tSSD->Enable_Pin ,DIO_u8Pin_LOW); break;
		case SSD_u8COM_ANOD: DIO_u8SetPinValue(Copy_PSSD_tSSD->Enable_Port , Copy_PSSD_tSSD->Enable_Pin ,DIO_u8Pin_HIGH); break;
		default: Local_u8ErrorState=1;
		}
	}
	else if(Copy_u8Comstate == SSD_u8COM_DISABLE)
	{
		switch(Copy_PSSD_tSSD->com_type)
		{
		case SSD_u8COM_CATHOD: DIO_u8SetPinValue(Copy_PSSD_tSSD->Enable_Port , Copy_PSSD_tSSD->Enable_Pin ,DIO_u8Pin_HIGH); break;
		case SSD_u8COM_ANOD: DIO_u8SetPinValue(Copy_PSSD_tSSD->Enable_Port , Copy_PSSD_tSSD->Enable_Pin ,DIO_u8Pin_LOW); break;
		default: Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;
}
