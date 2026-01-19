#include "vex.h"

void drive() {
    int Left_speed, Right_speed;
    int deadband = 5;
    bool intakeOn = false; 
    bool R2Prev = false;
 
    while (true) {
        // Drive control
        bool R1Now = Controller.ButtonR1.pressing();
        bool R2Now = Controller.ButtonR2.pressing();
        Left_speed  = (Controller.Axis3.position() + Controller.Axis1.position());
        Right_speed = (Controller.Axis3.position() - Controller.Axis1.position());
 
        if (abs(Left_speed) > deadband) {
            Left.spin(reverse, Left_speed, pct);
        } else {
            Left.stop(brake);
        }
        if (abs(Right_speed) > deadband) {
            Right.spin(reverse, Right_speed, pct);
        } else {
            Right.stop(brake);
        }
        if (R1Now && !R2Prev) {  
            intakeOn = !intakeOn;   // flip the motor state
        }
        if (intakeOn) {
            intake.spin(fwd, 100, pct);
            storage.spin(reverse, 100, pct);
        } else {
            intake.stop();
            storage.stop();
        }
    }
}