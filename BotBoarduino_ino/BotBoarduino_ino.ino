//*********************************************************************************
// www.Lynxmotion.com
// Basic code for 2WD rover using continuous rotation servos, controlled via PS2
// Right now, the library does NOT support hot pluggable controllers, meaning 
// you must always either restart your Arduino after you connect the controller, 
// or call config_gamepad(pins) again after connecting the controller.
//*********************************************************************************

#include <PS2X_lib.h>  //for v1.6
#include <Servo.h> 
#include <stdio.h>

// create PS2 Controller Class
PS2X ps2x; 
int error = 0; 
byte vibrate = 0;

// create servo objects to control the servos
Servo servoleft; // left servo
Servo servoright; // right servo

#define Deadzone 10 //PS2 analog joystick Deadzone

void setup(){
 Serial.begin(9600);

 // Attaches servos to digital pins 3 and 4 on the BotBoarduino
 servoleft.attach(3);
 servoright.attach(4); 
 
 pinMode(7, INPUT);
 
 Serial.write("Starting program...\n");
 
 error = ps2x.config_gamepad(13,11,10,12, true, true);
 //error = ps2x.config_gamepad(9,7,6,8, true, true);   
}


void loop(){
  
  ps2x.read_gamepad();          //read controller 
  
      // This code uses the colored buttons on the right side of the joystick 
      if(ps2x.Button(PSB_RED)) {
       Serial.write("Right\n"); 
       servoleft.write(75);
       servoright.write(75);

      }
      else if(ps2x.Button(PSB_PINK)){
       Serial.write("Left\n"); 
       servoleft.write(115);
       servoright.write(115);

      }
      else if(ps2x.Button(PSB_BLUE)) {
       Serial.write("Back\n"); 
       servoleft.write(145);
       servoright.write(45);
      }
      else if(ps2x.Button(PSB_GREEN)){
       Serial.write("Forward\n"); 
       servoleft.write(45);
       servoright.write(145);

      }   
      else {
       servoleft.write(95);    // Adjust these values if the servos still move slightly
       servoright.write(95);
      }
 delay(50);
     
}


