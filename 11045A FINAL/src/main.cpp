/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Win Yeh                                                   */
/*    Created:      2025                                                      */
/*    Description:  WinLib Interface Class (WLIC) - Competition Template      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*==============================================================================
 * WELCOME TO WINLIB INTERFACE CLASS (WLIC)
 *==============================================================================
 *
 * Thank you for downloading this project from GitHub!
 *
 * WLIC is a powerful C++ framework for building customizable touch-based
 * graphical interfaces on VEX V5 Brain screens. This framework provides:
 *
 *   • Hierarchical navigation with parent-child interface relationships
 *   • Automatic touch detection with coordinate-based hit testing
 *   • Background update tasks for dynamic real-time displays
 *   • Run-Length Encoded (RLE) image rendering support
 *   • Callback system for custom actions on button presses
 *   • Clean state management for interface activation/deactivation
 *
 * GETTING STARTED:
 * ----------------
 * 1. Review the built-in interfaces in src/display.cpp for examples
 * 2. See API_Reference.md for complete documentation
 * 3. Customize the interfaces to match your team's needs
 * 4. Build and download to your VEX V5 Brain
 *
 * DISCLAIMER:
 * -----------
 * This software is provided "as is" without warranty of any kind, express or
 * implied. The author(s) shall not be held liable for any damages, issues, or
 * malfunctions that may arise from the use of this project. Use at your own
 * risk. Always test your code thoroughly before competition.
 *
 * Licensed under the MIT License - see LICENSE file for details.
 *
 *============================================================================*/

#include "vex.h"
using namespace vex;
competition Competition;

void pre_auton(void)
{  
  vexcodeInit();
  gyro1.calibrate();
  while (gyro1.isCalibrating()) {
    wait(10, msec);
  }
  Controller.rumble("-");
}

void autonomous(void)
{
  Test();
}

void usercontrol(void)
{
  drive();
}

int main()
{
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
