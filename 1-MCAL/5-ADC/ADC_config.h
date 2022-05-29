/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	ADC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_5_ADC_ADC_CONFIG_H_
#define COTS_1_MCAL_5_ADC_ADC_CONFIG_H_

/* Choose ADC Reference voltage
 * Choices
 * 1- AREF: AREF as reference Voltage , Internal Vref turned off
 * 2- AVCC: AVCC as reference Voltage with external capacitor at AREF pin
 * 3- INTERNAL: 2.56V Voltage Reference with external capacitor at AREF pin*/

#define ADC_REF_VOLTAGE AVCC

/*choose Auto trigger status
 * 1- SINGLE_MODE
 * 2- AUTO_TRIGGER*/
#define ADC_CONVERSION_MODE SINGLE_MODE

/*Choose Pre-scaler
 * 1- DIV_BY_2
 * 2- DIV_BY_4
 * 3- DIV_BY_8
 * 4- DIV_BY_16
 * 5- DIV_BY_32
 * 6- DIV_BY_64
 * 7- DIV_BY_128*/
#define ADC_PRE_SCALER DIV_BY_128

/*choose Auto trigger Source
 * 1- FREE_RUNNING_MODE
 * 2- ANALOG_COMPARATOR
 * 3- EXTERNAL_INTERRUPT_REQUEST0
 * 4- TIMER_COUNTER0_COMPARE MATCH
 * 5- TIMER_COUNTER0_OVERFLOW
 * 6- TIMER_COUNTER_COMPARE MATCHB
 * 7- TIMER_COUNTER1_OVERFLOW
 * 8- TIMER_COUNTER1_CAPTURE_EVENT*/
#define AUTO_TRIGGER_SOURCE FREE_RUNNING_MODE

/*Choose ADC_Resolution
 * 1- EIGHT_BIT
 * 2- TEN_BIT*/
#define ADC_RES EIGHT_BIT

#endif /* COTS_1_MCAL_5_ADC_ADC_CONFIG_H_ */
