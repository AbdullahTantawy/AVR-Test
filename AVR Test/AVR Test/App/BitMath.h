/*
 * BitMath.h
 *
 * Created: 5/10/2022 10:19:05 AM
 *  Author: Tantawy
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define Setbit(reg,bit)			reg|=(1<<bit)
#define Clrbit(reg,bit)			reg&=~(1<<bit)
#define Togbit(reg,bit)			reg^=(1<<bit)
#define Getbit(reg,bit)			1&(reg>>bit)


#endif /* BITMATH_H_ */