/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	ADC 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_register.h"
void ADC_voidInit(void)
{
	/*AVCC as reference voltage*/
#if ADC_REF_VOLTAGE==AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_REF_VOLTAGE==AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_REF_VOLTAGE==INTERNAL
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "Wrong Voltage Reference"
#endif
#if ADC_RES==EIGHT_BIT
	/*Activate left adjust result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_RES==TEN_BIT
	/*SET Right Adjust Result*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong Resolution"
#endif
	/*SET pre-scaler to divide by 128*/
	ADCSRA&=PRE_SCALERMASK;
	ADCSRA|=ADC_PRE_SCALER;
	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#if ADC_CONVERSION_MODE==AUTO_TRIGGER
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	/*Setting Auto Trigger Source*/
	SFIOR&=SOURCE_MASK;
	SFIOR|=(AUTO_TRIGGER_SOURCE<<5);
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#elif ADC_CONVERSION_MODE==SINGLE_MODE
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#else
#error "Wrong Conversion Mode"
#endif
}

u16 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	/*Clear The MUX bits in ADmux register*/
	ADMUX &=ADMUX_MASK;
	/*Set the required channel into the MUX bits*/
	ADMUX|=Copy_u8Channel;
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*polling (Busy waiting) until the conversion complete flag is set*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/*Clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
#if ADC_RES==EIGHT_BIT
	return ADCH;
#elif ADC_RES==TEN_BIT
	return ADC;
#else
#error "Wrong Conversion Mode"
#endif
}
