/*
 * Pushbutton.c
 *
 * Created: 5/11/2022 10:01:05 AM
 *  Author: Tantawy
 */ 

#include "Pushbutton.h"

void H_PushButton_Init(u8 Local_u8_PUSHBUTTON)
{
	switch (Local_u8_PUSHBUTTON)
	{
		case PUSHBUTTON_1 :	M_Dio_PinMode(PUSHBUTTON1_PIN , INPUT); break;
		case PUSHBUTTON_2 :	M_Dio_PinMode(PUSHBUTTON2_PIN , INPUT); break;
		case PUSHBUTTON_3 :	M_Dio_PinMode(PUSHBUTTON3_PIN , INPUT); break;
		case PUSHBUTTON_4 :	M_Dio_PinMode(PUSHBUTTON4_PIN , INPUT); break;
		default:													break;
	}
}

//--------------------------------------------------------------------------
u8 H_PushButton_Read(u8 Local_u8_PUSHBUTTON)
{
	u8 Local_u8_Reading = RELEASED;
	switch (Local_u8_PUSHBUTTON)
	{
		case PUSHBUTTON_1 : Local_u8_Reading=H_PushButton_Read_Pin(PUSHBUTTON1_PIN);  break;
		case PUSHBUTTON_2 : Local_u8_Reading=H_PushButton_Read_Pin(PUSHBUTTON2_PIN);  break;
		case PUSHBUTTON_3 :	Local_u8_Reading=H_PushButton_Read_Pin(PUSHBUTTON3_PIN);  break;
        case PUSHBUTTON_4 : Local_u8_Reading=H_PushButton_Read_Pin(PUSHBUTTON4_PIN);  break;
		default:																	  break;
	}
	return Local_u8_Reading;
}


//===================================================== 
u8 H_PushButton_Read_Pin(u8 Local_u8_PUSHBUTTON_Pin)
{
	  u8 Local_u8_Reading = RELEASED;
		
		if(M_Dio_PinGet(Local_u8_PUSHBUTTON_Pin) == PRESSED)
		{
			_delay_ms(BLINK_TIME); // to solve the bouncing problem
			if ( M_Dio_PinGet(Local_u8_PUSHBUTTON_Pin) == PRESSED)
			{
				Local_u8_Reading = PRESSED;
				//if the button still pressed hold until released
				while( M_Dio_PinGet(PUSHBUTTON1_PIN) == PRESSED);
			}
		}
	return 	Local_u8_Reading;
}