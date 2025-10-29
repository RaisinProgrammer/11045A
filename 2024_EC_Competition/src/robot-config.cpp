#include "vex.h"

using namespace vex;

brain Brain;

controller Controller = controller(primary);

motor L1 = motor(PORT1, ratio6_1, true);
motor L2 = motor(PORT2, ratio6_1, true);
motor L3 = motor(PORT3, ratio6_1, true);

motor R1 = motor(PORT4, ratio6_1, false);
motor R2 = motor(PORT5, ratio6_1, false);
motor R3 = motor(PORT6, ratio6_1, false);

motor Intake_Bot = motor(PORT7,ratio6_1, false);
motor Intake_Top = motor(PORT8,ratio6_1, false);


motor_group LeftMotors = motor_group(L1, L2, L3);
motor_group RightMotors = motor_group(R1, R2, R3);

digital_out Clamp1 = digital_out(Brain.ThreeWirePort.A);
digital_out Clamp2 = digital_out(Brain.ThreeWirePort.B);




inertial Inertial = inertial(PORT10);



