/*
 * LCD.c
 *
 * Created: 2020-02-24 16:11:57
 *  Author: User
 */ 

// .c for lcd manipulation

#include "LCD.h"
#include "DediWriter.h"

void LCDInit(void){

	LCDCRB = (1<<LCDMUX1)|(1<<LCDMUX0)|(1<<LCDPM2)|(1<<LCDPM1)|(1<<LCDPM2);
	LCDFRR = (0<<LCDPS2)|(0<<LCDPS1)|(0<<LCDPS0)|(1<<LCDCD2)|(1<<LCDCD1)|(1<<LCDCD0);
	LCDCCR = (0<<LCDDC2)|(0<<LCDDC1)|(0<<LCDDC0)|(1<<LCDCC3)|(1<<LCDCC2)|(1<<LCDCC1)|(1<<LCDCC0);
	LCDCRA = (1<<LCDEN)|(1<<LCDAB)|(0<<LCDIE)|(0<<LCDBL);
	
	TCCR1B = (0<<WGM13)|(1<<WGM12)|(0<<WGM11)|(0<<WGM10)|(1<<CS12)|(0<<CS11)|(1<<CS10);
	
	EIMSK |= (1<<PCIF1)|(1<<PCIF0);
	PORTB = (1<<PB7)|(1<<PB6);
	DDRB = (0<<DDB7)|(0<<DDB6);
	MCUCR = (0 << PUD);
}

void printAt(long num, int pos) {
	int pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
}

