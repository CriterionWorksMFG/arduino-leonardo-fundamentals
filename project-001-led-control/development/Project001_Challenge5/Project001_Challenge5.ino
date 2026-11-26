
const int ledPin = LED_BUILTIN;

unsigned long previousMillis = 0;
const unsigned long interval = 250;

bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    ledState = !ledState;

    digitalWrite(ledPin, ledState);
  }
}
