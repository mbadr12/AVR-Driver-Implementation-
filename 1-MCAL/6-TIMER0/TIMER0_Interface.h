/*
 * TIMER0_Interface.h
 *
 *  Created on: May 21, 2022
 *      Author: mbadr
 */

#ifndef COTS_1_MCAL_6_TIMER0_TIMER0_INTERFACE_H_
#define COTS_1_MCAL_6_TIMER0_TIMER0_INTERFACE_H_

typedef enum
{
	NO_PRE_SCALER=1,
	PRE_8,
	PRE_64,
	PRE_256,
	PRE_1024
}TIMER0_Prescaler;

typedef enum
{
	OVF_MODE=0,
	CTC_MODE,
	FAST_PWM_MODE
}TIMER0_MODES;

typedef enum
{
	POLLING=0,
	OVF_IE,
	CTC_IE,
}TIMER0_IE;

typedef enum
{
	DISCONNECT=0,
	TOGGLE,
	CLEAR,
	SET
}TIMER0_OC0;

typedef struct
{
	TIMER0_MODES Modes;
	TIMER0_Prescaler Prescaler;
	TIMER0_IE IE;
	TIMER0_OC0 OC0;
	u8 Prelaod;
	u8 CompareValue;
}TIMER0_CFG;

void TIMER0_voidInit(TIMER0_CFG *timer_cfg,void (*ptr)(void));

void TIMER0_voidStop(void);

#endif /* COTS_1_MCAL_6_TIMER0_TIMER0_INTERFACE_H_ */
