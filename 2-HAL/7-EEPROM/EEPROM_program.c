/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL				    *************************/
/*************************		SWC: 	EEPROM 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../../1-MCAL/9-TWI/TWI_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"

void EEPROM_voidSendDataByte(u8 Copy_u8DataByte , u16 Copy_u16Address)
{
	u8 Local_u8SlaveAddress=0;
	/*Start TWI*/
	TWI_SendStartCondition();
	/*Calculate The slave Address and Send The 2 MSB of Address*/
	Local_u8SlaveAddress=(0b01010000)|(A2_CONNECTION<<2)|(Copy_u16Address>>8);
	TWI_SendSlaveAddressWithWrite(Local_u8SlaveAddress);
	/*Send The 8 LSB of Address*/
	TWI_MasterWriteDataByte((u8) Copy_u16Address);
	/*Send The Data To EEPROM*/
	TWI_MasterWriteDataByte(Copy_u8DataByte);
	/*End TWI*/
	TWI_SendStopCondition();
}

void EEPROM_voidReadDataByte(u8 *Copy_pu8DataByte , u16 Copy_u16Address)
{
	u8 Local_u8SlaveAddress=0;
	/*Start TWI*/
	TWI_SendStartCondition();
	/*Calculate The slave Address and Send The 2 MSB of Address*/
	Local_u8SlaveAddress=(0b01010000)|(A2_CONNECTION<<2)|(Copy_u16Address>>8);
	TWI_SendSlaveAddressWithWrite(Local_u8SlaveAddress);
	/*Send The 8 LSB of Address*/
	TWI_MasterWriteDataByte((u8) Copy_u16Address);
	/*Start TWI again to Read Data from EEPROM*/
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(Local_u8SlaveAddress);
	/*Read Data From EEPROM*/
	TWI_MasterReadDataByte(Copy_pu8DataByte);
	/*End TWI*/
	TWI_SendStopCondition();
}
