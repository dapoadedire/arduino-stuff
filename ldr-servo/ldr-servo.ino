#include <Servo.h>

const int alertLedPin = 2;
const int gatePin = 3;
const int ldrPin = A0;
const int threshold = 50;  // Adjust this value according to your lighting conditions

Servo gateServo;

void setup() {
  pinMode(alertLedPin, OUTPUT);
  gateServo.attach(gatePin);
  gateServo.write(0);  // Setting the initial position of the servo to 0 degrees (closed)
}

void loop() {
  // Read the value from the LDR
  int ldrValue = analogRead(ldrPin);

  // Check if it is above the threshold
  if (ldrValue > threshold) {
    // If above the threshold, open the gate
    gateServo.write(90);  // Set the servo angle to 90 degrees (open)
    digitalWrite(alertLedPin, HIGH);  // Turn on the alert LED
  } else {
    // If below the threshold, close the gate
    gateServo.write(0);  // Set the servo angle to 0 degrees (closed)
    digitalWrite(alertLedPin, LOW);  // Turn off the alert LED
  }

  delay(100);  // Adjust this delay as needed
}
