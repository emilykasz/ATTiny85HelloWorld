//variables for the LED
int LED = 1;

// variables for the button
int buttonPin = 0;
boolean buttonState = false;
boolean prevButtonState = false;

// variable for the switch state
int switchVal = 2;

//variables for the timer
unsigned long startTime;
unsigned long endTime;
unsigned long interval = 100;

void setup() {

  //sets up the serial monitor
  Serial.begin(9600);
  //initalizes the button
  pinMode(buttonPin, INPUT);
  //initalizes the LED
  pinMode(LED, OUTPUT);

  //initalizes the timer
  startTime = millis();
}

void loop() {

  //uses the debounce function to set the buttonState variable
  buttonState = Debounce(buttonPin, prevButtonState);

  // changes the states when the button is pressed
  if (buttonState == HIGH && prevButtonState == LOW) {
    switchVal = switchVal + 1;
    if (switchVal == 3) {
      switchVal = 0;
    }
  }

  switch (switchVal) {

    case  0: // the LED is off
      digitalWrite(LED, LOW);
      break;

    case 1: // the LED is on
      digitalWrite(LED, HIGH);
      break;

    case 2: // the LED blinks every 100 ms
      endTime = millis();
      if (endTime - startTime >= interval) {
        digitalWrite(LED, HIGH);
        startTime = millis();
        digitalWrite(LED, LOW);
      }
      break;
  }
  prevButtonState = buttonState;
}

// function that allows the button to act when pressed once and again when pressed again
boolean Debounce (int aRandomButtonPin, boolean aPrevButtonState) {
  boolean aButtonState = digitalRead(aRandomButtonPin);
  if (aButtonState != aPrevButtonState) {
    delay(5);
    aButtonState = digitalRead(aRandomButtonPin);
  }
  return aButtonState;
}
