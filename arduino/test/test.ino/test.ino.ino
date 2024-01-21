#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);  // initialize serial communication
  myservo.attach(9);    // attaches the servo on pin 9 to the servo object
}

void loop() {
  if (Serial.available() > 0) {
    // read incoming serial data as a float:
    float radiansValue = Serial.parseFloat();
    
    // Convert radians to degrees:
    float degreesValue = radiansValue * (180.0 / M_PI);

    // Print radians and degrees:
    Serial.print("Radians: ");
    Serial.println(radiansValue);
    Serial.print("Degrees: ");
    Serial.println(degreesValue);

    // Map degrees to servo range (0 to 180) and write to the servo:
    myservo.write(degreesValue);

    delay(1500);
  }
}
