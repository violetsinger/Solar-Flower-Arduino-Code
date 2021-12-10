
//Violet Singer
//NMD 211
//Final Project - Lab
//December 10, 2021

#include <Servo.h>                           // The servo library

int sensorPin = A0;                          // The number of the pin that the photoresistor is connected to
int servoPin = 9;                            // The number of the pin that the motor is connected to

int sensorValue = 0;                         // Sets an integer variable that will enter the value read by the loop ()
int servoGra0d = 90;                         // The degrees of the start position of the flower
int tollerance = 40;                         // The tolerance within which the servo does not rotate even if the sensor detects variations from the central value

Servo myservo;                               // Initializes the servo by assigning it to the myservo instance

void setup() {
pinMode( sensorPin, INPUT);                  // Sets the pin to where the sensor is connected in INPUT mode
myservo.attach( servoPin );                  // Using the attach method, tell which pin the servomotor is connected to
myservo.write( servoGrad );                  // With the write  method set the starting degrees

void loop() {
sensorValue = analogRead(sensorPin);         // Read the value from the pin A0 and assign it to the sensorValue variable
if ( sensorValue < (512-tollerance) )        // Check if the value is less than the difference between 512 and the set tolerance 
{
if (servoGrad < 180) servoGrad++;            // Perform a further check that the servo is not > 180. The servoGrad value is increased from 90 to 91,92,93 ...
}
if ( sensorValue > (512+tollerance) )        // The value read by the sensor is compared with the total of 512 + tolerance
{
if (servoGrad > 0) servoGrad--;              // Check that servo angle is not less than 0,then decreases the servoGrad value
}

myservo.write( servoGrad );                  // Move the servo to the correct position

delay(1000);                                 // wait 100 milliseconds between detections
}
