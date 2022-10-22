/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TWI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*Set CLK Frequency to 400 Kbps*/
	/*Set TWBR*/
	TWBR=2;
	/*Clear the 2 bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	/*Initialize the node Address*/
	if(Copy_u8SlaveAddress!=0)
	{
		TWAR=(Copy_u8SlaveAddress<<1);
	}
	/*TWI Enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Initialize the node Address*/
	TWAR=(Copy_u8SlaveAddress<<1);
	/*TWI Enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrorStatus;
	/*Send Start Condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/*Clear the Interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*Busy waiting until the Interrupt Flag Is Raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	/*check Operation Status in the Status Register*/
	if((TWSR & TWSR_Mask)!=START_ACK)
	{
		Local_ErrorStatus=StartConditionErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Local_ErrorStatus;
	/*Send Start Condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/*Clear the Interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*Busy waiting until the Interrupt Flag Is Raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	/*check Operation Status in the Status Register*/
	if((TWSR & TWSR_Mask)!=REP_START_ACK)
	{
		Local_ErrorStatus=RepeatedStartErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	/*Set the Slave Address in the 7 MSB in Data Register*/
	TWDR=(Copy_u8SlaveAddress<<1);
	/*for write Request*/
	CLR_BIT(TWDR,0);
	/*Clear the Interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*Busy waiting until the Interrupt Flag Is Raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	/*check Operation Status in the Status Register*/
	if((TWSR & TWSR_Mask)!=SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorStatus=SlaveAddressWithWriteErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	/*Set the Slave Address in the 7 MSB in Data Register*/
	TWDR=(Copy_u8SlaveAddress<<1);
	/*for Read Request*/
	SET_BIT(TWDR,0);
	/*Clear the Interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*Busy waiting until the Interrupt Flag Is Raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	/*check Operation Status in the Status Register*/
	if((TWSR & TWSR_Mask)!=SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorStatus=SlaveAddressWithReadErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	/*Write The Data Byte*/
	TWDR=Copy_u8DataByte;
	/*Clear the Interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*Busy waiting until the Interrupt Flag Is Raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	/*check Operation Status in the Status Register*/
	if((TWSR & TWSR_Mask)!=MSTR_WR_BYTE_ACK)
	{
		Local_ErrorStatus=MasterWriteByteErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	if(Copy_pu8DataByte==NULL)
	{
		Local_ErrorStatus=NULL_POINTER;
	}
	else
	{
		/*Enable Master Generating Acknowledge bit after Receiving Data*/
		SET_BIT(TWCR,TWCR_TWEA);
		/*Clear the Interrupt Flag to Start the previous operation*/
		SET_BIT(TWCR,TWCR_TWINT);
		/*Busy waiting until the Interrupt Flag Is Raised*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
		/*check Operation Status in the Status Register*/
		if((TWSR & TWSR_Mask)!=MSTR_RD_BYTE_WITH_ACK)
		{
			Local_ErrorStatus=MasterReadByteWithAckErr;
		}
		else
		{
			/*Read The Received Data*/
			*Copy_pu8DataByte=TWDR;
		}
	}
	return Local_ErrorStatus;
}

void TWI_SendStopCondition(void)
{
	/*Generate Stop Condition on the Bus*/
	SET_BIT(TWCR,TWCR_TWSTO);
	/*Clear the Interrupt Flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
}
