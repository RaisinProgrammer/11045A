#include "vex.h"

using namespace vex;

void drive() {
    int Left_speed, Right_speed;
    int deadband = 5;
   

    while (true) {
        // Calculate left and right speeds based on joystick input
        Left_speed  = 6 * (Controller.Axis3.position() + Controller.Axis4.position());
        Right_speed = 6 * (Controller.Axis3.position() - Controller.Axis4.position());

        // Drive logic with deadband check for left motors
        if (abs(Left_speed) > deadband)
            LeftMotors.spin(fwd, Left_speed, rpm);                                                                
        else
            LeftMotors.stop(coast);
        
        if (abs(Right_speed) > deadband)
            RightMotors.spin(fwd, Right_speed, rpm);                                                                
        else
            RightMotors.stop(coast);

        

        // Intake motor control using button presses
        if (Controller.ButtonA.pressing()) {
            Intake_Bot.spin(fwd, -600 , rpm);
            Intake_Top.spin(fwd, -500 , rpm);
        } else if (Controller.ButtonY.pressing()) {
            Intake_Bot.spin(fwd, 600, rpm);
            Intake_Top.spin(fwd, 600, rpm);
        } else if (Controller.ButtonX.pressing()) {
            Intake_Bot.stop(brake);
            Intake_Top.stop(brake);
        }

        // Clamp control with ButtonB and ButtonR2
        if (Controller.ButtonB.pressing()) {
            Clamp1.set(true); 
            Clamp2.set(true); 
             // Clamp activated
        } else if (Controller.ButtonR2.pressing()) {
            Clamp1.set(false);
            Clamp2.set(false);  // Clamp released
        }
        else if (Controller.ButtonL2.pressing()) {
            RightMotors.spin(fwd, 220, rpm);
            LeftMotors.spin(fwd, 220, rpm);
            wait(0.7, sec);
            RightMotors.spin(fwd, -600, rpm);
            LeftMotors.spin(fwd, -600, rpm);
            //RightMotors.spin(reverse, 100, rpm);
            //LeftMotors.spin(reverse, 100, rpm);
            wait(0.5, sec);
            RightMotors.stop(coast);
            LeftMotors.stop(coast);
              // Clamp released
        }

        // Add a wait to avoid CPU overloading
        wait(25, msec);  // This needs to be inside the loop
    }
}

