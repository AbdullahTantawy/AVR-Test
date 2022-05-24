/*
 * Timer_interface.h
 *
 * Created: 5/22/2022 2:39:10 PM
 *  Author: Tantawy
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/*==============================================_Interfacing_File_Content_==================================================
1- Global MACROS
2- Functions Prototypes
==================================================================================================*/

//===========================_PROTOTYPES_================

void M_Timer0_vInit(void);
void M_Timer0_vStop(void);
void M_Timer0_vStart(void);
void M_Timer0_vSetPreload(u8 copy_u8Preload);
void M_Timer0_vSetCompMatch(u8 copy_u8CompValue);
void M_Timer0_vSetCallBack( void(*copy_ptrCallBack)(void) , u8 copy_IntID);
void M_Timer0_vIntEnable(u8 copy_IntID);
void M_Timer0_vIntDisable(u8 copy_IntID);

//======================_Global_MACROS_======================

#define TIMER0_OVF_INT_ID	0
#define TIMER0_CTC_INT_ID	1


#endif /* TIMER_INTERFACE_H_ */