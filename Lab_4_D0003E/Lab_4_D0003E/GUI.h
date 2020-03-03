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
#define GUI_init(p, q) {initObject(), p, q, p, false, false} 

struct GUI_block {
	Object Super;
	pulse p; pulse q;
	pulse activePulse;
	bool heldD; bool heldU;
};

typedef struct GUI_block GUI;

void interHandlerFreq(GUI *self, int arg);
void interHandlerSwitch(GUI *self, int arg);
void switchPulse(GUI *self);
void printActivePulse(GUI *self);
void pressing(GUI *self);

#endif /* GUI_H_ */