#include <ArduinoCar.h>
#include <Ultrasonic.h>
//include the librarys 

DriveBase _driveBase(1, 2, 3, 4, 5, 6);
//this defines an instance of the driveBase ( your car) and sets the ports 
UltraSonic _ultrasonic(7);
 
void setup() {
  //called at the beginning of the code
  _drivebase.IRON();
}

void loop() {
  //this runs constantly when you deploy the program. 
  
}