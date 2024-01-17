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
motor leftMotorA = motor(PORT1, ratio18_1, false);
motor leftMotorB = motor(PORT2, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT4, ratio18_1, true);
motor rightMotorB = motor(PORT3, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 332, 285, mm, 0.7142857142857143);

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
/*    Author:       Trent Miedema                                             */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
  
// Allows for easier use of the VEX Library
using namespace vex;

void setVelocities(void){ 
  if (Controller1.ButtonR2.pressing()){ // turns right on the spot
    Motor1.setVelocity(-100,percent);
    Motor5.setVelocity(-100,percent);
    Motor4.setVelocity(-100,percent);
    Motor3.setVelocity(-100,percent);
  }
  else if (Controller1.ButtonL2.pressing()){ // turns left on the spot
    Motor1.setVelocity(100,percent);
    Motor5.setVelocity(100,percent);
    Motor4.setVelocity(100,percent);
    Motor3.setVelocity(100,percent);
  }
  else if (Controller1.ButtonR1.pressing()){ // turns right while accepting drive instructions
    Motor1.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position()/2,percent);
    Motor5.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position()/2,percent);
    Motor4.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position()/2,percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position()/2,percent);
  }
  else if (Controller1.ButtonL1.pressing()){ // turns left while accepting drive instructions
    Motor1.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position(),percent);
    Motor5.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position(),percent);
    Motor4.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position(),percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2 + Controller1.Axis1.position(),percent);
  }
  else { // default movement code
    Motor1.setVelocity(Controller1.Axis3.position()*-1,percent);
    Motor5.setVelocity(Controller1.Axis3.position(),percent);
    Motor4.setVelocity(Controller1.Axis3.position(),percent);
    Motor3.setVelocity(Controller1.Axis3.position()*-1,percent);
  }
}

void moveMotors(void){ // actually moves motors
  Motor1.spin(forward);
  Motor5.spin(forward);
  Motor4.spin(forward);
  Motor3.spin(forward);
}

void throwCatapault(void){ //This throws the catapult of Jon Devlin
  Motor6.setVelocity(100,percent);
  Motor6.spin(forward);
  MotorGroup13.spinToPosition(65,degrees);
  MotorGroup13.setVelocity(20,percent);
  MotorGroup13.spinToPosition(-10,degrees);
  MotorGroup13.setVelocity(100,percent);
  Motor6.stop();
}

void intakeCatapault(void){
  Motor6.setVelocity(100,percent);
  Motor6.spin(forward);
}

void autonomousPeriod(void){
  intakeCatapault();
  Motor1.setVelocity(100,percent);
  Motor5.setVelocity(100,percent);
  Motor4.setVelocity(100,percent);
  Motor3.setVelocity(100,percent);
  Motor1.spinFor(forward,1500,degrees, false);
  Motor3.spinFor(forward,1500,degrees, false);
  Motor4.spinFor(reverse,1500,degrees, false);
  Motor5.spinFor(reverse,1500,degrees);

  Motor1.spinFor(reverse,200,degrees, false);
  Motor3.spinFor(reverse,200,degrees, false);
  Motor4.spinFor(forward,200,degrees, false);
  Motor5.spinFor(forward,200,degrees);

  Motor1.spinFor(forward,1600,degrees, false);
  Motor3.spinFor(forward,1600,degrees, false);
  Motor4.spinFor(reverse,1600,degrees, false);
  Motor5.spinFor(reverse,1600,degrees);

  Motor1.spinFor(reverse,250,degrees, false);
  Motor3.spinFor(reverse,250,degrees, false);
  Motor4.spinFor(reverse,250,degrees, false);
  Motor5.spinFor(reverse,250,degrees);

  Motor1.spinFor(reverse,3500,degrees, false);
  Motor3.spinFor(reverse,3500,degrees, false);
  Motor4.spinFor(forward,3500,degrees, false);
  Motor5.spinFor(forward,3500,degrees);

  Motor1.spinFor(forward,250,degrees, false);
  Motor3.spinFor(forward,250,degrees, false);
  Motor4.spinFor(forward,250,degrees, false);
  Motor5.spinFor(forward,250,degrees);
  throwCatapault();
}

void getOutOfWayForAutonomous(void){
  Motor1.setVelocity(-100,percent);
  Motor5.setVelocity(-100,percent);
  Motor4.setVelocity(100,percent);
  Motor3.setVelocity(100,percent);
  Motor1.spinFor(forward,1500,degrees);
  Motor3.spinFor(forward,1500,degrees);
  Motor4.spinFor(forward,1500,degrees);
  Motor5.spinFor(forward,1500,degrees);
}

int main(void){
  MotorGroup13.setVelocity(100,percent);
  autonomousPeriod();
  while ("Jon Devlin"){
    setVelocities();
    moveMotors();
    if (Controller1.ButtonB.pressing()){
      throwCatapault();
    }
    else if (Controller1.ButtonY.pressing()){
      intakeCatapault();
    }
  }
}

// Motors 3 & 5 should be set to reverse or at least the opposite of 4 & 1
// Motors 13 & 14 should be in a motor group with 13 set to reverse
// Motor 6 should be reverse
// Make sure to connect the controller
// Make sure to praise the Dev gods
