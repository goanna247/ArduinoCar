# ArduinoCar

This Arduino library is specially built for use with an Arduino uno and a L298N motor controller with 4 wheels. 
The aim was to allow more people to code these fun little robots, the library makes it a lot easier to code the robot and hopefully will provide you with a base knowledge for you to add more complex features. 



# Wiring diagrams 
When I was first building these cars there wasn’t many accessible wiring diagrams around, so just to make the process a little simpler I thought I would provide one to you here:
![GitHub Logo](/images/robotWiringDiagram.png)
# How to set up the library 
I am assuming you already have the Arduino IDE already downloaded, if you haven’t there are loads of tutorials online on how to download it 
So, to download the library, start by clicking the green clone or download button in the top right-hand corner and download it as a ZIP file. 
You want to then extract the file to your Arduino libraries folder; this will probably be in your documents folder. 
To check that the library has been properly installed, restart your IDE and go into file/examples and scroll all the way down to the bottom where you should find the ArduinoCar library. 
After you have ensured that the library is properly installed you should go to https://www.arduinolibraries.info/libraries/i-rremote and install the IR sensor library. 
There are 2 example sketches in the ArduinoCar library, Directions and Controller. I recommend playing around with directions to start off with then going to controller. 
# Functions of the library 
To start you must include the library, and the IR sensor libraries. Then you must create an instance of the object DriveBase and set up your ports (ENA, IN1, IN2, IN3, IN4, ENB), the IR sensor is always on port 11. 
In void setup you must call the IRON() function which was supposed to read IR on but now it’s just a metal. This will start the serial port and start up the IR sensor.
There are 7 different directions forwards, backwards, oneWheelLeft, oneWheelRight, twoWheelLeft, twoWheelRight and STOP. Each direction takes 2 inputs speed and time, speed should be over 200 or there is a possibility the car won’t move. wait Time is for how long it should go for. (STOP does not take any input). 
To call one of these directions you first need to call the name of your DriveBase instance then the function.

To call the Controller function you must first setup the receiving HEX values, to do this go into the IR remote library examples and go to IRrecvDemo. This will display the HEX values received by your IR sensor on the Serial monitor. On your remote press the button you want to make the car drive forwards and check what the value is, it should be something like 0xFF629D. 
Do this for forwards, backwards, left and right then assign these values to unsigned long variables (don’t worry if you don’t understand this, you just need to put the value into the example code where it says forwards and so on.)
Then you just call these 4 variables in your Controller function. This will allow your car to be driven. 
* just a note about controlling the car, if you press the button on the controller really quickly the IR sensor won’t detect you stopped clicking so it will run until you press another button. You can use this to your advantage making your car drive long distances. But if you just want a shorter drive hold the button down for half a second. 

# What's next?
I will be making updates every month to provide more features. I recommend if you are getting bored to try and set up an ultrasonic sensor to detect whether the robot is about to hit a wall.
