int LEDr = 2;
int LEDa = 3;
int LEDv = 4;
int LDR = A0;
int buttonPin = A1;

bool isNormalCycle = true;
unsigned long previousMillis = 0;
int lightState = 0; // 0: Red, 1: Green, 2: Yellow
int durations[3] = {5000, 5000, 2000}; // Red, Green, Yellow durations
int currentDuration = 0;

void setup() {
  pinMode(LEDr, OUTPUT);
  pinMode(LEDa, OUTPUT);
  pinMode(LEDv, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  updateTrafficLight(0); // Start with red light
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int LDR_valor = analogRead(LDR);
  float LDR_val = (LDR_valor * 5.0) / 1023.0;

  if (buttonState == LOW) {
    // Button pressed - switch to pedestrian mode
    pedestrianMode();
  } else if (isNormalCycle) {
    // Normal traffic light cycle based on light conditions
    if (millis() - previousMillis >= currentDuration) {
      // Move to the next state in the cycle
      previousMillis = millis();
      lightState = (lightState + 1) % 3; // Cycle through states
      updateTrafficLight(lightState);

      // Adjust durations based on light intensity
      if (LDR_val <= 2) {
        durations[0] = 5000; // Red duration
        durations[1] = 5000; // Green duration
        durations[2] = 2000; // Yellow duration
      } else {
        durations[0] = 2000;
        durations[1] = 2000;
        durations[2] = 1000;
      }
      currentDuration = durations[lightState];
    }
  }
}

void pedestrianMode() {
  // Stop the normal cycle
  isNormalCycle = false;
  updateTrafficLight(0); // Set to red
  delay(10000);          // 10 seconds for pedestrian crossing
  isNormalCycle = true;
  previousMillis = millis();
  lightState = 0;        // Reset to red state
  currentDuration = durations[0];
}

void updateTrafficLight(int state) {
  switch (state) {
    case 0: // Red
      digitalWrite(LEDr, HIGH);
      digitalWrite(LEDa, LOW);
      digitalWrite(LEDv, LOW);
      break;
    case 1: // Green
      digitalWrite(LEDr, LOW);
      digitalWrite(LEDa, LOW);
      digitalWrite(LEDv, HIGH);
      break;
    case 2: // Yellow
      digitalWrite(LEDr, LOW);
      digitalWrite(LEDa, HIGH);
      digitalWrite(LEDv, LOW);
      break;
  }
}