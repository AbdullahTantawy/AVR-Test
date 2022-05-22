/*
 * Puzzer.c
 *
 * Created: 5/15/2022 11:21:51 AM
 *  Author: Tantawy
 */ 

#include "Puzzer.h"


void H_Buzzer_Init(void)
{
	M_Dio_PinMode(BUZZER_PIN,OUTPUT);
}


void H_Buzzer_On(void)
{
	M_Dio_PinWrite(BUZZER_PIN,HIGH);
}

void H_Buzzer_Off(void)
{
		M_Dio_PinWrite(BUZZER_PIN,LOW);
}
void H_Buzzer_Once(void)
{
	M_Dio_PinWrite(BUZZER_PIN,HIGH);
	_delay_ms(60);
	M_Dio_PinWrite(BUZZER_PIN,LOW);
}

void H_Buzzer_OnceLong(void)
{
	M_Dio_PinWrite(BUZZER_PIN,HIGH);
	_delay_ms(120);
	M_Dio_PinWrite(BUZZER_PIN,LOW);
}
void H_Buzzer_Twice(void)
{
	H_Buzzer_Once();
	_delay_ms(60);
	H_Buzzer_Once();
}