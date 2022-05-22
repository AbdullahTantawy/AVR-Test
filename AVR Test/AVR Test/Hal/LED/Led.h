/*
 * Led.h
 *
 * Created: 5/10/2022 12:53:03 PM
 *  Author: Tantawy
 */ 


#ifndef LED_H_
#define LED_H_



//-------------------------_MACROS_------------------

#define RED_LED		1
#define BLU_LED		2
#define GRN_LED		3
//-------------------------_INCLUDES_------------------
#include "LedCfg.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "Std.h"
//-------------------------_PROTOTYPES_------------------------
void H_Led_Init(u8 local_u8_Led);  // Initialize the pins of led 
void H_Led_On(u8 local_u8_Led);
void H_Led_Off(u8 local_u8_Led);
void H_Led_Tog(u8 local_u8_Led);
void H_Led_BlinkOnce(u8 local_u8_Led);
void H_Led_Blinktwice(u8 local_u8_Led);



#endif /* LED_H_ */