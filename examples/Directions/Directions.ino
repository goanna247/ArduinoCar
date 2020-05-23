#include <ArduinoCar.h>
//include the library

DriveBase _driveBase(4, 3, 2, 10, 9, 7);
//this defines an instance of the DriveBase (your car) and sets the ports 
//for this example we have set the ports as follows:
/*
ENA - 4
IN1 - 3
IN2 - 2
IN3 - 10
IN4 - 9
ENB - 7
and the IR remote port is always set to port 11
*/

void setup() {
  //this is called once at the beginning of our code
  //this function turns on the Serial monitor
  _driveBase.IRON();
}

void loop() {
  //this is our code which runs when we deploy the program
  //it continuously loops, running all of the code inside it 

  _driveBase.forwards(250, 100);
  //This function makes the car go forwards, it takes 2 values:
  //The first value is speed, experiment with this value, however if it gets too low your car wont move
  //The second value is the amount of time it goes forwards for in miliseconds
  //for all of the different directions you have to input these 2 values 
  _driveBase.backwards(250, 100); // go backwards 
  _driveBase.oneWheelLeft(250, 100); // turn left using only 1 side
  _driveBase.oneWheelRight(250, 100);  // turn right using only 1 side
  _driveBase.twoWheelLeft(250, 100);  // turn left using both sides
  _driveBase.twoWheelRight(250, 100); // turn right using both sides
  _driveBase.STOP(); //stop the car
  delay(1000); // wait for 1 second 
}