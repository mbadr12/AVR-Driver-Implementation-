/*
 * TIMER0_Register.h
 *
 *  Created on: May 21, 2022
 *      Author: mbadr
 */

#ifndef COTS_1_MCAL_6_TIMER0_TIMER0_REGISTER_H_
#define COTS_1_MCAL_6_TIMER0_TIMER0_REGISTER_H_

#define TCCR0 	*((volatile u8*) 0x53)
#define TCNT0 	*((volatile u8*) 0x52)
#define TIMSK 	*((volatile u8*) 0x59)
#define OCR0 	*((volatile u8*) 0x5c)

#endif /* COTS_1_MCAL_6_TIMER0_TIMER0_REGISTER_H_ */
