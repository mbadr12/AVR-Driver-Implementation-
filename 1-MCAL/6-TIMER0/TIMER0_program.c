/*
 * Timer0_program.c
 *
 *  Created on: May 21, 2022
 *      Author: mbadr
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER0_Interface.h"
#include "TIMER0_Register.h"
void (*callback)(void)=NULL;
void TIMER0_voidInit(TIMER0_CFG *TIMER_cfg,void (*ptr)(void))
{
	TCCR0=0x00;
	TCCR0|=TIMER_cfg->Prescaler;
	TCNT0|=TIMER_cfg->Prelaod;
	switch(TIMER_cfg->Modes)
	{
	case OVF_MODE: CLR_BIT(TCCR0,3); CLR_BIT(TCCR0,6); SET_BIT(TCCR0,7); break;
	case CTC_MODE: CLR_BIT(TCCR0,3); SET_BIT(TCCR0,6); SET_BIT(TCCR0,7); OCR0=TIMER_cfg->CompareValue; break;
	case FAST_PWM_MODE: SET_BIT(TCCR0,3); SET_BIT(TCCR0,6); CLR_BIT(TCCR0,7); break;
	}
	TCCR0|=(TIMER_cfg->OC0<<4);
	TIMSK|=TIMER_cfg->IE;
	callback=ptr;
}
void TIMER0_voidStop(void)
{
	TCCR0=0x00;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(callback!=NULL)
	{
		callback();
	}
	else
	{
		/*Do Nothing*/
	}
}
