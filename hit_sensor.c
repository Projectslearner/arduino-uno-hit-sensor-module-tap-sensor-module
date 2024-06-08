/*
    Project name : Tap Sensor Module with Shock Detection
    Modified Date: 08-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-hit-sensor-module-tap-sensor-module
*/

int Led = 13;    // LED on Arduino board
int Shock = 3;   // Sensor signal
int val;         // Numeric variable to store sensor status
int shockCount = 0; // Variable to store the count of shocks

unsigned long lastShockedTime = 0; // Variable to store the time of the last shock

void setup()
{
  pinMode(Led, OUTPUT);   // Define LED as output interface
  pinMode(Shock, INPUT);  // Define input for sensor signal
  Serial.begin(9600);     // Initialize Serial communication
}

void loop()
{
  val = digitalRead(Shock); // Read and assign the value of digital interface 3 to val
  
  if (val == HIGH) // When sensor detects a signal, the LED flashes and the shock count increases
  {
    digitalWrite(Led, LOW); // Turn off LED
    unsigned long currentTime = millis(); // Get current time

    // If it's been more than 1 second since the last shock, reset shock count
    if (currentTime - lastShockedTime > 1000) {
      shockCount = 1;
    } else {
      shockCount++; // Increment shock count
    }

    lastShockedTime = currentTime; // Update last shock time
    Serial.print("Shock Detected! Total Shocks: "); // Print shock count to Serial Monitor
    Serial.println(shockCount); // Print shock count to Serial Monitor
  }
  else
  {
    digitalWrite(Led, HIGH); // Turn on LED
  }
}
