/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	ADC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_5_ADC_ADC_PRIVATE_H_
#define COTS_1_MCAL_5_ADC_ADC_PRIVATE_H_

#define AREF 	 1
#define AVCC 	 2
#define INTERNAL 3

#define DIV_BY_2		1
#define DIV_BY_4  		2
#define DIV_BY_8  		3
#define DIV_BY_16 		4
#define DIV_BY_32 		5
#define DIV_BY_64 		6
#define DIV_BY_128		7

#define FREE_RUNNING_MODE                 0
#define ANALOG_COMPARATOR                 1
#define EXTERNAL_INTERRUPT_REQUEST0       2
#define TIMER_COUNTER0_COMPARE MATCH      3
#define TIMER_COUNTER0_OVERFLOW           4
#define TIMER_COUNTER_COMPARE MATCHB      5
#define TIMER_COUNTER1_OVERFLOW           6
#define TIMER_COUNTER1_CAPTURE_EVENT	  7

#define EIGHT_BIT	1
#define TEN_BIT 	2

#define SINGLE_MODE 		1
#define AUTO_TRIGGER     	2

#define PRE_SCALERMASK 		0b11111000
#define ADMUX_MASK			0b11100000
#define SOURCE_MASK			0b00011111

#endif /* COTS_1_MCAL_5_ADC_ADC_PRIVATE_H_ */
