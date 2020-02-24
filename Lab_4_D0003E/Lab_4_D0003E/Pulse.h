/*
 * Pulse.h
 *
 * Created: 2020-02-24 15:55:16
 *  Author: User
 */ 

#include <stdbool.h>
#ifndef PULSE_H_
#define PULSE_H_
#define initPulse() {false, 0, 0}

typedef struct  
{
	bool active;
	int freq;
	int saved_freq;
} pulse;

void subFreq(pulse p);
void addFreq(pulse p);
void storeFreq(pulse p);
void restoreFreq(pulse p);



#endif /* PULSE_H_ */