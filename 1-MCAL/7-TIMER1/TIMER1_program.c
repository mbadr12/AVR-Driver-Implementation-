/*
 * TIMER1_program.c
 *
 *  Created on: May 28, 2022
 *      Author: mbadr
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_Interface.h"
#include "TIMER1_register.h"

void PWM_Init(void)
{
	TCCR1A=0x00;
	TCCR1B=0x00;
	SET_BIT(TCCR1A,1); SET_BIT(TCCR1A,7);
	SET_BIT(TCCR1B,1); SET_BIT(TCCR1B,3); SET_BIT(TCCR1B,4);
	ICR1=Top;
}

void PWM_UpdateOCR(u16 Value)
{
	OCR1A=Value;
}
