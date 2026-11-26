
const int redLED = 8;
const int greenLED = 9;

const int button1 = 2;
const int button2 = 3;

const unsigned long debounceDelay = 50;

// 0 = Stop, 1 = Red, 2 = Green
int mode = 0;

// Button tracking
int lastReading1 = HIGH;
int stableState1 = HIGH;
unsigned long lastChange1 = 0;

int lastReading2 = HIGH;
int stableState2 = HIGH;
unsigned long lastChange2 = 0;

// Prevent restart after both buttons
bool stopLatch = false;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);

  Serial.begin(9600);
  Serial.println("Control Panel Ready");
}

void loop() {
  unsigned long now = millis();

  int reading1 = digitalRead(button1);
  int reading2 = digitalRead(button2);

  bool press1 = false;
  bool press2 = false;

  // Debounce Button 1
  if (reading1 != lastReading1) {
    lastChange1 = now;
  }

  if (now - lastChange1 >= debounceDelay) {
    if (reading1 != stableState1) {
      stableState1 = reading1;
      if (stableState1 == LOW) {
        press1 = true;
      }
    }
  }
  lastReading1 = reading1;

  // Debounce Button 2
  if (reading2 != lastReading2) {
    lastChange2 = now;
  }

  if (now - lastChange2 >= debounceDelay) {
    if (reading2 != stableState2) {
      stableState2 = reading2;
      if (stableState2 == LOW) {
        press2 = true;
      }
    }
  }
  lastReading2 = reading2;

  // Both pressed: latch Stop mode
  if (stableState1 == LOW &&
      stableState2 == LOW) {

    if (!stopLatch) {
      mode = 0;
      stopLatch = true;
      Serial.println("STOP");
    }
  }

  // Wait until both buttons are released
  else if (stopLatch) {
    if (stableState1 == HIGH &&
        stableState2 == HIGH) {
      stopLatch = false;
    }
  }

  // Respond only to new button presses
  else if (press1) {
    mode = 1;
    Serial.println("RED MODE");
  }
  else if (press2) {
    mode = 2;
    Serial.println("GREEN MODE");
  }

  digitalWrite(redLED, mode == 1 ? HIGH : LOW);
  digitalWrite(greenLED, mode == 2 ? HIGH : LOW);
}

