/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	SPI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"

u8 SPI_U8BusyState=IDEL;
u8 SPI_u8SentData=0;
u8* SPI_pu8ReceivedData=NULL;
void(*SPI_pvCallBackFunc)(void)=NULL;
void SPI_voidInit(void)
{
	/*Data Order*/
#if DATA_ORDER==LSB_FIRST
	SET_BIT(SPCR,SPCR_DORD);
#elif DATA_ORDER==MSB_FIRST
	CLR_BIT(SPCR,SPCR_DORD);
#else
#error "Wrong Data Order"
#endif
	/*Master or Slave initialization*/
#if MASTER_SLAVE_SELECT==MASTER
	SET_BIT(SPCR,SPCR_MSTR);
#elif MASTER_SLAVE_SELECT==SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#error "Wrong Master/Slave Select"
#endif
	/*Clock Polarity*/
#if CLK_POLARITY==RAISING_LEADING
	CLR_BIT(SPCR,SPCR_CPOL);
#elif CLK_POLARITY==FALLING_LEADING
	SET_BIT(SPCR,SPCR_CPOL);
#else
#error "Wrong Clock Polarity"
#endif
	/*Clock Phase*/
#if CLK_PHASE==LEADING_SAMPLE
	CLR_BIT(SPCR,SPCR_CPHA);
#elif CLK_PHASE==LEADING_SETUP
	SET_BIT(SPCR,SPCR_CPHA);
#else
#error "Wrong Clock Phase"
#endif
	/*SPI Speed*/
#if SPI_SPEED==NORMAL_SPEED
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_SPEED==DOUBLE_SPEED
	SET_BIT(SPSR,SPSR_SPI2X);
#else
#error "Wrong SPI Speed"
#endif
	/*Clock prescaler*/
	SPCR&=PRE_SCALER_MASK;
	SPCR|=PRE_SCALER;
	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8TransceiveSynch(u8 Copy_u8SentData,u8* Copy_pu8RecievedData)
{
	u8 Local_u8StateError=OK;
	u32 Local_u32Counter=0;
	if(SPI_U8BusyState==IDEL)
	{
		if(Copy_pu8RecievedData==NULL)
		{
			Local_u8StateError=NULL_POINTER;
		}
		else
		{
			/*SPI Now is Busy*/
			SPI_U8BusyState=BUSY;
			/*Send the Data*/
			SPDR = Copy_u8SentData;
			/*Busy waiting until the transfer complete*/
			while((GET_BIT(SPSR,SPSR_SPIF)==0) && (Local_u32Counter<SPI_TIMEOUT))
			{
				Local_u32Counter++;
			}
			if(Local_u32Counter==SPI_TIMEOUT)
			{
				Local_u8StateError=NOK;
			}
			else
			{
				/*SPI Now Can Be Ideal*/
				SPI_U8BusyState=IDEL;
				/*Get the exchanged Data*/
				Copy_pu8RecievedData= SPDR;
			}
		}
	}
	else
	{
		Local_u8StateError=BUSY_FUNC;
	}
	return Local_u8StateError;
}
u8 SPI_u8TransceiveASynch(u8 Copy_u8SentData,u8* Copy_pu8RecievedData, void(*Copy_pvNotificationFun)(void))
{
	u8 Local_u8StateError=OK;
	if(SPI_U8BusyState==IDEL)
	{
		if((Copy_pu8RecievedData==NULL) || (Copy_pvNotificationFun==NULL))
		{
			Local_u8StateError=NULL_POINTER;
		}
		else
		{
			/*SPI Now is Busy*/
			SPI_U8BusyState=BUSY;
			/*Initialize Data and Notification Function Globally*/
			SPI_pu8ReceivedData=Copy_pu8RecievedData;
			SPI_pvCallBackFunc=Copy_pvNotificationFun;
			SPI_u8SentData=Copy_u8SentData;
			/*SPI Interrupt Enable*/
			SET_BIT(SPCR,SPCR_SPIE);
		}
	}
	else
	{
		Local_u8StateError=BUSY_FUNC;
	}
	return Local_u8StateError;
}

void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	/*Send the Data*/
	SPDR=SPI_u8SentData;
	/*Get the exchanged Data*/
	*SPI_pu8ReceivedData=SPDR;
	/*SPI Call Back Function*/
	SPI_pvCallBackFunc();
	/*SPI Now Can Be Ideal*/
	SPI_U8BusyState=IDEL;
}
