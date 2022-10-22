/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TWI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_9_TWI_TWI_INTERFACE_H_
#define COTS_1_MCAL_9_TWI_TWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteWithAckErr,
	MasterReadByteWithoutAckErr,

}TWI_ErrStatus;

/*Pass 0 in the slave Address argument if master won't be Addressed*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif /* COTS_1_MCAL_9_TWI_TWI_INTERFACE_H_ */
