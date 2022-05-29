/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	EXTI				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*Global pointer to function to Hold INT0 ISR Address*/
void (*EXTI_pvInt0Func)(void)=NULL;

void EXTI_voidInt00Init(void)
{
	/*Check sense control*/
#if INT0_SENSE==LOW_LEVEL
	/*Set sense control for INT0 to falling edge*/
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE==ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE==FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE==RAISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong INT0_SENSE configuration option"
#endif

#if INT0_INTIAL_STATE==ENABLED
	/*Peripheral Interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INTIAL_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INTIAL_STATE configuration option"
#endif
}

void EXTI_voidInt01Init(void)
{
	/*Check sense control*/
#if INT1_SENSE==LOW_LEVEL
	/*Set sense control for INT0 to falling edge*/
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE==ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE==FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE==RAISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#else
#error "Wrong INT1_SENSE configuration option"
#endif

#if INT1_INTIAL_STATE==ENABLED
	/*Peripheral Interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);

#elif INT1_INTIAL_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT1_INTIAL_STATE configuration option"
#endif
}

void EXTI_voidInt02Init(void)
{
	/*Check sense control*/
#if INT2_SENSE==FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT2_SENSE==RAISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
#error "Wrong INT0_SENSE configuration option"
#endif

#if INT2_INTIAL_STATE==ENABLED
	/*Peripheral Interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);

#elif INT2_INTIAL_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT2_INTIAL_STATE configuration option"
#endif
}

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8sense)
{
	u8 Local_u8ErrorStatus=OK;
	switch(Copy_u8sense)
	{
	case LOW_LEVEL:    CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
	case ON_CHANGE:	   SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
	case FALLING_EDGE: CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
	case RAISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
	default: Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8sense)
{
	u8 Local_u8ErrorStatus=OK;
	switch(Copy_u8sense)
	{
	case LOW_LEVEL:    CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
	case ON_CHANGE:	   SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
	case FALLING_EDGE: CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
	case RAISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
	default: Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8sense)
{
	u8 Local_u8ErrorStatus=OK;
	switch(Copy_u8sense)
	{
	case FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
	case RAISING_EDGE: SET_BIT(MCUCSR,MCUCSR_ISC2); break;
	default: Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*Do nothing*/
	}
}
