
const int sensorPin2 = 5;  // sensor baño
const int ledPin2 = 12;    // LED baño
const int ledPin3 = 8; // LED patio
const int ldrPin = A5; // LDR 
int ldrValue = 0;

void setup() {
  // Inicialización
  Serial.begin(38400);
  pinMode(sensorPin2, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(sensorPin2, LOW);
  digitalWrite(ldrPin, LOW);
}

void loop() {

  
  //Sensor PIR baño
  if (digitalRead(sensorPin2) == HIGH) {
    digitalWrite(ledPin2, HIGH);
    Serial.println("Alguien está aquí");
    delay (3000);
  } else {
    digitalWrite(ledPin2, LOW);
    Serial.println("Nadie");
  }

  //Sensor LDR
  ldrValue = analogRead(ldrPin); 
  Serial.println(ldrValue);

  if (ldrValue >= 600){
    digitalWrite(ledPin3,HIGH);
  }
  else {
    digitalWrite(ledPin3,LOW);
  }

  delay(500);
}

