#include "vex.h"
using namespace vex;

brain Brain; 
controller Controller = controller(primary);

motor L1 = motor(PORT18, ratio6_1, false);  
motor L2 = motor(PORT19, ratio6_1, false); 
motor L3 = motor(PORT20, ratio6_1, false); 
motor_group Left = motor_group(L1, L2, L3);

motor R1 = motor(PORT8, ratio6_1, true);  
motor R2 = motor(PORT3, ratio6_1, true);  
motor R3 = motor(PORT10, ratio6_1, true); 
motor_group Right = motor_group(R1, R2, R3);

motor storage = motor(PORT17, ratio6_1, false);
motor puke = motor(PORT5, ratio6_1, false);
motor intake = motor(PORT4, ratio6_1, true);


inertial gyro1 = inertial(PORT6);

digital_out piston = digital_out(Brain.ThreeWirePort.G);
digital_out piston2 = digital_out(Brain.ThreeWirePort.H);

void vexcodeInit(void) 
{
    // Nothing to initialize
}