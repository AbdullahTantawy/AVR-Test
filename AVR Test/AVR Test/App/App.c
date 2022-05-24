/*
 * App.c
 *
 * Created: 5/19/2022 12:52:08 PM
 *  Author: Tantawy
 */ 
#include "App.h"

u8 Local_u8_Qnum =1;
u8 Local_u8_Min = 0;
u8 Local_u8_Sec = 0;
u8 Local_u8_Hour = 0;

void A_Asking(void)
{
	H_Lcd_ClockDisplay(Local_u8_Hour,Local_u8_Min,Local_u8_Sec);
	u8 Local_u8_Answer = 1;
	H_Lcd_GoTo(0,0);
	H_Lcd_WriteStr("Q");
	H_Lcd_WriteChar(Local_u8_Qnum+48);
	H_Lcd_GoTo(1,3);
	H_Lcd_WriteStr("A  B  C  D");
	while(Local_u8_Answer != 0)
	{
		Local_u8_Answer = H_PushButton_Read(PUSHBUTTON_1);
		if (Local_u8_Answer==0)
		{
			Local_u8_Answer = A;
			break;
		}
		Local_u8_Answer = H_PushButton_Read(PUSHBUTTON_2);
		if (Local_u8_Answer==0)
		{
			Local_u8_Answer = B;
			break;
		}
		Local_u8_Answer = H_PushButton_Read(PUSHBUTTON_3);
		if (Local_u8_Answer==0)
		{
			Local_u8_Answer = C;
			break;
		}
		Local_u8_Answer = H_PushButton_Read(PUSHBUTTON_4);
		if (Local_u8_Answer==0)
		{
			Local_u8_Answer = D;
			break;
		}
	
	}
	H_Lcd_Clr();
	A_CheckAnswer(Local_u8_Answer);
}

void A_CheckAnswer(u8 Local_u8_Answer)
{
	u8 Local_u8_ArrAnswer[5] = {D,D,D,C,C};
	if (Local_u8_Answer == Local_u8_ArrAnswer[Local_u8_Qnum-1])
	{
		A_RightAnswer();
	}
	else
	{
		A_WrongAnswer();
	}

}


void A_RightAnswer(void)
{
	
	H_Buzzer_Once();
	H_Lcd_GoTo(1,2);
	H_Lcd_WriteStr(">>> GREAT <<<");
	_delay_ms(1500);
	Local_u8_Qnum++;
	H_Lcd_Clr();
}


void A_WrongAnswer(void)
{
	Local_u8_Min++;
	H_Buzzer_Twice();
	H_Lcd_GoTo(1,0);
	H_Lcd_WriteStr("> DISPLAY 1 MIN <<<");
	_delay_ms(60);
	H_Buzzer_Twice();
	_delay_ms(60);
	H_Lcd_Clr();
	H_Lcd_GoTo(1,2);
	H_Lcd_WriteStr(">>> LOSER <<<");
	_delay_ms(1000);
	H_Lcd_Clr();
	A_Asking();
}

void A_manage_time(void)
{
	
	if (Local_u8_Sec < 59 )
	{
		Local_u8_Sec++;
	}
	else
	{
		Local_u8_Sec =0;
		Local_u8_Min++;
	}
	H_Lcd_ClockDisplay(Local_u8_Hour,Local_u8_Min,Local_u8_Sec);
}