/*
 * Pushbutton.h
 *
 * Created: 5/11/2022 10:01:30 AM
 *  Author: Tantawy
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

//--------------------_INCLUDES_--------------------------
#include "Std.h"
#include "Dio.h"
#include "PushbuttonCfg.h"
#define F_CPU 16000000UL
#include "util/delay.h"

//---------------------_MACROS_-----------------------------

#define PUSHBUTTON_1	1
#define PUSHBUTTON_2	2
#define PUSHBUTTON_3	3
#define PUSHBUTTON_4	4

//push button modes MACROS
#define ACTIVE_LOW		0
#define ACTIVE_HIGH		1
// Conditions of PUSH buttons modes
#if PUSHBUTTON_MODE == ACTIVE_LOW

#define PRESSED			0
#define RELEASED		1

#elif PUSHBUTTON_MODE == ACTIVE_HIGH

#define PRESSED			1
#define RELEASED		0

#endif

//----------------_PROTOTYPES_---------------------------
void H_PushButton_Init(u8 PUSHBUTTON_PIN);
u8 H_PushButton_Read(u8 PUSHBUTTON_PIN);
u8 H_PushButton_Read_Pin(u8 Local_u8_PUSHBUTTON_Pin);


#endif /* PUSHBUTTON_H_ */