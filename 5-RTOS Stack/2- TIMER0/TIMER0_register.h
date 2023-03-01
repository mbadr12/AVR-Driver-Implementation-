/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  RTOS Stack		    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_6__TIMER_TIMER_REGISTER_H_
#define COTS_1_MCAL_6__TIMER_TIMER_REGISTER_H_

/*TIMER0 Registers*/
#define TCCR0 *((volatile u8*) 0x53) /*TIMER0 control Register*/
#define TCCR0_WGM00 6				 /*Waveform Generation bit0*/
#define TCCR0_WGM01 3				 /*Waveform Generation bit1*/
#define TCCR0_CS02  2				 /*Pre-Scaler bit2*/
#define TCCR0_CS01  1				 /*Pre-Scaler bit1*/
#define TCCR0_CS00  0				 /*Pre-Scaler bit0*/
#define OCR0  *((volatile u8*) 0x5c) /*OutPut Compare Register 0*/

#define TIMSK *((volatile u8*) 0x59) /*Timer Mask*/
#define TIMSK_OCIE0		1			 /*Out Compare 0 interrupt Enable*/

#endif /* COTS_1_MCAL_6__TIMER_TIMER_REGISTER_H_ */
