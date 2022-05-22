/*
 * Puzzer.h
 *
 * Created: 5/15/2022 11:22:12 AM
 *  Author: Tantawy
 */ 


#ifndef PUZZER_H_
#define PUZZER_H_

#include "PuzzerCfg.h"
#include "Dio.h"

#define F_CPU 16000000UL
#include "util/delay.h"

void H_Buzzer_Init(void);
void H_Buzzer_On(void);
void H_Buzzer_Off(void);
void H_Buzzer_Once(void);
void H_Buzzer_OnceLong(void);
void H_Buzzer_Twice(void);

#endif /* PUZZER_H_ */