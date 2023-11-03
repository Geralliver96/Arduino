void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(6, INPUT);
  digitalWrite(6,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(6)==HIGH){
    Serial.println("Somebody is here");
  }else{
    Serial.println("Nobody");
  }
delay(800);
}
