/*
 * TIMER1_register.h
 *
 *  Created on: May 28, 2022
 *      Author: mbadr
 */

#ifndef COTS_1_MCAL_7_TIMER1_TIMER1_REGISTER_H_
#define COTS_1_MCAL_7_TIMER1_TIMER1_REGISTER_H_

#define TCCR1A 	*((volatile u8*) 0x4f)
#define TCCR1B 	*((volatile u8*) 0x4e)
#define TCNT1 	*((volatile u16*) 0x4c)
#define OCR1A 	*((volatile u16*) 0x4a)
#define ICR1 	*((volatile u16*) 0x46)

#endif /* COTS_1_MCAL_7_TIMER1_TIMER1_REGISTER_H_ */
