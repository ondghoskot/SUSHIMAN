// Testing Servo with the esp32

#include <ESP32Servo.h>

Servo myServo;

// Define servo pin
const int servoPin = 18;

// Servo positions
const int CLOSED_POSITION = 0;    // Gate closed (no food)
const int OPEN_POSITION = 90;     // Gate open (dispense food) somehow a 98 degree difference looks more like 90 degrees, let's keep it 90 for now

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  Serial.println("ESP32 Servo Test Starting...");
  
  myServo.attach(servoPin);
  
  // Start at closed position
  myServo.write(CLOSED_POSITION); // Any servo has a default 0 degree position, wait for it to turn there then fix the desired arm on that angle
  Serial.println("Servo initialized at CLOSED position");
  
  delay(1000);
}

void loop() {
  // Simulate feeding cycle
  Serial.println("Opening gate - Dispensing food...");
  myServo.write(OPEN_POSITION);
  delay(3000);  // Keep open for 3 seconds
  
  Serial.println("Closing gate...");
  myServo.write(CLOSED_POSITION);
  delay(3000);  // Wait 3 seconds before next dispense (testing)
  
}

