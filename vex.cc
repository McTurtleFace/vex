#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
controller Controller1 = controller(primary);
motor Motor1 = motor(PORT1, ratio18_1, false);

motor Motor3 = motor(PORT3, ratio18_1, false);

motor Motor4 = motor(PORT4, ratio18_1, false);

motor Motor5 = motor(PORT5, ratio18_1, false);

motor Motor6 = motor(PORT6, ratio18_1, false);

digital_out DigitalOutA = digital_out(Brain.ThreeWirePort.A);



// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/


// Include the V5 Library
#include "vex.h"
#include <cmath>
 // Allows for easier use of the VEX Library
using namespace vex;


void setVelocities(int front){
 int motorOne = ( (abs(Controller1.Axis1.position) < 10)? (Controller1.Axis3.position()):((Controller1.Axis3.position()+Controller1.Axis1.position())/2) ) * front;
 int motorThree = ( (abs(Controller1.Axis1.position) < 10)? (Controller1.Axis3.position()):((Controller1.Axis3.position()+Controller1.Axis1.position())/2) ) * front;
 int motorTwo = -1 * ( (abs(Controller1.Axis1.position) < 10)? (Controller1.Axis3.position()):((Controller1.Axis3.position()-Controller1.Axis1.position())/2) ) * front;
 int motorFour = -1 * ( (abs(Controller1.Axis1.position) < 10)? (Controller1.Axis3.position()):((Controller1.Axis3.position()-Controller1.Axis1.position())/2) ) * front;


 Motor1.setVelocity(motorOne,percent);
 Motor3.setVelocity(motorTwo,percent);
 Motor4.setVelocity(motorThree,percent);
 Motor5.setVelocity(motorFour,percent);
}

void moveMotors(void){
 Motor1.spin(forward);
 Motor3.spin(forward);
 Motor4.spin(forward);
 Motor5.spin(forward);
}

void intake(){
 Motor7.setVelocity(50,percent);
 Motor7.spin(reverse);
}


void outtake(){
 Motor7.setVelocity(50,percent);
 Motor7.spin(forward);
}

void autonomous(void){
 Motor1.setVelocity(100,percent);
 Motor3.setVelocity(100,percent);
 Motor4.setVelocity(-100,percent);
 Motor5.setVelocity(-100,percent);

 moveMotors();
}

void opcontrol(void) {
 int frontDirection = 1, wingsOut = 0, intakeRunning = 0;
 DigitalOutA.set(false);
 Motor8.setVelocity(100,percent);
 Motor9.setVelocity(-100,percent);

 while (1){
   if (Controller1.ButtonB.pressed()) frontDirection = frontDirection * (-1);

   if (Controller1.ButtonR1.pressed()){
     Motor8.spinFor(reverse,1,degrees,false);
   }
   else if (Controller1.ButtonR2.pressed()){
     Motor8.spinFor(forward,1,degrees,false);
   }
   else if (Controller1.ButtonL1.pressed()){
     Motor9.spinFor(reverse,1,degrees,false);
   }
   else if (Controller1.ButtonL2.pressed()){
     Motor9.spinFor(forward,1,degrees,false);
   }
   
   setVelocities(frontDirection);
   moveMotors();
   if (Controller1.ButtonA.pressed()) {
     intake();
     intakeRunning = 1;
   }
   else if (Controller1.ButtonB.pressed()) {
     outtake();
     intakeRunning = 1;
   }
   else if (intakeRunning && Controller1.ButtonX.pressed()) {
     Motor7.stop();
     intakeRunning = 0;
   }
 }
}



