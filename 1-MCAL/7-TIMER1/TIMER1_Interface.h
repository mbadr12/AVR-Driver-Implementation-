/*
 * TIMER1_Interface.h
 *
 *  Created on: May 28, 2022
 *      Author: mbadr
 */

#ifndef COTS_1_MCAL_7_TIMER1_TIMER1_INTERFACE_H_
#define COTS_1_MCAL_7_TIMER1_TIMER1_INTERFACE_H_

#define F 50
#define N 8

#define Top ((F_CPU - N *F)/ (N*F))

void PWM_Init(void);

void PWM_UpdateOCR(u16 Value);

#endif /* COTS_1_MCAL_7_TIMER1_TIMER1_INTERFACE_H_ */
