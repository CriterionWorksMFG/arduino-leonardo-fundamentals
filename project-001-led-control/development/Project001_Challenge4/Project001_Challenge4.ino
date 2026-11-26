
const int ledPin = LED_BUILTIN;

int mode = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Arduino Ready");
  Serial.println("Enter 1, 2, or 0");
}

void loop() {

  // Check for incoming commands
  if (Serial.available() > 0) {

    char command = Serial.read();

    if (command == '1') {
      mode = 1;
      Serial.println("Normal Mode");
    }
    else if (command == '2') {
      mode = 2;
      Serial.println("Warning Mode");
    }
    else if (command == '0') {
      mode = 0;
      Serial.println("System Stopped");
    }
    else if (command == '3') {
      mode = 3;
      Serial.println("Custom Mode");
    }
  }

  // Execute selected mode
  if (mode == 1) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  else if (mode == 2) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  else if (mode == 3) {
    digitalWrite(ledPin, HIGH);
    delay(500);

    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}

