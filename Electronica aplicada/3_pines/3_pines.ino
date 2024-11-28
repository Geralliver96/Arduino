
const int pin1 = 2; 
const int pin2 = 3;
const int pin3 = 4;

void setup() {
 
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT);
}

void loop() {
  
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);  
  digitalWrite(pin3, HIGH);
  delay(2000); 
  
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);

  delay(1000);
}