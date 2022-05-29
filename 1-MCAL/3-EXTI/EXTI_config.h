/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	EXTI				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Options:
			1-LOW_LEVEL
			2- ONCHANGE
			3-FALLING_EDGE
			4- RAISING_EDGE
 */

#define INT0_SENSE FALLING_EDGE

#define INT1_SENSE FALLING_EDGE

#define INT2_SENSE FALLING_EDGE

/*Options
			1- ENABLED
			2- DISABLED
 */
#define INT0_INTIAL_STATE	ENABLED
#define INT1_INTIAL_STATE 	ENABLED
#define INT2_INTIAL_STATE 	ENABLED

#endif
