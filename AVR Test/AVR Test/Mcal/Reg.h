/*
 * Reg.h
 *
 * Created: 5/10/2022 10:31:06 AM
 *  Author: Tantawy
 */ 


#ifndef REG_H_
#define REG_H_

//--------------DIO_REGs_ADDRESSES_-------------------

#define DDRA	*(volatile char *)0x3A
#define PORTA	*(volatile char *)0x3B
#define PINA    *(volatile char *)0x39

#define DDRB	*(volatile char *)0x37
#define PORTB	*(volatile char *)0x38
#define PINB    *(volatile char *)0x36


#define DDRC	*(volatile char *)0x34
#define PORTC	*(volatile char *)0x35
#define PINC    *(volatile char *)0x33


#define DDRD	*(volatile char *)0x31
#define PORTD	*(volatile char *)0x32
#define PIND    *(volatile char *)0x30


//--------------EXT_INT_REGs_ADDRESSES_-------------------

#define SREG     *(volatile char *)0x5F
#define GICR     *(volatile char *)0x5B
#define MCUCR    *(volatile char *)0x55


//--------------ADC_REGs_ADDRESSES_-------------------

#define ADMUX			*(volatile char *)0x27
#define ADCSRA			*(volatile char *)0x26
#define ADCL			*(volatile char *)0x24
#define ADCH		    *(volatile char *)0x25
#define ADC_VALUE       *(volatile  u16 *)0x24




#endif /* REG_H_ */