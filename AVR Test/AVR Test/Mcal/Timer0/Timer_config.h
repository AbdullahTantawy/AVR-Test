/*
 * Timer_config.h
 *
 * Created: 5/22/2022 2:38:35 PM
 *  Author: Tantawy
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*==============================_Configutatoin_File_=======================================
-> Configutation Macros
*/

//=====================================_Choose Timer 0 Mode_===========================
/*
	1- TIMER0_NORMAL_MODE
	2- TIMER0_CTC_MODE
	3- TIMER0_FAST_PWM_MODE
	4- TIMER0_PHASE_CORRECT_MODE
*/
#define TIMER0_MODE								TIMER0_NORMAL_MODE

//=====================================_CHoose timer PRESCALER_===========================
/*
	-> TIMER0_NO_CLOCK
	-> TIMER0_NO_PRESCALER
	-> TIMER0_PRESCALER_8
	-> TIMER0_PRESCALER_64
	-> TIMER0_PRESCALER_256
	-> TIMER0_PRESCALER_1024
	-> TIMER0_PRESCALER_EXT_CLK_FALLING_EDGE
	-> TIMER0_PRESCALER_EXT_CLK_RISING_EDGE

*/
#define TIMER0_PRESCALER						TIMER0_PRESCALER_1024	

//----------------------------------------------------------------------------
/*
	-> TIMER0_OC0_DISCONNECT
	-> TIMER0_OC0_TOGGLE_ON_COMP_MATCH
	-> TIMER0_OC0_CLEAR_ON_COMP_MATCH
	-> TIMER0_OC0_SET_ON_COMP_MATCH

*/

#define TIMER0_OC0_MODE			 TIMER0_OC0_DISCONNECT




#endif /* TIMER_CONFIG_H_ */