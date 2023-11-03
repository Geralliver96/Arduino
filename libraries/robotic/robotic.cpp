#include"robotic.h"


dcMotor::dcMotor(/* args */)
{
    pinA = 8;
    pinB = 7;
    pinEn = 6;
}
dcMotor::dcMotor(byte A, byte B, byte en)
{
    pinA = A;
    pinB = B;
    pinEn = en;
}

dcMotor::~dcMotor()
{
}
void dcMotor::setup(){
    pinMode(pinA,OUTPUT);
    pinMode(pinB,OUTPUT);
    pinMode(pinEn,OUTPUT);
}
void dcMotor::move(bool direction, byte vel){
    if(!direction){
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB,LOW);
    }else{
        digitalWrite(pinB,HIGH);
        digitalWrite(pinA,LOW);
    }
    analogWrite(pinEn,vel);
}
void dcMotor::stop(){
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,LOW);
    analogWrite(pinEn,0);
}