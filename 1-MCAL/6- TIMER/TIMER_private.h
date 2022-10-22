/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_6__TIMER_TIMER_PRIVATE_H_
#define COTS_1_MCAL_6__TIMER_TIMER_PRIVATE_H_
/*Timer0 Waveform generation modes*/
#define TIMER0_NORMAL_MODE 				1
#define TIMER0_PWM_PHASE_CORRECT_MODE	2
#define TIMER0_CTC_MODE					3
#define TIMER0_FAST_PWM_MODE			4

/*Timer0 Compare Output Modes*/
#define COMP_OPMODE_MASK				0b11001111
#define TIMER0_NORMAL					0b00000000
#define TIMER0_TOGGLE_OC0				0b00010000
#define TIMER0_CLR_OC0					0b00100000
#define TIMER0_SET_OC0					0b00110000
#define TIMER0_CLR_ON_COMP_SET_AT_TOP 	0b00100000
#define TIMER0_SET_ON_COMP_CLR_AT_TOP 	0b00110000

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

/*Timer1 Waveform generation modes*/
#define TIMER1_WAVE_MODE_MASK_TCCR1A		0b11111100
#define TIMER1_WAVE_MODE_MASK_TCCR1B		0b11100111
#define TIMER1_WGM10_WGM11_MASK				0b00000011
#define TIMER1_WGM12_WGM13_MASK				0b00001100
#define TIMER1_NORMAL_MODE					0
#define PWM_8BIT_PHASE_CORRECT_MODE			1
#define PWM_9BIT_PHASE_CORRECT_MODE        	2
#define PWM_10BIT_PHASE_CORRECT_MODE       	3
#define CTC_OCR1A_MODE                     	4
#define FAST_PWM_8BIT_MODE                 	5
#define FAST_PWM_9BIT_MODE                 	6
#define FAST_PWM_10BIT_MODE                	7
#define PWM_PHASE_FREQ_CORRECT_ICR1_MODE   	8
#define PWM_PHASE_FREQ_CORRECT_OCR1A_MODE	9
#define PWM_PHASE_CORRECT_ICR1_MODE       	10
#define PWM_PHASE_CORRECT_OCR1A_MODE      	11
#define CTC_ICR1_MODE                     	12
#define FAST_PWM_ICR1_MODE                	13
#define FAST_PWM_OCR1A_MODE					15

/*Timer1 Compare Output Modes*/
#define COMP_OPMODE_CHANA_MASK	0b00111111
#define COMP_OPMODE_CHANB_MASK	0b11001111
#define TIMER1_NORMAL					0
#define TIMER1_TOGGLE_OC1A_B			1
#define TIMER1_CLR_OC1A_B				2
#define TIMER1_SET_OC1A_B				3
#define TIMER1_TOGGLE_OC1A 				1
#define TIMER1_CLR_ON_COMP_SET_AT_TOP 	2
#define TIMER1_SET_ON_COMP_CLR_AT_TOP 	3

/*Timer0 Waveform generation modes*/
#define TIMER2_NORMAL_MODE 				1
#define TIMER2_PWM_PHASE_CORRECT_MODE	2
#define TIMER2_CTC_MODE					3
#define TIMER2_FAST_PWM_MODE			4

/*Timer0 Compare Output Modes*/
#define COMP_OPMODE_MASK				0b11001111
#define TIMER2_NORMAL					0b00000000
#define TIMER2_TOGGLE_OC2				0b00010000
#define TIMER2_CLR_OC2					0b00100000
#define TIMER2_SET_OC2					0b00110000
#define TIMER2_CLR_ON_COMP_SET_AT_TOP 	0b00100000
#define TIMER2_SET_ON_COMP_CLR_AT_TOP 	0b00110000

#endif /* COTS_1_MCAL_6__TIMER_TIMER_PRIVATE_H_ */
