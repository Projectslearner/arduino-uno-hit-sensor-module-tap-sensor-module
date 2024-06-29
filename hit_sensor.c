/*
    Project name : Arduino Uno Hit Sensor Module
    Modified Date: 29-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-hit-sensor-module
*/

// Define the pin connected to the hit sensor module
const int hitSensorPin = 2; // Change this pin according to your setup

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize the hit sensor pin as input
  pinMode(hitSensorPin, INPUT);
}

void loop() {
  // Read the state of the hit sensor module
  int sensorValue = digitalRead(hitSensorPin);
  
  // Check if a hit or tap is detected
  if (sensorValue == HIGH) { // Assuming HIGH means a hit or tap
    Serial.println("Hit detected");
  }

  delay(100); // Delay for sensor stability and to debounce
}
