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

motor Motor3 = motor(PORT3, ratio18_1, true);

motor Motor4 = motor(PORT4, ratio18_1, false);

motor Motor5 = motor(PORT5, ratio18_1, true);

motor MotorGroup13MotorA = motor(PORT13, ratio18_1, true);
motor MotorGroup13MotorB = motor(PORT14, ratio18_1, false);
motor_group MotorGroup13 = motor_group(MotorGroup13MotorA, MotorGroup13MotorB);




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

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

void setVelocities(void){ 
  if (Controller1.ButtonA.pressing()){ // full speed ahead code
    Motor1.setVelocity(Controller1.Axis3.position(),percent);
    Motor5.setVelocity(Controller1.Axis3.position()*-1,percent);
    Motor4.setVelocity(Controller1.Axis3.position()*-1,percent);
    Motor3.setVelocity(Controller1.Axis3.position(),percent);
  }
  else if (Controller1.ButtonR1.pressing() && Controller1.ButtonL1.pressing() ||
           Controller1.ButtonR2.pressing() && Controller1.ButtonL2.pressing()){ // incase somebody is stupid
    Motor1.setVelocity(Controller1.Axis3.position()/2,percent);
    Motor5.setVelocity(Controller1.Axis3.position()/-2,percent);
    Motor4.setVelocity(Controller1.Axis3.position()/-2,percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2,percent);
  }
  else if (Controller1.ButtonR2.pressing()){ // turns right on the spot
    Motor1.setVelocity(100,percent);
    Motor5.setVelocity(100,percent);
    Motor4.setVelocity(100,percent);
    Motor3.setVelocity(100,percent);
  }
  else if (Controller1.ButtonL2.pressing()){ // turns left on the spot
    Motor1.setVelocity(-100,percent);
    Motor5.setVelocity(-100,percent);
    Motor4.setVelocity(-100,percent);
    Motor3.setVelocity(-100,percent);
  }
  else if (Controller1.ButtonR1.pressing()){ // turns right while accepting drive instructions
    Motor1.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
    Motor5.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
    Motor4.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2 + 50,percent);
  }
  else if (Controller1.ButtonL1.pressing()){ // turns left while accepting drive instructions
    Motor1.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
    Motor5.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
    Motor4.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
    Motor3.setVelocity(Controller1.Axis3.position()/2 - 50,percent);
  }
  else { // default movement code
    Motor1.setVelocity(Controller1.Axis3.position()*0.75,percent);
    Motor5.setVelocity(Controller1.Axis3.position()*-0.75,percent);
    Motor4.setVelocity(Controller1.Axis3.position()*-0.75,percent);
    Motor3.setVelocity(Controller1.Axis3.position()*0.75,percent);
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
  Motor1.setVelocity(-100,percent);
  Motor5.setVelocity(-100,percent);
  Motor4.setVelocity(100,percent);
  Motor3.setVelocity(100,percent);
  Motor1.spinFor(forward,1500,degrees);
  Motor3.spinFor(forward,1500,degrees);
  Motor4.spinFor(forward,1500,degrees);
  Motor5.spinFor(forward,1500,degrees);

  Motor1.setVelocity(100,percent);
  Motor5.setVelocity(100,percent);
  Motor4.setVelocity(-100,percent);
  Motor3.setVelocity(-100,percent);
  Motor1.spinFor(forward,6500,degrees);
  Motor3.spinFor(forward,6500,degrees);
  Motor4.spinFor(forward,6500,degrees);
  Motor5.spinFor(forward,6500,degrees);

  Motor1.setVelocity(-100,percent);
  Motor5.setVelocity(-100,percent);
  Motor4.setVelocity(-100,percent);
  Motor3.setVelocity(-100,percent);
  Motor1.spinFor(forward,500,degrees);
  Motor3.spinFor(forward,500,degrees);
  Motor4.spinFor(forward,500,degrees);
  Motor5.spinFor(forward,500,degrees);
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
