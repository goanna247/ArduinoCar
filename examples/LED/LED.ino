#include <LED.h>
#include <ArduinoCar.h>
//include the two librarys we need for this example

DriveBase _drivebase(1, 2, 3, 4, 5, 6);
//define an instance of the drivebase class (your car) and sets the pins 
LED _led1(7,8, 9);
//define an instance of the 3 colour led class 

//this is run once when the program starts 
void setup() {
  _drivebase.IRON();
  //turn on the serial port 
}

//this runs continously 
void loop() {
  _led.ON(5);
  //turn on the LED (magenta)
  _drivebase.forwards(250, 500);
  //make the car go forwards for half a second
  _led.OFF();
  //turn the light off
  delay(1000);
  //wait 1 second
}
