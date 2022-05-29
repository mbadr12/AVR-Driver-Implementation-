/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	LED					*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include"STD_TYPES.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

u8 LED_u8TurnOn(LED_t* Copy_PLED_tLED)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_PLED_tLED->conn_type)
	{
	case LED_u8SourceCon: DIO_u8SetPinValue(Copy_PLED_tLED->port,Copy_PLED_tLED->pin,DIO_u8Pin_HIGH); break;
	case LED_u8SinkCon: DIO_u8SetPinValue(Copy_PLED_tLED->port,Copy_PLED_tLED->pin,DIO_u8Pin_LOW); break;
	default: Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;
}

u8 LED_u8TurnOff(LED_t* Copy_PLED_tLED)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_PLED_tLED->conn_type)
	{
	case LED_u8SourceCon: DIO_u8SetPinValue(Copy_PLED_tLED->port,Copy_PLED_tLED->pin,DIO_u8Pin_LOW); break;
	case LED_u8SinkCon: DIO_u8SetPinValue(Copy_PLED_tLED->port,Copy_PLED_tLED->pin,DIO_u8Pin_HIGH); break;
	default: Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
u8 LED_u8Toggle(LED_t* Copy_PLED_tLED)
{
	u8 Local_u8ErrorState=0;
	if(Copy_PLED_tLED->conn_type <= LED_u8SinkCon)
	{
		DIO_u8TogglePinValue(Copy_PLED_tLED->port,Copy_PLED_tLED->pin);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
