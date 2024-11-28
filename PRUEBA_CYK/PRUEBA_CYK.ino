int sensor = 2;
int led1 = 3;
int valor=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(sensor, INPUT);
pinMode(led1, OUTPUT);  
digitalWrite(led1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
valor = digitalRead(sensor);
digitalWrite(led1, valor);
Serial.println(valor);

}