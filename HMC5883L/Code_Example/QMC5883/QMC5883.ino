// Include required libraries
#include <Wire.h>
#include <DFRobot_QMC5883.h>

// Create an object of DFRobot_QMC5883 class
DFRobot_QMC5883 compass;

void setup()
{
  // Start serial communication
  Serial.begin(115200);

  // Check if the sensor is connected
  while (!compass.begin())
  {
    Serial.println("Could not find a valid 5883 sensor, check wiring!");
    delay(500);
  }

  // Check the type of sensor and initialize it accordingly
  if (compass.isHMC()) {
    Serial.println("Initialize HMC5883");
    //compass.setRange(HMC5883L_RANGE_1_3GA);
    //compass.setMeasurementMode(HMC5883L_CONTINOUS);
    //compass.setDataRate(HMC5883L_DATARATE_15HZ);
    //compass.setSamples(HMC5883L_SAMPLES_8);
  } else if (compass.isQMC()) {
    Serial.println("Initialize QMC5883");
    //compass.setRange(QMC5883_RANGE_2GA);
    //compass.setMeasurementMode(QMC5883_CONTINOUS);
    //compass.setDataRate(QMC5883_DATARATE_50HZ);
    //compass.setSamples(QMC5883_SAMPLES_8);
  } else if (compass.isVCM()) {
    Serial.println("Initialize VCM5883L");
    //compass.setMeasurementMode(VCM5883L_CONTINOUS);
    //compass.setDataRate(VCM5883L_DATARATE_200HZ);
  }

  // Delay for 1 second
  delay(1000);
}

void loop()
{
  // Set the declination angle for your location to correct the heading
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / PI);
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);

  // Read the raw data from the sensor
  Vector mag = compass.readRaw();

  // Get the heading in degrees
  compass.getHeadingDegrees();

  // Print the heading
  Serial.println(mag.HeadingDegress);

  // Delay for 100ms
  delay(100);
}
