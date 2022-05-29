/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	ADC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_5_ADC_ADC_REGISTER_H_
#define COTS_1_MCAL_5_ADC_ADC_REGISTER_H_


#define ADCL 			 *((volatile u8*) 0x24)			//ADC High register
#define ADCH 			 *((volatile u8*) 0x25)			//ADC Low register
#define ADC  			 *((volatile u16*)0x24)

#define ADCSRA			 *((volatile u8*) 0x26)			//ADC control and status register A
#define ADCSRA_ADEN 	 7								//ADC Enable
#define ADCSRA_ADSC		 6								//Start conversion
#define ADCSRA_ADATE	 5								//Auto trigger enable
#define ADCSRA_ADIF		 4								//Interrupt flag
#define ADCSRA_ADIE		 3								//Interrupt enable
#define ADCSRA_ADPS2	 2								//pre-scaler bit2
#define ADCSRA_ADPS1	 1                              //pre-scaler bit1
#define ADCSRA_ADPS0	 0                              //pre-scaler bit0

#define ADMUX 			 *((volatile u8*) 0x27)			//ADC multiplexer selection register
#define ADMUX_REFS1 	 7								//Reference selection bit0
#define ADMUX_REFS0		 6                              //Reference selection bit1
#define ADMUX_ADLAR 	 5                              //ADC left adjust result

#define SFIOR 			 *((volatile u8*) 0x50)

#endif /* COTS_1_MCAL_5_ADC_ADC_REGISTER_H_ */
