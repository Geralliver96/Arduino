#include<robotic.h>
dcMotor ML(7,8,9);

long int ts, tp, ta;
int Prev, dp, Pp, Pa;
float rev, rpm;
void cuenta();

void setup() {
  // put your setup code here, to run once:
  ts = 500;
  tp = 0;
  ta = 0;
  Pp = 0;
  Pa = 0;
  Prev = 20;

  ML.setup();
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3),cuenta,FALLING);
  Serial.begin(9600);
  ML.move(MOVE_CLOCKWISE,255);

}

void loop() {
  tp = millis();
  if(tp-ta>1000){
    noInterrupts();
    dp = Pp - Pa;
    rev = dp/Prev;
    rpm = (rev/ts)*60000;
     Serial.println(rpm);
    Pa = Pp;
    interrupts();
    ta = tp;
  }
  // put your main code here, to run repeatedly:

}
void cuenta(){
  ++Pp;
}
