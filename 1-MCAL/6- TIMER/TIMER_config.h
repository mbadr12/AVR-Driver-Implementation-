/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_6__TIMER_TIMER_CONFIG_H_
#define COTS_1_MCAL_6__TIMER_TIMER_CONFIG_H_

/*choose Timer0 Waveform Generation Mode:
 * 1- TIMER0_NORMAL_MODE
 * 2- TIMER0_PWM_PHASE_CORRECT_MODE
 * 3- TIMER0_CTC_MODE
 * 4- TIMER0_FAST_PWM_MODE*/
#define TIMER0_GENERATION_MODE TIMER0_FAST_PWM_MODE

/*Choose Timer0 Compare Output Mode:
 * For Non-PWM mode:
 * 1- TIMER0_NORMAL: Normal port operation, OC0 disconnected
 * 2- TIMER0_TOGGLE_OC0: Toggle OC0 on compare match
 * 3- TIMER0_CLR_OC0: Clear OC0 on compare match
 * 4- TIMER0_SET_OC0: Set OC0 on compare match
 * For Fast PWM mode:
 * 1- TIMER0_NORMAL: Normal port operation, OC0 disconnected
 * 2- TIMER0_Reserved
 * 3- TIMER0_CLR_ON_COMP_SET_AT_TOP: Clear OC0 on compare match, set OC0 at TOP
 * 4- TIMER0_SET_ON_COMP_CLR_AT_TOP: Set OC0 on compare match, clear OC0 at TOP*/
#define TIMER0_COMPARE_OUTPUT_MODE TIMER0_CLR_ON_COMP_SET_AT_TOP

/*Choose Pre-scaler
 * 1- NO_CLK_SRC
 * 2- NO_DIV
 * 3- DIV_BY_8
 * 4- DIV_BY_64
 * 5- DIV_BY_256
 * 6- DIV_BY_1024
 * 7- EXT_CLK_FALL_EDGE
 * 8- EXT_CLK_RAIS_EDGESCALER DIV_BY_128 */
#define TIMER0_PRESCALER DIV_BY_8

#define TIMER1_PRESCALER DIV_BY_8

#define TIMER2_PRESCALER DIV_BY_64

/*choose Timer1 Waveform Generation Mode:
 * 1- TIMER1_NORMAL_MODE
 * 2- PWM_8BIT_PHASE_CORRECT_MODE
 * 3- PWM_9BIT_PHASE_CORRECT_MODE
 * 4- PWM_10BIT_PHASE_CORRECT_MODE
 * 5- CTC_OCR1A_MODE
 * 6- FAST_PWM_8BIT_MODE
 * 7- FAST_PWM_9BIT_MODE
 * 8- FAST_PWM_10BIT_MODE
 * 9- PWM_PHASE_FREQ_CORRECT_ICR1_MODE
 * 10- PWM_PHASE_FREQ_CORRECT_OCR1A_MODE
 * 11- PWM_PHASE_CORRECT_ICR1_MODE
 * 12- PWM_PHASE_CORRECT_OCR1A_MODE
 * 13- CTC_ICR1_MODE
 * 14- Reserved
 * 15- FAST_PWM_ICR1_MODE
 * 16- FAST_PWM_OCR1A_MODE*/

#define TIMER1_GENERATION_MODE TIMER1_NORMAL_MODE

/*Choose TIMER1 Compare Output Mode:
 * For Non-PWM mode:
 * 1- TIMER1_NORMAL: Normal port operation, OC1A/OC1B disconnected.
 * 2- TIMER1_TOGGLE_OC0: Toggle OC1A/OC1B on compare match
 * 3- TIMER1_CLR_OC0: Clear OC1A/OC1B on compare match
 * 4- TIMER1_SET_OC0: Set OC0 on compare match
 * For Fast PWM mode:
 * 1- TIMER1_NORMAL: Normal port operation, OC1A/OC1B disconnected.
 * 2- TIMER1_TOGGLE_OC1A: WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
 * For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
 * 3- TIMER1_CLR_ON_COMP_SET_AT_TOP: Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP
 * 4- TIMER1_SET_ON_COMP_CLR_AT_TOP: Set OC0 on compare match, clear OC0 at TOP*/

#define TIMER1_COMPARE_OUTPUT_MODE TIMER1_NORMAL

/*choose Timer0 Waveform Generation Mode:
 * 1- TIMER2_NORMAL_MODE
 * 2- TIMER2_PWM_PHASE_CORRECT_MODE
 * 3- TIMER2_CTC_MODE
 * 4- TIMER2_FAST_PWM_MODE*/
#define TIMER2_GENERATION_MODE TIMER2_NORMAL_MODE

/*Choose Timer2 Compare Output Mode:
 * For Non-PWM mode:
 * 1- TIMER2_NORMAL: Normal port operation, OC0 disconnected
 * 2- TIMER2_TOGGLE_OC0: Toggle OC0 on compare match
 * 3- TIMER2_CLR_OC0: Clear OC0 on compare match
 * 4- TIMER2_SET_OC0: Set OC0 on compare match
 * For Fast PWM mode:
 * 1- TIMER2_NORMAL: Normal port operation, OC0 disconnected
 * 2- TIMER2_Reserved
 * 3- TIMER2_CLR_ON_COMP_SET_AT_TOP: Clear OC0 on compare match, set OC0 at TOP
 * 4- TIMER2_SET_ON_COMP_CLR_AT_TOP: Set OC0 on compare match, clear OC0 at TOP*/
#define TIMER2_COMPARE_OUTPUT_MODE TIMER2_NORMAL

#endif /* COTS_1_MCAL_6__TIMER_TIMER_CONFIG_H_ */
