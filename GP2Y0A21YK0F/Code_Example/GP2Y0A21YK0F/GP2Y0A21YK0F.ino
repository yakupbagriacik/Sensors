// Include the required libraries
#include <SharpIR.h> // Library for Sharp Infrared distance sensors

// Define the analog pin used to connect the IR distance sensor
#define IRPin A0

// Define the model of the Sharp IR sensor used
#define model 1080

// Initialize a variable to store the measured distance in centimeters
double distance_cm;

// Initialize the SharpIR sensor object
SharpIR mySensor = SharpIR(IRPin, model);

// Set up the Arduino board
void setup() {
  // Start serial communication with baud rate of 9600
  Serial.begin(9600);
}

// Continuously read and print the distance data from the IR sensor
void loop() {
  // Measure the distance using the SharpIR sensor
  distance_cm = mySensor.distance();

  // Print the distance in centimeters to the serial monitor
  Serial.print("Mean distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Wait for 1 second before repeating the loop
  delay(1000);
}
