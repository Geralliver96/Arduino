//Motor-ventilador
int speedPin=9;
int dirPin1=10;
int dirPin2=13;
int speedMotor= 100;
int dt1 = 100;
int dt2 = 4000;
const int sensorPin1 = 6;  // sensor entrada
const int ledPin1 = 7;    // LED entrada

//LCD
#include <LiquidCrystal.h>
int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
int numero = 0;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

//DHT11

#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11
int dhtPin = 8;
DHT HT(dhtPin, Type);
int humidity;
float tempC;
float tempF;
int dt (500);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(38400);
  HT.begin();
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin1,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin1, OUTPUT);
   digitalWrite(sensorPin1, LOW);
}

void loop() {
  // DHT
humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  
 lcd.setCursor(0, 0);
  lcd.print("Humedad:");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C");

  delay(dt);
  lcd.clear();

  //Sensor PIR entrada
  if (digitalRead(sensorPin1) == HIGH) {
    digitalWrite(ledPin1, HIGH);
    Serial.println("Alguien está aquí");
  } else {
    digitalWrite(ledPin1, LOW);
    Serial.println("Nadie");
  }

  //Motor-ventilador
  if(tempC>=26){
    digitalWrite(dirPin1,1);
    digitalWrite(dirPin2,0);
    analogWrite(speedPin, 255);
    //delay(dt1);
    analogWrite(speedPin, speedMotor);
    //delay(dt2);
  }else{
    digitalWrite(dirPin1,0);
    digitalWrite(dirPin2,0);
    analogWrite(speedPin, 0);
    delay(dt1);
  }
 
}