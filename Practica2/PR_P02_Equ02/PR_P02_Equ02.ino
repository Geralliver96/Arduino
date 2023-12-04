int POT_sp = 1; 
float sp;
int PWM_salida = 6;
int PWM_salida2 = 5;
float pv;
float vl_deseada; // velocidad lineal deseada en m/s
int rad = 10; // radio de la rueda en cm


int pinA = 3;
volatile int contador = 0;
unsigned long previousMillis = 0; 
long interval = 100;

float cv;
float cv1;
float cv2;
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
  pinMode(PWM_salida2,OUTPUT);
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

  // Leer velocidad lineal deseada
  vl_deseada = 2; // m/s
  
  // Convertir a rpm
  sp = (vl_deseada * 60) / (2 * 3.1416 * rad/100); 
  
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
  analogWrite(PWM_salida2,cv*(255.0/500.0));

  Serial.print("SetPoint: ");
  Serial.print(sp);
  Serial.print(", RPM: ");
  Serial.print(pv);
  Serial.print(" , Velocidad lineal: ");
  Serial.println(vl_deseada);

  delay (100);
}

void interrupcion(){
  contador++;
}