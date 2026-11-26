
const int redLED = 8;
const int greenLED = 9;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {
  // Red LED on, green LED off
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(1000);

  // Green LED on, red LED off
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(1000);

  // Both LEDs on
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, HIGH);
  delay(1000);

  // Both LEDs off
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(1000);
}

