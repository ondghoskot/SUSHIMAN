// Testing Servo with the esp32

#include <ESP32Servo.h>

Servo myServo;

// Define servo pin
const int servoPin = 18;

// Servo positions
const int CLOSED_POSITION = 0;    // Gate closed (no food)
const int OPEN_POSITION = 90;     // Gate open (dispense food)

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  Serial.println("ESP32 Servo Test Starting...");
  
  myServo.attach(servoPin);
  
  // Start at closed position
  myServo.write(CLOSED_POSITION);
  Serial.println("Servo initialized at CLOSED position");
  
  delay(1000);
}

void loop() {
  // Simulate feeding cycle
  Serial.println("Opening gate - Dispensing food...");
  myServo.write(OPEN_POSITION);
  delay(2000);  // Keep open for 2 seconds
  
  Serial.println("Closing gate...");
  myServo.write(CLOSED_POSITION);
  delay(5000);  // Wait 5 seconds before next dispense
  
}

