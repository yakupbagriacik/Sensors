// Include the required libraries
#include <Wire.h> // Library for I2C communication
#include <Adafruit_BMP085.h> // Library for BMP085 sensor

// Initialize the BMP085 sensor object
Adafruit_BMP085 bmp;

void setup() {
  // Start serial communication with baud rate of 9600
  Serial.begin(9600);

  // Check if the BMP085 sensor is connected
  if (!bmp.begin()) {
    // Print an error message to the serial monitor if the sensor is not found
    Serial.println("Sensor could not be found!");
    // Enter an infinite loop to prevent the program from continuing
    while (1) {}
  }
}

void loop() {
  // Read and print the temperature from the BMP085 sensor
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature()); // Read temperature from the sensor
  Serial.println(" *C"); // Print the temperature in degrees Celsius

  // Read and print the atmospheric pressure from the BMP085 sensor
  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure()); // Read pressure from the sensor
  Serial.println(" Pa"); // Print pressure in Pascals

  // Read and print the sea level pressure from the BMP085 sensor
  Serial.print("Sea Level Pressure = ");
  Serial.print(bmp.readSealevelPressure()); // Read sea level pressure from the sensor
  Serial.println(" Pa"); // Print sea level pressure in Pascals

  // Read and print the altitude from the BMP085 sensor
  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude(101500)); // Read altitude from the sensor with reference pressure of 101500 Pa
  Serial.println(" meters"); // Print altitude in meters above sea level

  // Add a blank line for readability
  Serial.println();

  // Wait for 2 seconds before repeating the loop
  delay(2000);
}
