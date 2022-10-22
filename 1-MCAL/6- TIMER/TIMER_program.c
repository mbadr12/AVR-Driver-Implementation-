/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

static void (*TIMERS_pvCallBackFunc[8]) (void)={NULL};

void TIMER0_voidInit(void)
{
	/*choose Wave Generation Mode*/
#if TIMER0_GENERATION_MODE == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	/*Over Flow Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_TOIE0);
#elif TIMER0_GENERATION_MODE == TIMER0_PWM_PHASE_CORRECT_MODE
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#elif TIMER0_GENERATION_MODE == TIMER0_CTC_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
#elif TIMER0_GENERATION_MODE == TIMER0_FAST_PWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
#else
#error "Wrong Generation mode"
#endif
	/*Compare match output mode*/
	TCCR0&=COMP_OPMODE_MASK;
	TCCR0|=TIMER0_COMPARE_OUTPUT_MODE;
	/*Prescaler*/
	TCCR0&=TIMER_PRESCALER_MASK;
	TCCR0|=TIMER0_PRESCALER;
}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMERS_pvCallBackFunc[1]!=NULL)
	{
		TIMERS_pvCallBackFunc[1]();
	}
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(TIMERS_pvCallBackFunc[0]!=NULL)
	{
		TIMERS_pvCallBackFunc[0]();
	}
}

void TIMER1_voidInit(void)
{
	/*Choose Waveform Generation Mode*/
	TCCR1A&=TIMER1_WAVE_MODE_MASK_TCCR1A;
	TCCR1B&=TIMER1_WAVE_MODE_MASK_TCCR1B;
	TCCR1A|=(TIMER1_GENERATION_MODE&TIMER1_WGM10_WGM11_MASK);
	TCCR1B|=((TIMER1_GENERATION_MODE&TIMER1_WGM12_WGM13_MASK)<<1);
	/*Compare Output Mode for Channel A*/
	TCCR1A&=COMP_OPMODE_CHANA_MASK;
	TCCR1A|=(TIMER1_COMPARE_OUTPUT_MODE<<TCCR1A_COM1A0);
	/*Compare Output Mode for Channel B*/
	TCCR1A&=COMP_OPMODE_CHANB_MASK;
	TCCR1A|=(TIMER1_COMPARE_OUTPUT_MODE<<TCCR1A_COM1B0);
#if TIMER1_GENERATION_MODETIMER1_GENERATION_MODE==TIMER1_NORMAL_MODE
	/*Overflow Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_TOIE1);
#elif TIMER1_GENERATION_MODETIMER1_GENERATION_MODE==CTC_OCR1A_MODE
	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE1A);
	SET_BIT(TIMSK,TIMSK_OCIE1B);
#elif TIMER1_GENERATION_MODETIMER1_GENERATION_MODE==CTC_ICR1_MODE
	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE1A);
	SET_BIT(TIMSK,TIMSK_OCIE1B);
#endif
	/*Prescaler*/
	TCCR1B&=TIMER_PRESCALER_MASK;
	TCCR1B|=TIMER1_PRESCALER;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1=Copy_u16Value;
}

u16 TIMER1_u16GetTimerValue(void)
{
	return TCNT1;
}

void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value)
{
	OCR1A=Copy_u16Value;
}

void TIMER1_voidSetChannelBCompMatchValue(u16 Copy_u16Value)
{
	OCR1B=Copy_u16Value;
}

void ICU_voidInit(void)
{
	/*Set Trigger Source to raising Edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	/*Enable Input Capture Interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorStatus=OK;
	switch(Copy_u8Edge)
	{
	case ICU_RaisingEdge: SET_BIT(TCCR1B,TCCR1B_ICES1); break;
	case ICU_FallingEdge: CLR_BIT(TCCR1B,TCCR1B_ICES1); break;
	default: Local_u8ErrorStatus=NOK; break;
	}
	return Local_u8ErrorStatus;
}

u8 TIMER_u8EnableInterrupt(u8 Copy_u8ChannelID,u8 Copy_u8InterruptID)
{
	u8 Local_u8ErrorStatus=OK;
	switch(Copy_u8ChannelID)
	{
	case TIMER0:
		switch(Copy_u8InterruptID)
		{
		case OVERFLOW_INT: SET_BIT(TIMSK,TIMSK_TOIE0); break;
		case CTC_INT: SET_BIT(TIMSK,TIMSK_OCIE0); break;
		default: Local_u8ErrorStatus=NOK; break;
		}break;
		case TIMER1:
			switch(Copy_u8InterruptID)
			{
			case OVERFLOW_INT: SET_BIT(TIMSK,TIMSK_TOIE1); break;
			case CTC_INT: SET_BIT(TIMSK,TIMSK_OCIE1A); SET_BIT(TIMSK,TIMSK_OCIE1B); break;
			case ICU_INT: SET_BIT(TIMSK,TIMSK_TICIE1); break;
			default: Local_u8ErrorStatus=NOK; break;
			}break;
			case TIMER2:
				switch(Copy_u8InterruptID)
				{
				case OVERFLOW_INT: SET_BIT(TIMSK,TIMSK_TOIE2); break;
				case CTC_INT: SET_BIT(TIMSK,TIMSK_OCIE2); break;
				default: Local_u8ErrorStatus=NOK; break;
				}break;
	}
	return Local_u8ErrorStatus;
}

u8 TIMER_u8DisableInterrupt(u8 Copy_u8ChannelID,u8 Copy_u8InterruptID)
{
	u8 Local_u8ErrorStatus=OK;
	switch(Copy_u8ChannelID)
	{
	case TIMER0:
		switch(Copy_u8InterruptID)
		{
		case OVERFLOW_INT: CLR_BIT(TIMSK,TIMSK_TOIE0); break;
		case CTC_INT: CLR_BIT(TIMSK,TIMSK_OCIE0); break;
		default: Local_u8ErrorStatus=NOK; break;
		}break;
		case TIMER1:
			switch(Copy_u8InterruptID)
			{
			case OVERFLOW_INT: CLR_BIT(TIMSK,TIMSK_TOIE1); break;
			case CTC_INT: CLR_BIT(TIMSK,TIMSK_OCIE1A); SET_BIT(TIMSK,TIMSK_OCIE1B); break;
			case ICU_INT: CLR_BIT(TIMSK,TIMSK_TICIE1); break;
			default: Local_u8ErrorStatus=NOK; break;
			}break;
			case TIMER2:
				switch(Copy_u8InterruptID)
				{
				case OVERFLOW_INT: CLR_BIT(TIMSK,TIMSK_TOIE2); break;
				case CTC_INT: CLR_BIT(TIMSK,TIMSK_OCIE2); break;
				default: Local_u8ErrorStatus=NOK; break;
				}break;
	}
	return Local_u8ErrorStatus;
}

void TIMER1_voidSetICR1Value(u16 Copy_u16Value)
{
	ICR1=Copy_u16Value;
}

u16 ICU_u16ReadInputCaputre(void)
{
	return ICR1;
}
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if(TIMERS_pvCallBackFunc[3]!=NULL)
	{
		TIMERS_pvCallBackFunc[3]();
	}
}

void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if(TIMERS_pvCallBackFunc[4]!=NULL)
	{
		TIMERS_pvCallBackFunc[4]();
	}
}

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if(TIMERS_pvCallBackFunc[2]!=NULL)
	{
		TIMERS_pvCallBackFunc[2]();
	}
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMERS_pvCallBackFunc[5]!=NULL)
	{
		TIMERS_pvCallBackFunc[5]();
	}
}

void TIMER2_voidInit(void)
{
	/*choose Wave Generation Mode*/
#if TIMER2_GENERATION_MODE == TIMER2_NORMAL_MODE
	CLR_BIT(TCCR2,TCCR2_WGM21);
	CLR_BIT(TCCR2,TCCR2_WGM20);
	/*Overflow Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_TOIE2);
#elif TIMER2_GENERATION_MODE == TIMER2_PWM_PHASE_CORRECT_MODE
	SET_BIT(TCCR2,TCCR0_WGM20);
	CLR_BIT(TCCR2,TCCR0_WGM21);
#elif TIMER2_GENERATION_MODE == TIMER2_CTC_MODE
	SET_BIT(TCCR2,TCCR0_WGM21);
	CLR_BIT(TCCR2,TCCR0_WGM20);
	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE2);
#elif TIMER2_GENERATION_MODE == TIMER2_FAST_PWM_MODE
	SET_BIT(TCCR2,TCCR0_WGM21);
	SET_BIT(TCCR2,TCCR0_WGM20);
#else
#error "Wrong Generation mode"
#endif
	/*Compare match output mode*/
	TCCR2&=COMP_OPMODE_MASK;
	TCCR2|=TIMER2_COMPARE_OUTPUT_MODE;
	/*Prescaler*/
	TCCR0&=TIMER_PRESCALER_MASK;
	TCCR0|=TIMER0_PRESCALER;
}

void TIMER2_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR2=Copy_u8Value;
}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if(TIMERS_pvCallBackFunc[7]!=NULL)
	{
		TIMERS_pvCallBackFunc[7]();
	}
}

void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if(TIMERS_pvCallBackFunc[6]!=NULL)
	{
		TIMERS_pvCallBackFunc[6]();
	}
}
u8 TIMER_u8SetCallBack(void (* Copy_pvCallBackFunc) (void),u8 Copy_u8ChannelID)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvCallBackFunc!=NULL)
	{
		/*pass The pointer to local function to global pointer to function to be called in ISR*/
		TIMERS_pvCallBackFunc[Copy_u8ChannelID]=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}
void Servo_vRotate(u8 Copy_u8Rotationdegree,u8 Copy_u8Channel)
{
	u16 Local_u16OCR1Value=0;
	/*Choose FBWM with ICR1 Top*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	/*Prescaler Division by 8*/
	TCCR1B&=TIMER_PRESCALER_MASK;
	TCCR1B|=DIV_BY_8;
	/*total time 20 ms*/
	TIMER1_voidSetICR1Value(20000);
	Local_u16OCR1Value=Copy_u8Rotationdegree*11+600;
	if(Copy_u8Channel==SERVO_CHANNEL1)
	{
		/*Compare Output Mode: Clear OC1A on compare match, set OC1A at TOP*/
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		TIMER1_voidSetChannelACompMatchValue(Local_u16OCR1Value);
	}
	else if(Copy_u8Channel==SERVO_CHANNEL2)
	{
		/*Compare Output Mode: Clear OC1B on compare match, set OC1B at TOP*/
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		CLR_BIT(TCCR1A,TCCR1A_COM1B0);
		TIMER1_voidSetChannelBCompMatchValue(Local_u16OCR1Value);
	}
}
