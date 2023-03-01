/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	MOTORS				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "MOTORS_interface.h"
#include "MOTORS_Private.h"
#include "MOTORS_config.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"

u8 DC_u8Rotate(DC_MOTOR* Copy_DCMotor,u8 Copy_u8Direction)
{
	u8 Local_u8ErorState=OK;
	if(Copy_DCMotor==NULL)
	{
		Local_u8ErorState=NULL_POINTER;
	}
	else
	{
		switch(Copy_u8Direction)
		{
		case CW: DIO_u8SetPinValue(Copy_DCMotor->DC_Port,Copy_DCMotor->DC_Pin1,DIO_u8Pin_HIGH);
				 DIO_u8SetPinValue(Copy_DCMotor->DC_Port,Copy_DCMotor->DC_Pin2,DIO_u8Pin_LOW); break;
		case CCW: DIO_u8SetPinValue(Copy_DCMotor->DC_Port,Copy_DCMotor->DC_Pin1,DIO_u8Pin_LOW);
				 DIO_u8SetPinValue(Copy_DCMotor->DC_Port,Copy_DCMotor->DC_Pin2,DIO_u8Pin_HIGH); break;
		default: Local_u8ErorState=WORNG_DIRECTION; break;
		}
	}

	return Local_u8ErorState;
}
u8 DC_u8Stop(DC_MOTOR* Copy_DCMotor)
{
	u8 Local_u8ErorState=OK;
	if(Copy_DCMotor==NULL)
	{
		Local_u8ErorState=NULL_POINTER;
	}
	else
	{
		DIO_u8SetPinValue(Copy_DCMotor->DC_Port,Copy_DCMotor->DC_Pin1,DIO_u8Pin_LOW);
		DIO_u8SetPinValue(Copy_DCMotor->DC_Port,Copy_DCMotor->DC_Pin2,DIO_u8Pin_LOW);
	}

	return Local_u8ErorState;
}
u8 STEPPER_u8Rotate(STEPPER_MOTOR* Copy_STEPPERMOTOR,u16 Copy_u16Angle,u8 Copy_u8Direction)
{
	u8 Local_u8ErorState=OK;
	u32 Local_u32IterationsNum=0;
	u32 Local_u32Counter=0;
	if(Copy_STEPPERMOTOR==NULL)
	{
		Local_u8ErorState=NULL_POINTER;
	}
	else
	{
		if(Copy_u16Angle==CONT_ROTATION)
		{
			switch(Copy_u8Direction)
			{
			case CCW: while(1)
			{
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_LOW);
				_delay_ms(2);
			} break;
			case CW: while(1)
			{
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_LOW);
				_delay_ms(2);
			} break;
			default: Local_u8ErorState=WORNG_DIRECTION; break;
			}
		}
		else
		{
			Local_u32IterationsNum=(Copy_u16Angle*10)/7;
			switch(Copy_u8Direction)
			{
			case CCW: for(Local_u32Counter=0;Local_u32Counter<Local_u32IterationsNum;Local_u32Counter++)
			{
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_LOW);
				_delay_ms(2);
			} break;
			case CW: for(Local_u32Counter=0;Local_u32Counter<Local_u32IterationsNum;Local_u32Counter++)
			{
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_LOW);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
				_delay_ms(2);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN4,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN3,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN2,DIO_u8Pin_HIGH);
				DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_LOW);
				_delay_ms(2);
			} break;
			default: Local_u8ErorState=WORNG_DIRECTION; break;
			}
		}
	}

	return Local_u8ErorState;
}
u8 STEPPER_u8Stop(STEPPER_MOTOR* Copy_STEPPERMOTOR)
{
	u8 Local_u8ErorState=OK;
	if(Copy_STEPPERMOTOR==NULL)
	{
		Local_u8ErorState=NULL_POINTER;
	}
	else
	{
		DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
		DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
		DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
		DIO_u8SetPinValue(Copy_STEPPERMOTOR->Stepper_Port,Copy_STEPPERMOTOR->Stepper_PIN1,DIO_u8Pin_HIGH);
	}

	return Local_u8ErorState;
}
