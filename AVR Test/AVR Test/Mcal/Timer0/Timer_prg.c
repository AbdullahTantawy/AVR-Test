/*
 * Timer_prg.c
 *
 * Created: 5/22/2022 2:37:07 PM
 *  Author: Tantawy
 */ 

/*==============================================_Programme_File_Content_==================================================
1- Global Variables
2- Functions Implementation 
==================================================================================================*/

//===========================_INCLUDES_=======================

#include "Std.h"
#include "BitMath.h"
#include "Timer_private.h"
#include "Timer_config.h"
#include "Timer_interface.h"
#include <avr/interrupt.h>
//----------------------------------------------------------------------------------------------------------
//two global pointers to functions
void (*pv_CallBackArr[2])(void) = {NULL};

//===========================_FUNCTIOSNS_BODIES_================

void M_Timer0_vInit(void)
{
	#if				TIMER0_MODE		==		TIMER0_NORMAL_MODE
		Clrbit(TIMER0_TCCR0,TCCR0_WGM00);
		Clrbit(TIMER0_TCCR0,TCCR0_WGM01);
		//OC0 MODE
		#if (TIMER0_OC0_MODE >= 0 &&  TIMER0_OC0_MODE <= 3 )
			TIMER0_TCCR0 &= TIMER0_OC0_MASK;
			TIMER0_TCCR0 |= (TIMER0_OC0_MODE << 4);
		#else
			#error ("conflicting modes")
        #endif
	
	#elif			TIMER0_MODE		==		TIMER0_CTC_MODE
		Clrbit(TIMER0_TCCR0,TCCR0_WGM00);
		Setbit(TIMER0_TCCR0,TCCR0_WGM01);
		//OC0 MODE
		#if (TIMER0_OC0_MODE >= 0 &&  TIMER0_OC0_MODE <= 3 )
		TIMER0_TCCR0 &= TIMER0_OC0_MASK;
		TIMER0_TCCR0 |= (TIMER0_OC0_MODE << 4);
		#else
			#error ("conflicting modes")
		#endif
	
	#elif			TIMER0_MODE		==		TIMER0_FAST_PWM_MODE
		Setbit(TIMER0_TCCR0,TCCR0_WGM00);
		Setbit(TIMER0_TCCR0,TCCR0_WGM01);
	
	#elif			TIMER0_MODE		==		TIMER0_PHASE_CORRECT_MODE
		Setbit(TIMER0_TCCR0,TCCR0_WGM00);
		Clrbit(TIMER0_TCCR0,TCCR0_WGM01);
	#else
		#error ("Wrong mode")
	#endif

}

//----------------------------------------------------------------------------------------------------------
void M_Timer0_vStop(void)
{
	// 1- Clear the three bits of the prescaler
	TIMER0_TCCR0 &= TIMER0_PRESCALER_MASK;
	TIMER0_TCCR0 |= TIMER0_NO_CLOCK;
}
//----------------------------------------------------------------------------------------------------------

void M_Timer0_vStart(void)
{
	// 1- Clear the three bits of the prescaler
	// 2- mask the prescaler
	TIMER0_TCCR0 &= TIMER0_PRESCALER_MASK;
	TIMER0_TCCR0 |= TIMER0_PRESCALER;
}
//----------------------------------------------------------------------------------------------------------

void M_Timer0_vSetPreload(u8 copy_u8Preload)
{
		TIMER0_TCCR0 = copy_u8Preload;
}
//----------------------------------------------------------------------------------------------------------

void M_Timer0_vSetCompMatch(u8 copy_u8CompValue)
{
		TIMER0_OCR0 = copy_u8CompValue;
}
//----------------------------------------------------------------------------------------------------------

void M_Timer0_vSetCallBack( void(*copy_ptrCallBack)(void) , u8 copy_IntID)
{
	
	switch(copy_IntID)
	{
		case TIMER0_OVF_INT_ID:
			pv_CallBackArr[TIMER0_OVF_INT_ID] = copy_ptrCallBack;
		break;
		case TIMER0_CTC_INT_ID:
			pv_CallBackArr[TIMER0_CTC_INT_ID] = copy_ptrCallBack;
		break;
		default: 
		return;
	}
}
//----------------------------------------------------------------------------------------------------------

void M_Timer0_vIntEnable(u8 copy_IntID)
{
	switch(copy_IntID)
	{
		case TIMER0_OVF_INT_ID:
			Setbit(TIMER_TIMSK,TIMSK_OVIE);
			break;
		case TIMER0_CTC_INT_ID:
			Setbit(TIMER_TIMSK,TIMSK_OCIE);
			break;
		default:
		return; // error state
	}
}
//----------------------------------------------------------------------------------------------------------

void M_Timer0_vIntDisable(u8 copy_IntID)
{
	switch(copy_IntID)
	{
		case TIMER0_OVF_INT_ID:
			Clrbit(TIMER_TIMSK,TIMSK_OVIE);
		break;
		case TIMER0_CTC_INT_ID:
			Clrbit(TIMER_TIMSK,TIMSK_OCIE);
		break;
		default:
		return;
	}
}

//----------------------------------------------------------------------------------------------------------

ISR(TIMER0_COMP_vect)
{
	static u8 counter=0;
	counter++;
	if (counter == 63)
	{
		counter=0;
		pv_CallBackArr[TIMER0_CTC_INT_ID]();
	}
	
}
//----------------------------------------------------------------------------------------------------------

ISR(TIMER0_OVF_vect)
{
	static u8 counter=0;
	counter++;
	if (counter == 63)
	{
		counter=0;
		pv_CallBackArr[TIMER0_OVF_INT_ID]();
	}
}