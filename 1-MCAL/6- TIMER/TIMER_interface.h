/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#ifndef COTS_1_MCAL_6__TIMER_TIMER_INTERFACE_H_
#define COTS_1_MCAL_6__TIMER_TIMER_INTERFACE_H_

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

#define ICU_RaisingEdge 	1
#define ICU_FallingEdge 	0

#define OVERFLOW_INT 		0
#define CTC_INT				1
#define ICU_INT				2

#define TIMER0_OVF_INT		0
#define TIMER0_COMP_INT		1
#define TIMER1_OVF_INT		2
#define TIMER1_COMPA_INT	3
#define TIMER1_COMPB_INT	4
#define TIMER1_CAPT_INT		5
#define TIMER2_OVF_INT		6
#define TIMER2_COMP_INT		7

#define SERVO_CHANNEL1		1
#define SERVO_CHANNEL2		2

void TIMER0_voidInit(void);

void TIMER1_voidInit(void);

void TIMER2_voidInit(void);

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);

void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value);

void TIMER1_voidSetChannelBCompMatchValue(u16 Copy_u16Value);

void TIMER1_voidSetICR1Value(u16 Copy_u16Value);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

u16 TIMER1_u16GetTimerValue(void);

void ICU_voidInit(void);

u16 ICU_u16ReadInputCaputre(void);

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge);

void TIMER2_voidSetCompMatchValue(u8 Copy_u8Value);

u8 TIMER_u8SetCallBack(void (* Copy_pvCallBackFunc) (void),u8 Copy_u8ChannelID);

u8 TIMER_u8EnableInterrupt(u8 Copy_u8ChannelID,u8 Copy_u8InterruptID);

u8 TIMER_u8DisableInterrupt(u8 Copy_u8ChannelID,u8 Copy_u8InterruptID);

void Servo_vRotate(u8 Copy_u8Rotationdegree,u8 Copy_u8Channel);

#endif /* COTS_1_MCAL_6__TIMER_TIMER_INTERFACE_H_ */
