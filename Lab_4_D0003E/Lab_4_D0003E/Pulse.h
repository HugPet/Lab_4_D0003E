/*
 * Pulse.h
 *
 * Created: 2020-02-24 15:55:16
 *  Author: User
 */ 

// .h for pulse object

#include <stdbool.h>
#include <avr/io.h>
#ifndef PULSE_H_
#define PULSE_H_
#define NULL 0
#define initPulse(r, t) {false, r, 0, t}

struct pulse_block 
{
	bool active;
	int freq;
	int saved_freq;
	int pos;
};

typedef struct pulse_block pulse;

void activate(pulse *p);
void deactivate(pulse *p);
void subFreq(pulse *p);
void addFreq(pulse *p);
void storeFreq(pulse *p);
void restoreFreq(pulse *p);
int getFreq(pulse *p);
int getPos(pulse *p);



#endif /* PULSE_H_ */