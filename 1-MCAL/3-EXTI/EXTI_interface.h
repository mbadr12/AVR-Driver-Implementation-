/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	EXTI				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		1
#define ON_CHANGE		2
#define FALLING_EDGE	3
#define RAISING_EDGE	4

void EXTI_voidInt00Init(void);

void EXTI_voidInt01Init(void);

void EXTI_voidInt02Init(void);

/* Description: A Function to set the required sense control of INT0 using post build configuration
 * input: Copy_u8sense   Options:
 *                                1-LOW_LEVEL
 *                                2- ONCHANGE
 *                                3-FALLING_EDGE
 *                                4- RAISING_EDGE
 *	Output: ErrorStatus	with type u8
 */

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8sense);

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8sense);

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);

u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt0Func)(void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt0Func)(void));

#endif
