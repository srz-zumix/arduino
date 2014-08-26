#ifndef lib74hc595_H_
#define lib74hc595_H_
#include "arduino.h"

class ShiftRegister
{
public:
	ShiftRegister(int latch, int clock, int data);
	
public:
	void Begin(void);
	void Output(int mode, byte data);
	void Output16(int mode, int data);
	void End(void);
	
private:
	int latchPin, clockPin, dataPin;
};

#endif
