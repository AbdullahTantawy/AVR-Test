/*
 * LcdCfg.h
 *
 * Created: 5/12/2022 11:04:48 AM
 *  Author: Tantawy
 */ 


#ifndef LCDCFG_H_
#define LCDCFG_H_


/*=================================================_Functions_Describtin_================================================================


								>>>>>>>	The Functions you need to use the App <<<<<<<<<
 H_Lcd_Init();
 
 H_Lcd_WriteChar(' ');
 
 H_Lcd_WriteStr(" ");
 
 H_Lcd_writeCommand(MACROS);
 
 H_Lcd_Clr();

 H_Lcd_GoTo(row , column);								---> go to the position
 
 H_Lcd_ClockDisplay(hour,min,sec);						----> Display the clock
 
 H_Lcd_Shift(" ");										----> Shift the the string from left to right

 H_Lcd_PrintNum(number);								----> print any number +ve & -ve & floating
 
 H_Lcd_ClockCouterMin(Maximum mins);					----> Timer to count until selected Minutes  

==================================================================================================================*/
#define LCD_DATA_PORT	PORT_A

#define LCD_DATA_REG		PORTA

#define LCD_DATA_PIN_7       PA6
#define LCD_DATA_PIN_6       PA5
#define LCD_DATA_PIN_5       PA4
#define LCD_DATA_PIN_4       PA3

#define LCD_EN_PIN			 PA2			//PB0
#define LCD_RS_PIN			 PA1			//PB1

//================================================
// _4_BITS_MODE_  (0)  OR  _8_BITS_MODE_  (1)

#define 	_8_BITS_MODE_			(0)

#if _8_BITS_MODE_
   #define _BIT_MODE_COMMAND	_8_BIT_MODE_COMMAND
#else
	#define _BIT_MODE_COMMAND	_4_BIT_MODE_COMMAND
#endif

#endif /* LCDCFG_H_ */