
const int ledPin = LED_BUILTIN;

// Operating mode
int mode = 0;

// LED state
bool ledState = LOW;

// Timing variables
unsigned long previousMillis = 0;
unsigned long onTime = 1000;
unsigned long offTime = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);

  Serial.println("Controller Ready");
  Serial.println("0=Stop 1=Normal 2=Warning 3=Custom");
}

void loop() {

  // TASK 1: Read incoming commands
  if (Serial.available() > 0) {

    char command = Serial.read();

    if (command == '0') {
      mode = 0;
      Serial.println("STOP");
    }
    else if (command == '1') {
      mode = 1;
      onTime = 1000;
      offTime = 1000;
      Serial.println("NORMAL");
    }
    else if (command == '2') {
      mode = 2;
      onTime = 100;
      offTime = 100;
      Serial.println("WARNING");
    }
    else if (command == '3') {
      mode = 3;
      onTime = 500;
      offTime = 1500;
      Serial.println("CUSTOM");
    }
    else if (command == '4') {
      mode = 4;
      onTime = 50;
      offTime = 950;
      Serial.println("HEARTBEAT");
    }

    // Restart LED timing after valid command
    if (command >= '0' && command <= '4') {
      previousMillis = millis();

      if (mode == 0) {
        ledState = LOW;
      }
      else {
        ledState = HIGH;
      }

      digitalWrite(ledPin, ledState);
    }
  }

  // TASK 2: Control LED without delay()
  if (mode != 0) {

    unsigned long currentMillis = millis();

    unsigned long interval;

    if (ledState == HIGH) {
      interval = onTime;
    }
    else {
      interval = offTime;
    }

    if (currentMillis - previousMillis >= interval) {

      previousMillis = currentMillis;

      ledState = !ledState;

      digitalWrite(ledPin, ledState);
    }
  }
}
