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
motor MotorGroup13MotorA = motor(PORT13, ratio18_1, false);
motor MotorGroup13MotorB = motor(PORT14, ratio18_1, true);
motor_group MotorGroup13 = motor_group(MotorGroup13MotorA, MotorGroup13MotorB);

controller Controller1 = controller(primary);



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
  
// Allows for easier use of the VEX Library
using namespace vex;

void setVelocities(void){
  if (Controller1.ButtonA.pressing()){
    Motor1.setVelocity(Controller1.Axis3.position(),percent);
    Motor5.setVelocity(Controller1.Axis3.position(),percent);
    Motor4.setVelocity(Controller1.Axis3.position(),percent);
    Motor3.setVelocity(Controller1.Axis3.position(),percent);
  }
  else if (Controller1.ButtonR1.pressing() && Controller1.ButtonL1.pressing() ||
           Controller1.ButtonR2.pressing() && Controller1.ButtonL2.pressing()){
    Motor1.setVelocity(Controller1.Axis3.position()/2,percent);
    Motor5.setVelocity(Controller1.Axis3.position()/2,percent);
    Motor4.setVelocity(Controller1.Axis3.position()/2,percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2,percent);
  }
  else if (Controller1.ButtonR2.pressing()){
    Motor1.setVelocity(100,percent);
    Motor5.setVelocity(-100,percent);
    Motor4.setVelocity(-100,percent);
    Motor3.setVelocity(100,percent);
  }
  else if (Controller1.ButtonL2.pressing()){
    Motor1.setVelocity(-100,percent);
    Motor5.setVelocity(100,percent);
    Motor4.setVelocity(100,percent);
    Motor3.setVelocity(-100,percent);
  }
  else if (Controller1.ButtonR1.pressing()){
    Motor1.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
    Motor5.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
    Motor4.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
  }
  else if (Controller1.ButtonL1.pressing()){
    Motor1.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
    Motor5.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
    Motor4.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
  }
  else {
    Motor1.setVelocity(Controller1.Axis3.position()*0.75,percent);
    Motor5.setVelocity(Controller1.Axis3.position()*0.75,percent);
    Motor4.setVelocity(Controller1.Axis3.position()*0.75,percent);
    Motor3.setVelocity(Controller1.Axis3.position()*0.75,percent);
  }
}

void moveMotors(void){
  Motor1.spin(forward);
  Motor5.spin(forward);
  Motor4.spin(forward);
  Motor3.spin(forward);
}

void throwCatapault(void){
  MotorGroup13.spinToPosition(230,degrees);
  MotorGroup13.setVelocity(20,percent);
  MotorGroup13.spinToPosition(-5,degrees);
  MotorGroup13.setVelocity(100,percent);
}

int main(void){
  MotorGroup13.setVelocity(100,percent);
  while (1){
    setVelocities();
    moveMotors();
    if (Controller1.ButtonB.pressing()){
      throwCatapault();
    }
  }
}
