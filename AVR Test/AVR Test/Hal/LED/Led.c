/*
 * Led.c
 *
 * Created: 5/10/2022 12:53:20 PM
 *  Author: Tantawy
 */ 

#include "Led.h"
#include "Dio.h"

/*
this function to initialize the led
make the pin output
*/
void H_Led_Init(u8 local_u8_Led)
{
	switch(local_u8_Led)
	{
		case RED_LED :	 M_Dio_PinMode(RED_LED_PIN,OUTPUT);	break;
		case BLU_LED :	 M_Dio_PinMode(BLU_LED_PIN,OUTPUT);	break;
		case GRN_LED :	 M_Dio_PinMode(GRN_LED_PIN,OUTPUT);	break;
		default:											break;
	}
	
}

/*
function to turn the led on 
*/
void H_Led_On(u8 local_u8_Led)
{
	switch(local_u8_Led)
	{
		case RED_LED :	 M_Dio_PinWrite(RED_LED_PIN,HIGH);	break;
		case BLU_LED :	 M_Dio_PinWrite(BLU_LED_PIN,HIGH);	break;
		case GRN_LED :	 M_Dio_PinWrite(GRN_LED_PIN,HIGH);	break;
		default:											break;
	}
}	

/*
function to turn the led off
*/
void H_Led_Off(u8 local_u8_Led)
{
	switch(local_u8_Led)
	{
		case RED_LED :	 M_Dio_PinWrite(RED_LED_PIN,LOW);	break;
		case BLU_LED :	 M_Dio_PinWrite(BLU_LED_PIN,LOW);	break;
		case GRN_LED :	 M_Dio_PinWrite(GRN_LED_PIN,LOW);	break;
		default:											break;
	}
}
/*
function to turn the led off if it is on 
and turn it on if it is off
*/
void H_Led_Tog(u8 local_u8_Led)
{
	
	switch(local_u8_Led)
	{
		case RED_LED :	 M_Dio_pinTog(RED_LED_PIN);	break;
		case BLU_LED :	 M_Dio_pinTog(BLU_LED_PIN);	break;
		case GRN_LED :	 M_Dio_pinTog(GRN_LED_PIN);	break;
		default:									break;
	}
	M_Dio_pinTog(local_u8_Led);
}

/*
turn the led on and hold it for a selected time and turn it on
*/
void H_Led_BlinkOnce(u8 local_u8_Led)
{
	switch(local_u8_Led)
	{
		case RED_LED :	
				M_Dio_PinWrite(RED_LED_PIN,HIGH);
				_delay_ms(BLINK_TIME);
				M_Dio_PinWrite(RED_LED_PIN,LOW);
		 		break;
		case BLU_LED :
				M_Dio_PinWrite(BLU_LED_PIN,HIGH);
				_delay_ms(BLINK_TIME);
				M_Dio_PinWrite(BLU_LED_PIN,LOW);
			 	break;
		case GRN_LED :	
				M_Dio_PinWrite(GRN_LED_PIN,HIGH);
				_delay_ms(BLINK_TIME);
				M_Dio_PinWrite(GRN_LED_PIN,LOW);	
				 break;
		default:							
				break;
	}

}
/*
turn the led on and hold it for a selected time and turn it on
make it twice
*/
void H_Led_Blinktwice(u8 local_u8_Led)
{
	H_Led_BlinkOnce(local_u8_Led);
	_delay_ms(BLINK_TIME);
	H_Led_BlinkOnce(local_u8_Led);
}

//================================================

