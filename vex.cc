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
motor Motor1 = motor(PORT1, ratio18_1, false);

motor Motor3 = motor(PORT3, ratio18_1, false);

motor Motor4 = motor(PORT4, ratio18_1, false);

motor Motor5 = motor(PORT5, ratio18_1, false);

controller Controller1 = controller(primary);
motor Motor11 = motor(PORT10, ratio18_1, false);




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
  Motor1.setVelocity(Controller1.Axis3()-Controller1.Axis4()/2,percent);
  Motor5.setVelocity(Controller1.Axis3()-Controller1.Axis4()/2,percent);
  Motor4.setVelocity(Controller1.Axis3()-Controller1.Axis4()/2,percent);
  Motor3.setVelocity(Controller1.Axis3()-Controller1.Axis4()/2,percent);
  return 0;
}

void moveMotors(void){
  Motor1.spin(forward);
  Motor5.spin(reverse);
  Motor4.spin(forward);
  Motor3.spin(reverse);
  return 0;
}

void throwCatapault(){
  Motor11.spinToPosition(24,degrees);
  Motor11.spinToPosition(0,degrees);
}

int main(void){
  while (1){
    setVelocities();
    moveMotors();
    if (Controller1.ButtonB()){
      throwCatapault();
    }
  }
}
