/*
 * AvrDrivers.c
 *
 * Created: 5/12/2022 8:00:33 AM
 * Author : Tantawy
 */ 




#define F_CPU 16000000UL
#include "util/delay.h"
#include "Led.h"
#include "Pushbutton.h"
#include "Lcd.h"
#include "Puzzer.h"
#include "Timer_interface.h"
#include "App.h"

int main(void)
{
	u8 i=0;
	H_Lcd_Init();
	H_Buzzer_Init();
	H_PushButton_Init(PUSHBUTTON_1);
	H_PushButton_Init(PUSHBUTTON_2);
	H_PushButton_Init(PUSHBUTTON_3);
	H_PushButton_Init(PUSHBUTTON_4);
	Setbit(SREG,7);
	M_Timer0_vIntEnable(TIMER0_OVF_INT_ID);
	M_Timer0_vSetCallBack(A_manage_time , TIMER0_OVF_INT_ID);
	
	H_Lcd_GoTo(0,1);
	H_Lcd_WriteStr("Welcome ");
	_delay_ms(2000);
	H_Lcd_Clr();
	H_Lcd_GoTo(0,3);
	H_Lcd_WriteStr("Start Game");
	_delay_ms(2000);
	H_Lcd_Clr();
	M_Timer0_vStart();
	
	for (i=0;i<5;i++)
	{
		A_Asking();
		
	}
	H_Lcd_GoTo(1,0);
	H_Lcd_WriteStr("Congratulations ");
	while (1)
	{
		
	}
	return 0;
}



