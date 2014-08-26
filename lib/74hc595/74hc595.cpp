#include "arduino.h"
#include "lib74hc595.h"

ShiftRegister::ShiftRegister(int latch, int clock, int data)
: latchPin(latch), clockPin(clock), dataPin(data)
{
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void ShiftRegister::Begin(void)
{
    digitalWrite(latchPin, LOW);
}

void ShiftRegister::Output(int mode, byte data)
{
    shiftOut(dataPin, clockPin, mode, data);
}
void ShiftRegister::Output16(int mode, int data)
{
    if( mode == LSBFIRST )
    {
        shiftOut(dataPin, clockPin, mode, (data   )&0xFF);
        shiftOut(dataPin, clockPin, mode, (data>>8)&0xFF);
    }
    else
    {
        shiftOut(dataPin, clockPin, mode, (data>>8)&0xFF);
        shiftOut(dataPin, clockPin, mode, (data   )&0xFF);
    }
}

void ShiftRegister::End(void)
{
    digitalWrite(latchPin, HIGH);
}

