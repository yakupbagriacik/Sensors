// Include the required libraries
#include <OneWire.h> // Library for 1-Wire protocol
#include <DallasTemperature.h> // Library for Dallas Temperature sensors

// Define the digital pin used to connect the temperature sensor
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);

// Initialize the DallasTemperature sensor object
DallasTemperature sensors(&oneWire);

// Initialize a variable to store the temperature in degrees Celsius
float Celsius = 0;

// Set up the Arduino board
void setup(void)
{
  // Start serial communication with baud rate of 9600
  Serial.begin(9600);

  // Initialize the temperature sensor
  sensors.begin();
}

// Continuously read and print data from the temperature sensor
void loop(void)
{
  // Request the temperature from the sensor
  sensors.requestTemperatures();

  // Read the temperature in degrees Celsius
  Celsius = sensors.getTempCByIndex(0);

  // Print the temperature to the serial monitor
  Serial.print(Celsius);
  Serial.print(" C  "); // Print the temperature in degrees Celsius and add a unit label

  // Wait for 1 second before repeating the loop
  delay(1000);
}
