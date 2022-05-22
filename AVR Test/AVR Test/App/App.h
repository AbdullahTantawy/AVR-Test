/*
 * App.h
 *
 * Created: 5/19/2022 12:51:51 PM
 *  Author: Tantawy
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU 16000000UL
#include "util/delay.h"
#include "Lcd.h"
#include "Puzzer.h"
#include "Pushbutton.h"


#define A	1
#define B	2
#define C	3
#define D	4


void A_Asking(void);
void A_CheckAnswer(u8 Local_u8_Answer);
void A_RightAnswer(void);
void A_WrongAnswer(void);



#endif /* APP_H_ */