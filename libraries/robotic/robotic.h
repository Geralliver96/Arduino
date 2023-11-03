/*
    Nombre: robotic.h
*/

#ifndef ROBOTIC_H
#define ROBOTIC_H

#include<Arduino.h>
#include<Servo.h>


#define MOVE_CLOCKWISE 0
#define MOVE_COUNTERCLOCKWISE 1

class dcMotor
{
private:
    byte pinA;
    byte pinB;
    byte pinEn;

public:
    dcMotor(/* args */);
    dcMotor(byte A, byte B, byte en);
    ~dcMotor();
    void setup();
    void move(bool direction, byte vel);
    void stop();
};


#endif