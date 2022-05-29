/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	KEYPAD				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include"STD_TYPES.h"

#include "../../1-MCAL/1-DIO/DIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY, Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState;
	static char Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;
	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDROWArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIdx=0; Local_u8ColumnIdx<COLUMN_NUM;Local_u8ColumnIdx++)
	{
		/*Activate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8Pin_LOW);

		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
		{
			/*Read The Current row*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDROWArr[Local_u8RowIdx],&Local_u8PinState);
			/*Check if switch is pressed*/
			if(Local_u8PinState==DIO_u8Pin_LOW)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
				while(Local_u8PinState==DIO_u8Pin_LOW)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDROWArr[Local_u8RowIdx],&Local_u8PinState);
				}
				//return Local_u8PressedKey;
			}
		}
		/*Deactivate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8Pin_HIGH);
	}

	return Local_u8PressedKey;
}
