/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  RTOS Stack		    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_6__TIMER_TIMER_PRIVATE_H_
#define COTS_1_MCAL_6__TIMER_TIMER_PRIVATE_H_


/*Pre Scaler*/
#define TIMER_PRESCALER_MASK	0b11111000
#define NO_CLK_SRC				0
#define NO_DIV    				1
#define DIV_BY_8  				2
#define DIV_BY_64 				3
#define DIV_BY_256 				4
#define DIV_BY_1024 			5
#define EXT_CLK_FALL_EDGE		6
#define EXT_CLK_RAIS_EDGE		7


#endif /* COTS_1_MCAL_6__TIMER_TIMER_PRIVATE_H_ */
