#include <Servo.h>

const int redPin = 2;
const int yellowPin = 3;
const int greenPin = 4;
const int gatePin = 9;

const int redDuration = 5000;
const int yellowDuration = 2000;
const int greenDuration = 5000;

Servo gateServo;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);


  gateServo.attach(gatePin);  // Attaching the servo to the gatePin
  gateServo.write(0);         // Setting the initial position of the servo to 0 degrees (closed)
}

void loop() {
  // Red light
  digitalWrite(redPin, HIGH);
  gateServo.write(0);  
  delay(redDuration);
  digitalWrite(redPin, LOW);

  // Yellow light
  digitalWrite(yellowPin, HIGH);
  gateServo.write(0);  
  delay(yellowDuration);
  digitalWrite(yellowPin, LOW);

  // Green light
  digitalWrite(greenPin, HIGH);
  gateServo.write(90);  
  delay(greenDuration);
  digitalWrite(greenPin, LOW);
}
