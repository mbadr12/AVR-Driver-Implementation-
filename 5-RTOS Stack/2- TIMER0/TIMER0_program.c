/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  RTOS Stack		    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_register.h"

static void (*TIMER0_pvCompCallBackFunc) (void)={NULL};

void TIMER0_voidInit(void)
{
	/*choose Wave Generation Mode*/
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	OCR0 = TIMER0_COMP_MATCH_VALUE;
	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
	/*Prescaler*/
	TCCR0&=TIMER_PRESCALER_MASK;
	TCCR0|=TIMER0_PRESCALER;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCompCallBackFunc!=NULL)
	{
		TIMER0_pvCompCallBackFunc();
	}
}

u8 TIMER_u8SetCallBack(void (* Copy_pvCallBackFunc) (void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvCallBackFunc!=NULL)
	{
		/*pass The pointer to local function to global pointer to function to be called in ISR*/
		TIMER0_pvCompCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}