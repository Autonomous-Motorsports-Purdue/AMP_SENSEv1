#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <cfloat>
#include <utility/imumaths.h>

#define DECIMALS 4

// Check I2C device address and correct line below (by default address is 0x29
// or 0x28)
//                                   id, address
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void setup(void) {
  Serial.begin(115200);

  /* Initialise the sensor */
  if (!bno.begin(OPERATION_MODE_NDOF)) {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print(
        "Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1)
      ;
  }

  delay(1000);

  /* Use external crystal for better accuracy */
  bno.setExtCrystalUse(true);
}

void loop(void) {
  sensors_event_t orientationData, velocityData;

  // Absolute Position
  bno.getEvent(&orientationData);
  Serial.print("ox:");
  Serial.print(orientationData.orientation.x, DECIMALS);
  Serial.print(",oy:");
  Serial.print(orientationData.orientation.y, DECIMALS);
  Serial.print(",oz:");
  Serial.print(orientationData.orientation.z, DECIMALS);

  // Angular Rate
  bno.getEvent(&velocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
  Serial.print(",ax:");
  Serial.print(velocityData.gyro.x, DECIMALS);
  Serial.print(",ay:");
  Serial.print(velocityData.gyro.y, DECIMALS);
  Serial.print(",az:");
  Serial.print(velocityData.gyro.z, DECIMALS);
  Serial.println();
  // delay(3);
}
