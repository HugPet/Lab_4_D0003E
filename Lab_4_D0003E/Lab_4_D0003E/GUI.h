/*
 * GUI.h
 *
 * Created: 2020-02-29 12:02:42
 *  Author: User
 */ 

#include "TinyTimber.h"
#include "pulse.h"
#include "LCD.h"
#include <stdbool.h>
#ifndef GUI_H_
#define GUI_H_
#define GUI_init(p, q) {initObject(), p, q, 0} 

struct GUI_block {
	Object Super;
	pulse p; pulse q;
	char pulseSwitch;
};

typedef struct GUI_block GUI;

void interHandlerFreq(GUI *g, enum Vector v);
void switchPulse(GUI *g);
void printActivePulse(GUI *g);


#endif /* GUI_H_ */