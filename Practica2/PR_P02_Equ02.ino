int POT_sp = 1;
float sp;
int PWM_salida = 6;
float pv;


int pinA = 3;
volatile int contador = 0;
unsigned long previousMillis = 0;
long interval = 100;

float cv;
float cv1;
float error;
float error1;
float error2;

float Kp = 1;
float Ki = 1;
float Kd = 0.01;
float Tm = 0.1;

void setup(){
pinMode(pinA,INPUT);
pinMode(PWM_salida,OUTPUT);
Serial.begin(115200);
attachInterrupt(1,interrupcion,RISING);
}

void loop(){

unsigned long currentMillis = millis();

if((currentMillis - previousMillis) >= interval){

previousMillis = currentMillis;
pv = 10*contador*(60.0/374.0); //rpm eje principal
  contador = 0;
}


sp = analogRead(POT_sp) * (380.0/1023.0);
error = sp - pv;

cv = cv1 + (Kp+Kd/Tm)*error + (-Kp + Ki*Tm-2*Kd/Tm)*error1 + (Kd/Tm)*error2;
cv1 = cv;
error2 = error1;
error1 = error;

if(cv>500.0){

  cv = 500.0;
}
if(cv < 30.0){

  cv = 30.0;
}


analogWrite(PWM_salida,cv*(255.0/500.0));

Serial.print("SetPoint: ");
Serial.print(sp);
Serial.print(", RPM: ");
Serial.println(pv);

delay (100);
}

void interrupcion(){
  contador++;
}