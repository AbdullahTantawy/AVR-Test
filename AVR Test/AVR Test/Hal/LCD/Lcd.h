/*
 * Lcd.h
 *
 * Created: 5/12/2022 11:04:20 AM
 *  Author: Tantawy
 */ 


#ifndef LCD_H_
#define LCD_H_

//=======================_INCLUDES_=============================

#include "LcdCfg.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include "util/delay.h"
//=======================_MACROS_=============================


#define _NULL_					'\0'
//====_COMMANDS_====================
#define LCD_CLR					0x01
#define LCD_RETURN_HOME			0x02
#define LCD_DIS_ON_CRS_OFF		0x0C
#define LCD_DIS_ON_CRS_OFF		0x0C
#define _8_BIT_MODE_COMMAND		0x38
#define _4_BIT_MODE_COMMAND		0x2C

//======================_PROTOTYPES_=========================

void H_Lcd_Init(void);
void H_Lcd_WriteChar(u8);
void H_Lcd_WriteStr(u8 *Local_u8_PrtArr);
void H_Lcd_writeCommand(u8 Local_u8_Command);
void H_Lcd_Clr(void);

void H_Lcd_GoTo(u8 , u8);
void H_Lcd_ClockDisplay(u8,u8,u8);
void H_Lcd_Shift(u8 * Local_u8_PtrArr);


void H_Lcd_PrintNum(f64 Local_f64_Num);
void H_Lcd_ClockCouterMin(u8 Local_u8_MaxMin);


#endif /* LCD_H_ */