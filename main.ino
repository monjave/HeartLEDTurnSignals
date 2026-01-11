// LED Pin Definitions for Left and Right Signals
int leftPins[] = { 4, 5, 6, 7, 8, 9, 10 };         // Left LEDs
int rightPins[] = { 11, 12, 13, A0, A1, A2, A3 };  // Right LEDs

// Button Pins
int leftButtonPin = 2;
int rightButtonPin = 3;
int hazardButtonPin = A4;

// Toggle States for Left, Right, and Hazard Lights
bool leftSignalOn = false;
bool rightSignalOn = false;
bool hazardOn = false;

// Button State Tracking
bool lastLeftButtonState = HIGH;
bool lastRightButtonState = HIGH;
bool lastHazardButtonState = HIGH;

// Timing Variables
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
const int ledInterval = 500;  // LED blink interval

unsigned long previousLeftMillis = 0;
unsigned long previousRightMillis = 0;

int currentLeftLed = 0;
int currentRightLed = 0;

// Flags for Initial Flashing
bool leftInitialFlashDone = false;
bool rightInitialFlashDone = false;

void setup() {
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);
  pinMode(hazardButtonPin, INPUT_PULLUP);

  for (int i = 0; i < 7; i++) {
    pinMode(leftPins[i], OUTPUT);
    pinMode(rightPins[i], OUTPUT);
  }
}

void loop() {
  bool leftButtonState = digitalRead(leftButtonPin);
  bool rightButtonState = digitalRead(rightButtonPin);
  bool hazardButtonState = digitalRead(hazardButtonPin);

  // Detect button press for left signal
  if (leftButtonState == LOW && lastLeftButtonState == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    leftSignalOn = !leftSignalOn;
    rightSignalOn = false;
    hazardOn = false;
    leftInitialFlashDone = false;
    lastDebounceTime = millis();
  }

  // Detect button press for right signal
  if (rightButtonState == LOW && lastRightButtonState == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    rightSignalOn = !rightSignalOn;
    leftSignalOn = false;
    hazardOn = false;
    rightInitialFlashDone = false;
    lastDebounceTime = millis();
  }

  // Detect button press for hazard lights
  if (hazardButtonState == LOW && lastHazardButtonState == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    hazardOn = !hazardOn;
    leftSignalOn = false;
    rightSignalOn = false;
    lastDebounceTime = millis();
  }

  lastLeftButtonState = leftButtonState;
  lastRightButtonState = rightButtonState;
  lastHazardButtonState = hazardButtonState;

  // Left Signal
  if (leftSignalOn) {
    if (!leftInitialFlashDone) {
      flashAllLEDs(leftPins);
      leftInitialFlashDone = true;
    }
    runLEDSequence(leftPins, currentLeftLed, previousLeftMillis);
  } else {
    turnOffLEDs(leftPins);
    currentLeftLed = 0;
  }

  // Right Signal
  if (rightSignalOn) {
    if (!rightInitialFlashDone) {
      flashAllLEDs(rightPins);
      rightInitialFlashDone = true;
    }
    runLEDSequence(rightPins, currentRightLed, previousRightMillis);
  } else {
    turnOffLEDs(rightPins);
    currentRightLed = 0;
  }

  // Hazard Lights (all LEDs flash together)
  if (hazardOn) {
    static unsigned long lastHazardFlash = 0;
    static bool hazardState = false;

    if (millis() - lastHazardFlash >= ledInterval) {
      lastHazardFlash = millis();
      hazardState = !hazardState;

      for (int i = 0; i < 7; i++) {
        digitalWrite(leftPins[i], hazardState ? HIGH : LOW);
        digitalWrite(rightPins[i], hazardState ? HIGH : LOW);
      }
    }
  } else if (!leftSignalOn && !rightSignalOn) {
    turnOffLEDs(leftPins);
    turnOffLEDs(rightPins);
    currentLeftLed = 0;
    currentRightLed = 0;
  }

}

// Function to flash all LEDs twice at the beginning & end
void flashAllLEDs(int pins[]) {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(pins[i], HIGH);
    }
    delay(500);
    for (int i = 0; i < 7; i++) {
      digitalWrite(pins[i], LOW);
    }
    delay(500);
  }
}

// Function to run LED sequence (non-blocking)
void runLEDSequence(int pins[], int &currentLed, unsigned long &prevMillis) {
  unsigned long currentMillis = millis();

  if (currentMillis - prevMillis >= ledInterval) {
    prevMillis = currentMillis;

    if (currentLed > 0) {
      digitalWrite(pins[currentLed - 1], LOW);
    }

    if (currentLed < 7) {
      digitalWrite(pins[currentLed], HIGH);
      currentLed++;
    } else {
      flashAllLEDs(pins);  // Flash at the end
      currentLed = 0;
    }
  }
}

// Function to turn off all LEDs
void turnOffLEDs(int pins[]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], LOW);
  }
}