int LEDr = 2;
int LEDa = 3;
int LEDv = 4;
int LDR = A0;
int buttonPin = A1;

bool isNormalCycle = true;
unsigned long previousMillis = 0;
int lightState = 0; // 0: Rojo, 1: Verde, 2: Amarillo
int durations[3] = {5000, 5000, 2000}; // Rojo, Verde, Amarillo duracion
int currentDuration = 0;

void setup() {
  pinMode(LEDr, OUTPUT);
  pinMode(LEDa, OUTPUT);
  pinMode(LEDv, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  updateTrafficLight(0); // Empieza con luz verde
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int LDR_valor = analogRead(LDR);
  float LDR_val = (LDR_valor * 5.0) / 1023.0;

  if (buttonState == LOW) {
    // Se presiona el botón y se activa el modo peatón
    pedestrianMode();
  } else if (isNormalCycle) {
    // Luz de semáforo normal dependiente de la luz de ambiente
    if (millis() - previousMillis >= currentDuration) {
      // Cambio al siguiente estado del ciclo
      previousMillis = millis();
      lightState = (lightState + 1) % 3; // Ciclo por los estados
      updateTrafficLight(lightState);

      // Ajuste la duración en función de la intensidad de la luz
      if (LDR_val <= 2) {
        durations[0] = 5000; // Duracion LED rojo
        durations[1] = 5000; // Duracion LED verde
        durations[2] = 2000; // Duracion LED amarillo
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
  // Parar modo normal
  isNormalCycle = false;
  updateTrafficLight(0); // Poner en rojo
  delay(10000);          // 10 seg para cruce de peatones
  isNormalCycle = true;
  previousMillis = millis();
  lightState = 0;        // Reset a estado rojo
  currentDuration = durations[0];
}

void updateTrafficLight(int state) {
  switch (state) {
    case 0: // Estado rojo
      digitalWrite(LEDr, HIGH);
      digitalWrite(LEDa, LOW);
      digitalWrite(LEDv, LOW);
      break;
    case 1: // Estado verde
      digitalWrite(LEDr, LOW);
      digitalWrite(LEDa, LOW);
      digitalWrite(LEDv, HIGH);
      break;
    case 2: // Estado amarillo
      digitalWrite(LEDr, LOW);
      digitalWrite(LEDa, HIGH);
      digitalWrite(LEDv, LOW);
      break;
  }
}