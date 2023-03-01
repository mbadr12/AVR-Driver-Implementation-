/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	MOTORS				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_2_HAL_6_MOTORS_MOTORS_INTERFACE_H_
#define COTS_2_HAL_6_MOTORS_MOTORS_INTERFACE_H_

typedef struct
{
	u8 DC_Port;
	u8 DC_Pin1;
	u8 DC_Pin2;
}DC_MOTOR;
typedef struct
{
	u8 Stepper_Port;
	u8 Stepper_PIN1;
	u8 Stepper_PIN2;
	u8 Stepper_PIN3;
	u8 Stepper_PIN4;
}STEPPER_MOTOR;


#define CW  1
#define CCW 2
#define FULL_SPEED 0
#define POTANTIMETER_CONTROL 1
#define LM35_CONTROL		 2
#define CONT_ROTATION		 0

u8 DC_u8Rotate(DC_MOTOR* Copy_DCMotor,u8 Copy_u8Direction);
u8 DC_u8Stop(DC_MOTOR* Copy_DCMotor);
u8 STEPPER_u8Rotate(STEPPER_MOTOR* Copy_STEPPERMOTOR,u16 Copy_u16Angle,u8 Copy_u8Direction);
u8 STEPPER_u8Stop(STEPPER_MOTOR* Copy_STEPPERMOTOR);


#endif /* COTS_2_HAL_6_MOTORS_MOTORS_INTERFACE_H_ */
