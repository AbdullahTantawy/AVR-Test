/*
 * Dio.c
 *
 * Created: 5/10/2022 10:00:46 AM
 *  Author: Tantawy
 */ 

#include "Dio.h"
#include "BitMath.h"

//-------_function_to_select_the_pins_modes_-----------------------------
// take two arguments one to select the port and the pin
// and another to select out or input (mode)
void M_Dio_PinMode(u8 Local_u8_num , u8 Local_u8_Mode)
{
	// variable to select the pin number -> 
	//ex:Local_u8_num =PA4 = (14) mean pin 4
	u8 Local_u8_Pin = Local_u8_num %10;
	// variable to select the port -> (14) mean port 1(A)
	u8 local_u8_Port = Local_u8_num /10;
	
	switch(Local_u8_Mode) // switch the mode is input or output
	{
		case INPUT:
		{
			switch(local_u8_Port) // switch the port (A,B,C,D)
			{
				case PORT_A:	Clrbit(DDRA,Local_u8_Pin);	 break;
				case PORT_B:	Clrbit(DDRB,Local_u8_Pin);	 break;
				case PORT_C:	Clrbit(DDRC,Local_u8_Pin);	 break;
				case PORT_D:	Clrbit(DDRD,Local_u8_Pin);	 break;
				default:								 break;
			}// switch port
		}
		break;// Case input
		case OUTPUT:
		{
			switch(local_u8_Port) // select the port
			{
				case PORT_A:	Setbit(DDRA,Local_u8_Pin);	 break;
				case PORT_B:	Setbit(DDRB,Local_u8_Pin);	 break;
				case PORT_C:	Setbit(DDRC,Local_u8_Pin);	 break;
				case PORT_D:	Setbit(DDRD,Local_u8_Pin);	 break;
				default:								 break;
			}// switch port
		}
		break;//case output
		default:
		break;//default
		
	}// switch mode
	
}// DIO pin mode function

/*******************************************************************************************************/
void M_Dio_PinWrite(u8 Local_u8_num , u8 Local_u8_Mode)
{
	// variable to select the pin number
	u8 Local_u8_Pin = Local_u8_num %10;
	// variable to select the port
	u8 local_u8_Port = Local_u8_num /10;
	
	switch(Local_u8_Mode)
	{
		case LOW:
		{
			switch(local_u8_Port) // select the port
			{
				case PORT_A:	Clrbit(PORTA,Local_u8_Pin);	 break;
				case PORT_B:	Clrbit(PORTB,Local_u8_Pin);	 break;
				case PORT_C:	Clrbit(PORTC,Local_u8_Pin);	 break;
				case PORT_D:	Clrbit(PORTD,Local_u8_Pin);	 break;
				default:								 break;
			}// switch port
		}
		break;// Case input
		case HIGH:
		{
			switch(local_u8_Port) // select the port
			{
				case PORT_A:	Setbit(PORTA,Local_u8_Pin);	 break;
				case PORT_B:	Setbit(PORTB,Local_u8_Pin);	 break;
				case PORT_C:	Setbit(PORTC,Local_u8_Pin);	 break;
				case PORT_D:	Setbit(PORTD,Local_u8_Pin);	 break;
				default:								 break;
			}// switch port
		}
		break;//case output
		default:
		break;//default
		
	}// switch mode
	
}

//----------------------------------------------------------------

void M_Dio_pinTog(u8 Local_u8_num)
{
	// variable to select the pin number
	u8 Local_u8_Pin = Local_u8_num %10;
	// variable to select the port
	u8 local_u8_Port = Local_u8_num /10;
	
	switch(local_u8_Port) // select the port
	{
		case PORT_A:	Togbit(PORTA,Local_u8_Pin);	 break;
		case PORT_B:	Togbit(PORTB,Local_u8_Pin);	 break;
		case PORT_C:	Togbit(PORTC,Local_u8_Pin);	 break;
		case PORT_D:	Togbit(PORTD,Local_u8_Pin);	 break;
		default:								 break;
	}// switch port
}

//----------------------------------------------------------------------------

u8   M_Dio_PinGet(u8 Local_u8_num)
{
	// variable to select the pin number
	u8 Local_u8_Pin = Local_u8_num %10;
	// variable to select the port
	u8 local_u8_Port = Local_u8_num /10;
	
	u8 Local_u8_Reading = 0;
	switch(local_u8_Port) // select the port
	{
		case PORT_A:Local_u8_Reading=Getbit(PINA,Local_u8_Pin);	 break;
		case PORT_B:Local_u8_Reading=Getbit(PINB,Local_u8_Pin);	 break;
		case PORT_C:Local_u8_Reading=Getbit(PINC,Local_u8_Pin);	 break;
		case PORT_D:Local_u8_Reading=Getbit(PIND,Local_u8_Pin);	 break;
		default:													 break;
	}// switch port
	
	return Local_u8_Reading;
}

//----------------------------------------------------

void M_Dio_PortMode(u8 Local_u8_num , u8 Local_u8_Mode)
{
	
	switch(Local_u8_Mode) // switch the mode is input or output
	{
		case INPUT:
		{
			switch(Local_u8_num) // switch the port (A,B,C,D)
			{
				case PORT_A:	DDRA=0X00;	 break;
				case PORT_B:	DDRB=0X00;	 break;
				case PORT_C:	DDRC=0X00;	 break;
				case PORT_D:	DDRD=0X00;	 break;
				default:					 break;
			}// switch port
		}
		break;// Case input
		case OUTPUT:
		{
			switch(Local_u8_num) // select the port
			{
				case PORT_A:	DDRA=0XFF;	 break;
				case PORT_B:	DDRB=0XFF;	 break;
				case PORT_C:	DDRC=0XFF;	 break;
				case PORT_D:    DDRD=0XFF;	 break;
				default:								 break;
			}// switch port
		}
		break;//case output
		default:
		break;//default
		
	}// switch mode
}

//-------------------------------------------------------------------

void M_Dio_PortWrite(u8 Local_u8_num , u8 Local_u8_Mode)
{
	
	switch(Local_u8_Mode)
	{
		case LOW:
		{
			switch(Local_u8_num) // select the port
			{
				case PORT_A:	PORTA=0X00;	 break;
				case PORT_B:	PORTB=0X00;	 break;
				case PORT_C:	PORTC=0X00;	 break;
				case PORT_D:	PORTD=0X00;	 break;
				default:					 break;
			}// switch port
		}
		break;// Case input
		case HIGH:
		{
			switch(Local_u8_num) // select the port
			{
				case PORT_A:	PORTA=0XFF;	 break;
				case PORT_B:	PORTB=0XFF;	 break;
				case PORT_C:	PORTC=0XFF;	 break;
				case PORT_D:	PORTD=0XFF;	 break;
				default:					 break;
			}// switch port
		}
		break;//case output
		default:
		break;//default
		
	}// switch mode
}
 
