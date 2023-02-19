// Define the pins used for the ultrasonic sensor
const int trigger_pin = 2;
const int echo_pin = 3;

// Initialize variables to store the time passed and distance measured
int time_passed;
int distance;

// Set up the Arduino board
void setup() {
  // Set the trigger pin as an output
  pinMode(trigger_pin, OUTPUT);
  // Set the echo pin as an input
  pinMode(echo_pin, INPUT);

  // Start serial communication with baud rate of 9600
  Serial.begin(9600);
}

// Continuously read and print the distance data from the ultrasonic sensor
void loop() {
  // Generate a 10 microsecond pulse on the trigger pin to initiate a measurement
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  // Measure the time for the echo signal to be received and convert it to distance in centimeters
  time_passed = pulseIn(echo_pin, HIGH);
  distance = (time_passed / 2) / 29.1; //29.1 is a constant that can change with temprature

  // Print the measured distance in centimeters to the serial monitor
  Serial.print("Distance = ");
  Serial.println(distance);

  // Wait for 500 milliseconds before repeating the loop
  delay(500);
}
