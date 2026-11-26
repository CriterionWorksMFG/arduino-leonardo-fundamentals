
const int ledPin = 8;
const int buttonPin = 2;

bool ledState = LOW;

int buttonState = HIGH;
int lastButtonReading = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
}

void loop() {

  // Read the physical button
  int reading = digitalRead(buttonPin);

  // Detect a change in the raw reading
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // Only accept a stable reading
  if (millis() - lastDebounceTime > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      // Only toggle on a confirmed press
      if (buttonState == LOW) {
        ledState = !ledState;

        digitalWrite(ledPin, ledState);

        Serial.println(
          ledState ? "LED ON" : "LED OFF"
        );
      }
    }
  }

  lastButtonReading = reading;
}

