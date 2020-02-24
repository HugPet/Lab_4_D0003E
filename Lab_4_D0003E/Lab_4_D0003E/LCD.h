/*
 * LCD.h
 *
 * Created: 2020-02-24 16:11:48
 *  Author: User
 */ 

// .h for lcd manipulation

#include <stdbool.h>

#ifndef LCD_H_
#define LCD_H_


void printAt(long num, int pos);
void writeChar(char ch, int pos);
int writeReg(int num, int reg, bool shift);
void LCDInit();


#endif /* LCD_H_ */