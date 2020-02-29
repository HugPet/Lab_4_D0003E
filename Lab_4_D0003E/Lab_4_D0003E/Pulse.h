/*
 * Pulse.h
 *
 * Created: 2020-02-24 15:55:16
 *  Author: User
 */ 

// .h for pulse object

#include "TinyTimber.h"
#include <stdbool.h>
#include <avr/io.h>
#ifndef PULSE_H_
#define PULSE_H_
#define NULL 0
#define initPulse(r, t) {initObject(), r, 0, t}

struct pulse_block 
{
	Object Super;
	int freq;
	int saved_freq;
	int portNum;
};

typedef struct pulse_block pulse;

void subFreq(pulse *p);
void addFreq(pulse *p);
void storeFreq(pulse *p);
void restoreFreq(pulse *p);
int getFreq(pulse *p);



#endif /* PULSE_H_ */