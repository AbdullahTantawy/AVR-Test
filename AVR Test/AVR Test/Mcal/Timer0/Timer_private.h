/*
 * Timer_private.h
 *
 * Created: 5/22/2022 2:37:40 PM
 *  Author: Tantawy
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


/*==============================================_Private_File_Content_==================================================
1- Private MACROS
2- Registers
3- Bits
4- Static functions prototypes 
==================================================================================================*/

//--------------_TIMER0_REGs_ADDRESSES_-------------------

#define TIMER0_TCCR0			*((volatile char *)0x53)
#define TIMER0_TCNT0			*((volatile char *)0x52)
#define TIMER0_OCR0				*((volatile char *)0x5C)
						 				   	   
#define TIMER_TIMSK				*((volatile char *)0x59)
#define TIMER_TIFR				*((volatile char *)0x58)

//---------------------_BITs_MACROS_-----------------------------------------------------------------------------------
// TIMER0_TCCR0_BITS
#define TCCR0_FOC0						7	//force output compare
#define TCCR0_WGM01						3	// Waveform Generation Mode
#define TCCR0_WGM00						6	// Waveform Generation Mode
#define TCCR0_COM00						4	//  Compare Output Match Mode
#define TCCR0_COM01						5	//  Compare Output Match Mode
#define TCCR0_CS00						0   
#define TCCR0_CS01						1	// THREE PINS TO SELECT THE CLOCK (PRESCALE)
#define TCCR0_CS02						2
 // TIMER TIMSK BITS (INTERRUPTS ENABLE)
#define TIMSK_OCIE						1	 // OVERFLOW INTERRUPT ENABLE	TIFR
#define TIMSK_OVIE						0	 // OUTPUT COMPARE INTERRUPT ENABLE
// TIMER TIFR BITS (FLAGS)
#define TIFR_OCF						1	 // OVERFLOW FLAG
#define TIFR_OVF						0	 // OUTPUT COMPARE FLAG

//-------------------------------------------------------------------------------------------------------------
// Timer 0 Mode
#define TIMER0_NORMAL_MODE					0  // numbers such as the number in  the table
#define TIMER0_CTC_MODE						1
#define TIMER0_FAST_PWM_MODE				2
#define TIMER0_PHASE_CORRECT_MODE			3

//------------------------------------------------------------------------------------------------------------
// TIMRE0 PRESSCALER

#define TIMER0_NO_CLOCK								0
#define TIMER0_NO_PRESCALER							1
#define TIMER0_PRESCALER_8							2
#define TIMER0_PRESCALER_64							3
#define TIMER0_PRESCALER_256						4
#define TIMER0_PRESCALER_1024						5
#define TIMER0_PRESCALER_EXT_CLK_FALLING_EDGE		6
#define TIMER0_PRESCALER_EXT_CLK_RISING_EDGE		7

#define TIMER0_PRESCALER_MASK			(0XF8)

//----------------------------------------------------------------------------------------------------

#define TIMER0_OC0_DISCONNECT											0
#define TIMER0_OC0_TOGGLE_ON_COMP_MATCH									1
#define TIMER0_OC0_CLEAR_ON_COMP_MATCH									2
#define TIMER0_OC0_SET_ON_COMP_MATCH3

// FAST PWM MODE
#define TIMER0_OC0_DISCONNECT											0						
#define TIMER0_OC0_CLEAR_ON_COMP_MATCH_SET_BUTTOM						2
#define TIMER0_OC0_SET_ON_COMP_MATCH_CLEAR_BUTTOM						3


#define TIMER0_OC0_MASK					(0XCF)


/*
#define TIMER0_OC0_FAST_INVERTED
#define TIMER0_OC0_FAST_NONINVERTED
*/
#endif /* TIMER_PRIVATE_H_ */