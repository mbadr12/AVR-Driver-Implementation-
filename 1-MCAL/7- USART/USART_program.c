/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	USART 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "../7- USART/BIT_MATH.h"
#include "../7- USART/STD_TYPES.h"
#include "../7- USART/USART_config.h"
#include "../7- USART/USART_interface.h"
#include "../7- USART/USART_private.h"
#include "../7- USART/USART_register.h"

static u8 USART_u8BusyState=IDLE;
static void(* USART_pvCallBackFunc)(void)=NULL;
static u16 USART_u16SentData=0;
static char* USART_pcString=NULL;
static u8 USART_u8ISRSource=0;
static u8 USART_u8CharIndex=0;
static u8 USART_u8BufferLength=0;
static char* USART_pu8Data=NULL;

void USART_voidInit(void)
{
	u8 Local_u8UCSRCValue=0;
	u16 Local_u16UBRRValue=0;
	/*Access UCSRB Value*/
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);
	/*Synchronization mode*/
#if USART_MODE==ASYNCH
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
	/*Choose Speed*/
#if TRANS_SPEED==NORMAL_SPEED
	CLR_BIT(UCSRB,UCSRA_U2X);
	Local_u16UBRRValue=(500000ul/(u32)BAUD_RATE)-1;
#elif TRANS_SPEED==DOUBLE_SPEED
	SET_BIT(UCSRB,UCSRA_U2X);
	Local_u16UBRRValue=(1000000ul/(u32)BAUD_RATE)-1;
#endif
#elif USART_MODE==SYNCH
	SET_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
	CLR_BIT(UCSRB,UCSRA_U2X);
	Local_u16UBRRValue=(4000000ul/(u32)BAUD_RATE)-1;
#else
#error "Wrong USART Mode"
#endif
	/*Parity Mode*/
	Local_u8UCSRCValue&=PARITY_MASK;
	Local_u8UCSRCValue|=PARITY_MODE;
	/*NO. of stop bits*/
#if STOP_BIT==ONE_BIT
	CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#elif STOP_BIT==TWO_BIT
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#else
#error "Wrong Stop Bit Number"
#endif
	/*set NO. of data Bits*/
#if DATA_BIT==NINE_BIT
	SET_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
#elif DATA_BIT<NINE_BIT
	Local_u8UCSRCValue&=DATA_MASK;
	Local_u8UCSRCValue|=DATA_BIT;
#else
#error "Wrong Data Bit Number"
#endif
	UCSRC = Local_u8UCSRCValue;
	/*Baud Rate*/
	UBRRL=(u8)Local_u16UBRRValue;
	UBRRH=(Local_u16UBRRValue>>8);
	/*Enable the Transmit and Receive modes*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);
}

u8 USART_voidSendCharSynch(u16 Copy_u16Data)
{
	u8 Local_u8StateError=OK;
	u32 Local_u32Counter=0;
	if(USART_u8BusyState==IDLE)
	{
		/*Make USART Busy*/
		USART_u8BusyState=BUSY;
		/*Busy Waiting For Data Register Empty*/
		while((GET_BIT(UCSRA,UCSRA_UDRE)==0) && (Local_u32Counter<USART_TIMEOUT))
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter==USART_TIMEOUT)
		{
			Local_u8StateError=NOK;
		}
		else
		{
			/*clear transmit complete flag*/
			SET_BIT(UCSRA,UCSRA_UDRE);
			/*Send Data*/
#if DATA_BIT==NINE_BIT
			UDR=(u8)Copy_u16Data;
			UCSRB|=(Copy_u16Data>>8);
			USART_u8BusyState=IDLE;
#elif DATA_BIT<NINE_BIT
			UDR=(u8)Copy_u16Data;
			USART_u8BusyState=IDLE;
#endif
		}
	}
	else
	{
		Local_u8StateError=BUSY_FUNC;
	}
	return Local_u8StateError;
}

u8 USART_voidSendCharAsynch(u16 Copy_u16Data, void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8StateError=OK;
	if(USART_u8BusyState==IDLE)
	{
		if(Copy_pvNotificationFunc==NULL)
		{
			Local_u8StateError=NULL_POINTER;
		}
		else
		{
			/*Busy Waiting For Data Register Empty*/
			USART_u8BusyState=BUSY;
			/*Configure ISR Source As Sending Character*/
			USART_u8ISRSource=SEND_CHAR;
			USART_pvCallBackFunc=Copy_pvNotificationFunc;
			USART_u16SentData=Copy_u16Data;
			/*USART Data Register Empty Interrupt Enable*/
			SET_BIT(UCSRB,UCSRB_UDRIE);
		}
	}
	return Local_u8StateError;
}
u8 USART_u8SendStringSynch(const char* Copy_pcharString)
{
	u8 Local_u8StateError=OK;
	u8 Local_u8Counter=0;
	if(Copy_pcharString==NULL)
	{
		Local_u8StateError=NULL_POINTER;
	}
	else
	{
		/*Send All Characters until the string ended*/
		while(Copy_pcharString[Local_u8Counter]!='\0')
		{
			USART_voidSendCharSynch(Copy_pcharString[Local_u8Counter]);
			Local_u8Counter++;
		}
	}
	return Local_u8StateError;
}
u8 USART_u8SendStringASynch(const char* Copy_pcharString, void(* Copy_pvNotificationFunc)(void))
{
	u8 Local_u8StateError=0;
	if(USART_u8BusyState==IDLE)
	{
		if((Copy_pcharString==NULL) || (Copy_pvNotificationFunc==NULL))
		{
			Local_u8StateError=NULL_POINTER;
		}
		else
		{
			/*Make USART Busy*/
			USART_u8BusyState=BUSY;
			/*Configure ISR Source As Sending String*/
			USART_u8ISRSource=SEND_STRING;
			/*Initialize the variables & CallBack Notification Function Globally*/
			USART_pcString=Copy_pcharString;
			USART_pvCallBackFunc=Copy_pvNotificationFunc;
			USART_u8CharIndex=0;
			/*USART Data Register Empty Interrupt Enable*/
			SET_BIT(UCSRB,UCSRB_UDRIE);
		}
	}
	else
	{
		Local_u8StateError=BUSY_FUNC;
	}
	return Local_u8StateError;
}
u8 USART_u8ReceiveCharSynch(u8 *Copy_pu8Data)
{
	u8 Local_u8StateError=OK;
	if(USART_u8BusyState==IDLE)
	{
		/*Make USART Busy*/
		USART_u8BusyState=BUSY;
		/*Busy waiting For receive Complete*/
		while(GET_BIT(UCSRA,UCSRA_RXC)==0);
		SET_BIT(UCSRA,UCSRA_RXC);
		/*Send Data*/
		*Copy_pu8Data=UDR;
		/*Make USART IDLE*/
		USART_u8BusyState=IDLE;
	}
	else
	{
		Local_u8StateError=BUSY_FUNC;
	}
	return Local_u8StateError;
}
u8 USART_u8ReceiveCharASynch(u8 *Copy_pu8Data, void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8StateError=OK;
	if(USART_u8BusyState==IDLE)
	{
		if((Copy_pu8Data==NULL) || (Copy_pvNotificationFunc==NULL))
		{
			Local_u8StateError=NULL_POINTER;
		}
		else
		{
			/*Make USART Busy*/
			USART_u8BusyState=BUSY;
			/*Configure ISR Source As Receiving Character*/
			USART_u8ISRSource=RECEIVE_CHAR;
			USART_pu8Data=Copy_pu8Data;
			USART_pvCallBackFunc=Copy_pvNotificationFunc;
			/*Receive Complete Interrupt Enable*/
			SET_BIT(UCSRB,UCSRB_RXCIE);
		}
	}
	else
	{
		Local_u8StateError=BUSY_FUNC;
	}
	return Local_u8StateError;
}

u8 USART_u8ReceiveBufferSynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize)
{
	u8 Local_u8StateError=OK;
	u8 Local_u8Counter=0;
	if(Copy_pu8Buffer==NULL)
	{
		Local_u8StateError=NULL_POINTER;
	}
	for(Local_u8Counter=0;Local_u8Counter<Copy_u8BufferSize;Local_u8Counter++)
	{
		/*Receive Buffer in Array*/
		USART_u8ReceiveCharSynch(&Copy_pu8Buffer[Local_u8Counter]);
	}
	return Local_u8StateError;
}

u8 USART_u8ReceiveBufferASynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize, void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8StateError=OK;
	if(USART_u8BusyState==IDLE)
	{
		if((Copy_pu8Buffer==NULL) || (Copy_pvNotificationFunc==NULL))
		{
			Local_u8StateError=NULL_POINTER;
		}
		else
		{
			/*Make USART Busy*/
			USART_u8BusyState=BUSY;
			/*Configure ISR Source As Receiving String*/
			USART_u8ISRSource=RECEIVE_STRING;
			/*Initialize the variables & CallBack Notification Function Globally*/
			USART_u8CharIndex=0;
			USART_pcString=Copy_pu8Buffer;
			USART_pvCallBackFunc=Copy_pvNotificationFunc;
			USART_u8BufferLength=Copy_u8BufferSize;
			/*Receive Complete Interrupt Enable*/
			SET_BIT(UCSRB,UCSRB_RXCIE);
		}
	}
	else
	{
		Local_u8StateError=BUSY_FUNC;
	}
	return Local_u8StateError;
}

void __vector_14 ( void) __attribute__((signal));
void __vector_14 (void)
{
	if(USART_u8ISRSource==SEND_CHAR)
	{
		/*Send Data*/
#if DATA_BIT==NINE_BIT_BIT
		UDR=(u8)USART_u16SentData;
		UCSRB|=(USART_u16SentData>>8);
#elif DATA_BIT<NINE_BIT
		UDR=(u8)USART_u16SentData;
#endif
		/*Make USART Busy State Idle*/
		USART_u8BusyState=IDLE;
		/*Disable USART Data Register Empty Interrupt*/
		CLR_BIT(UCSRB,UCSRB_UDRIE);
		/*Invoke the call Back Notification*/
		USART_pvCallBackFunc();
	}
	else if(USART_u8ISRSource==SEND_STRING)
	{
		UDR=USART_pcString[USART_u8CharIndex];
		USART_u8CharIndex++;
		if(USART_pcString[USART_u8CharIndex]=='\0')
		{
			/*Make USART Busy State Idle*/
			USART_u8BusyState=IDLE;
			/*Disable USART Data Register Empty Interrupt*/
			CLR_BIT(UCSRB,UCSRB_UDRIE);
			/*Invoke the call Back Notification*/
			USART_pvCallBackFunc();
		}
	}
}
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	if(USART_u8ISRSource==RECEIVE_CHAR)
	{
		*USART_pu8Data=UDR;
		/*Make USART Busy State Idle*/
		USART_u8BusyState=IDLE;
		/*Receive Complete Interrupt Disable*/
		CLR_BIT(UCSRB,UCSRB_RXCIE);
		/*Invoke the call Back Notification*/
		USART_pvCallBackFunc();
	}
	else if(USART_u8ISRSource==RECEIVE_STRING)
	{
		USART_pcString[USART_u8CharIndex]=UDR;
		USART_u8CharIndex++;
		if(USART_u8CharIndex==USART_u8BufferLength)
		{
			USART_u8BusyState=IDLE;
			/*Receive Complete Interrupt Disable*/
			CLR_BIT(UCSRB,UCSRB_RXCIE);
			/*Invoke the call Back Notification*/
			USART_pvCallBackFunc();
		}
	}
}
