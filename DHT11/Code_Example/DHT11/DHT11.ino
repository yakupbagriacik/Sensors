// Include the required libraries
#include <DFRobot_DHT11.h> // Library for DHT11 temperature and humidity sensor

// Initialize the DHT11 sensor object
DFRobot_DHT11 DHT;

// Define the pin used to connect the DHT11 sensor
#define DHT11_PIN 2

// Set up the Arduino board
void setup() {
  // Start serial communication with baud rate of 9600
  Serial.begin(9600);
}

// Continuously read and print data from the DHT11 sensor
void loop() {
  // Read the temperature and humidity from the DHT11 sensor
  DHT.read(DHT11_PIN);

  // Print the temperature to the serial monitor
  Serial.print("Temperature:");
  Serial.print(DHT.temperature); // Read temperature from the sensor
  Serial.print(" C°"); // Print the temperature in degrees Celsius

  // Print the humidity to the serial monitor
  Serial.print("  Humidity:%");
  Serial.println(DHT.humidity); // Read humidity from the sensor

  // Wait for 1 second before repeating the loop
  delay(1000);
}
