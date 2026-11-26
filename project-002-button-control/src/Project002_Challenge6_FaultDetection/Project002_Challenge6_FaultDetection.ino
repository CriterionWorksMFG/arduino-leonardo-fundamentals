
const int redLED = 8;
const int greenLED = 9;

const int button1 = 2;
const int button2 = 3;

const unsigned long debounceDelay = 50;

// States
const int STOP = 0;
const int WARNING = 1;
const int NORMAL = 2;
const int FAULT = 3;

int mode = STOP;

bool faultActive = false;
bool stopLatch = false;

bool redState = LOW;
unsigned long previousBlinkMillis = 0;

// Button tracking
int lastReading1 = HIGH;
int stableState1 = HIGH;
unsigned long lastChange1 = 0;

int lastReading2 = HIGH;
int stableState2 = HIGH;
unsigned long lastChange2 = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);

  Serial.begin(9600);

  Serial.println("Controller Ready");
  Serial.println("F = Simulate Fault");
  Serial.println("R = Reset Fault");
}

void loop() {
  unsigned long now = millis();

  // Read serial commands
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'F') {
      faultActive = true;
      mode = FAULT;
      Serial.println("FAULT ACTIVE");
    }

    if (command == 'R' && faultActive) {
      faultActive = false;
      mode = STOP;
      stopLatch = true;
      Serial.println("FAULT RESET");
    }
  }

  // Read buttons
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

  // Fault takes priority
  if (faultActive) {
    mode = FAULT;
  }

  // Normal button operation
  else if (stableState1 == LOW &&
           stableState2 == LOW) {

    mode = STOP;
    stopLatch = true;
  }

  else if (stopLatch) {
    if (stableState1 == HIGH &&
        stableState2 == HIGH) {
      stopLatch = false;
    }
  }

  else if (press1) {
    mode = WARNING;
    Serial.println("WARNING");
  }

  else if (press2) {
    mode = NORMAL;
    Serial.println("NORMAL");
  }

  // LED outputs
  if (mode == NORMAL) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  else if (mode == WARNING ||
           mode == FAULT) {

    unsigned long interval =
      (mode == WARNING) ? 200 : 500;

    digitalWrite(greenLED, LOW);

    if (now - previousBlinkMillis >= interval) {
      previousBlinkMillis = now;
      redState = !redState;
    }

    digitalWrite(redLED, redState);
  }

  else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    redState = LOW;
  }
}

