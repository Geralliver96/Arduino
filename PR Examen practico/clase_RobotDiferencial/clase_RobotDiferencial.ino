#include <Arduino.h>

#define MOVE_FORWARD true
#define MOVE_BACWARD false

class RobotDiferencial {

  public:

    RobotDiferencial(float radioRueda, float distanciaRuedas, uint8_t mra, uint8_t mrb, uint8_t mre, uint8_t mla, uint8_t mlb, uint8_t mle ) {
      _radioRueda = radioRueda;
      _distanciaRuedas = distanciaRuedas;
      motorRPinA  = mra;
      motorRPinB  = mrb;
      motorRPinEN  = mre;
      motorLPinA  = mla;
      motorLPinB  = mlb;
      motorLPinEN  = mle;
    }

    void setup(){
      pinMode(motorRPinA,OUTPUT);
      pinMode(motorRPinB,OUTPUT);
      pinMode(motorLPinA,OUTPUT);
      pinMode(motorLPinB,OUTPUT);
      pinMode(motorLPinEN,OUTPUT);
      pinMode(motorRPinEN,OUTPUT);
      
    }

    void mover(bool M, float Vel, float  ang) {
      if(M){
        digitalWrite(motorRPinA,HIGH);
        digitalWrite(motorRPinB,LOW);
        digitalWrite(motorLPinA,HIGH);
        digitalWrite(motorLPinB,LOW);
      }else{
        digitalWrite(motorRPinB,HIGH);
        digitalWrite(motorRPinA,LOW);
        digitalWrite(motorLPinB,HIGH);
        digitalWrite(motorLPinA,LOW);

      }
      velR = Vel/_radioRueda + ang*_distanciaRuedas/(2*_radioRueda);
      velL = Vel/_radioRueda - ang*_distanciaRuedas/(2*_radioRueda);
      analogWrite(motorLPinEN,int(velL));
      analogWrite(motorRPinEN,int(velR));
      
    }

  private:

    float _radioRueda;
    float _distanciaRuedas;
    uint8_t motorRPinA;
    uint8_t motorRPinB;
    uint8_t motorRPinEN;
    uint8_t motorLPinA;
    uint8_t motorLPinB;
    uint8_t motorLPinEN;
    float velR;
    float velL;

};

RobotDiferencial robot(2,4,5,7,8,6,9,10);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
    robot.setup();

};
  // put your setup code here, to run once:

void loop() {
  // put your main code here, to run repeatedly:
  robot.mover(MOVE_FORWARD,75,0.3);

}
