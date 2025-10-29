#include "vex.h"
using namespace vex;

//reset Motors
void motors_reset(){
    LeftMotors.resetPosition();
    RightMotors.resetPosition();
}

// Stop motors with input brake type
void motors_stop(brakeType mode){
    LeftMotors.stop(mode);
    RightMotors.stop(mode);
}

// Stop motors with velocity
void motors_spin(float L_speed, float R_speed){
    LeftMotors.spin(fwd, L_speed, rpm);
    RightMotors.spin(fwd, R_speed, rpm);
}

    // Spin motors with input voltage
void motors_spin(float L_speed, float R_speed, voltageUnits units){
    LeftMotors.spin(fwd, L_speed, volt);
    RightMotors.spin(fwd, R_speed, volt);
}

// conver heading (deg) from 360 to -180 ~ 180
double heading_convert (double heading ){


  return (heading > 180 ) ? heading - 360 : heading;
  // ( condition ) ? ture : false;
}

double in_range( double data, double high_limt, double low_limt){
    return ((data > high_limt)? high_limt : ((data < low_limt)? low_limt : data));
}

// turn with given heading (deg) and speed (rpm), use Inertial Sensor
void inertial_turn_PID ( double heading, double speed_max){
double Kp =6;
double Ki =0;
double Kd =1;
double error_INT  = 0;
double error_now  = 0;
double error_last = 0;
double real_heading = heading_convert( heading );
//reset motor
motors_reset();
// reset inertial sensor
Inertial.resetRotation();
double speed_now = 0;
int count = 0;
while( count < 10 ){
if(fabs(Inertial.rotation() - real_heading) < 2){
    count++;
}
else{
    count = 0;
}
error_now=(real_heading - Inertial.rotation());
error_INT = in_range (error_INT+error_now, 500,-500);
speed_now = in_range (Kp*(error_now)+Ki*error_INT + Kd*(error_now-error_last), speed_max, -speed_max);
motors_spin(speed_now, - speed_now);
wait(10, msec);
error_last = error_now;
}

motors_stop(hold);

}

void inertial_move(double dis, double heading, double speed_max, bool stop = true){
    double target=fabs(dis*360/(8.26*M_PI)) * (64/36);
    motors_reset();
    Inertial.resetRotation();
    double turn_speed = 0;
    double position_now = 0;
    double speed_now = 0;
    double a=5;
    int dir=1;
    if (dis<0)
    dir=-1;
    while (position_now < target){
        if (position_now<target*0.5){
            speed_now = fmin(speed_now+a, speed_max);
        }
        else if (position_now > target*0.5){
            speed_now=fmax(speed_now-a, 20);
        }

        turn_speed = (heading - Inertial.rotation())* 2;
        motors_spin(dir * speed_now + turn_speed, dir * speed_now - turn_speed);
        position_now = fabs(LeftMotors.position(deg) + RightMotors.position(deg))/2;
        wait(10,msec);
    }
    if(stop){
        motors_stop(brake);
    }
}




void auto_redright(){

    Intake_Bot.spin(fwd, -600, rpm);
    wait(1,sec);
    Intake_Bot.stop();
    inertial_move(-110,0,600);
    wait(1,sec);
    Clamp1.set(true); 
    Clamp2.set(true);
    wait(1,sec);
    Intake_Bot.spin(fwd, -600, rpm);
    Intake_Top.spin(fwd, -400, rpm);
    wait(2,sec);
    inertial_turn_PID(-65,600);
    inertial_move(90,0,600);
    wait(2,sec);
    inertial_turn_PID(190,600);
    inertial_move(145,0,600);
}
void auto_blueleft(){

    Intake_Bot.spin(fwd, -600, rpm);
    wait(1,sec);
    Intake_Bot.stop();
    inertial_move(-110,0,600);
    wait(1,sec);
    Clamp1.set(true); 
    Clamp2.set(true);
    wait(1,sec);
    Intake_Bot.spin(fwd, -600, rpm);
    Intake_Top.spin(fwd, -400, rpm);
    wait(2,sec);
    inertial_turn_PID(65,600);
    inertial_move(95,0,600);
    wait(2,sec);
    inertial_turn_PID(-190,600);
    inertial_move(160,0,600);
}




void auto_skill(){
    Intake_Bot.spin(fwd, 600, rpm);
    Intake_Top.spin(fwd, -600, rpm);
    wait(2,sec);
    Intake_Bot.stop();
    inertial_move(-5,0,600);
    inertial_move(40,0,600);
    wait(10,msec);
    inertial_turn_PID(-90,600);
    inertial_move(-75,0,600);
    wait(10,msec);
    inertial_move(-5,0,600);
    Clamp1.set(true); 
    Clamp2.set(true);// clamp
    wait(10,msec);
    Intake_Bot.spin(fwd, -600, rpm);
    Intake_Top.spin(fwd, -400, rpm);
    inertial_turn_PID(90,600);
    inertial_move(90,0,600);
    wait(1,sec);//goal
    inertial_turn_PID(70,600);
    wait(10,msec);
    inertial_move(130,0,600);
    wait(10,msec);
    inertial_turn_PID(140,600);
    inertial_move(-50,0,600);
    wait(0.5,sec);
    Clamp1.set(false); 
    Clamp2.set(false);
    inertial_move(120,0,600);
    inertial_turn_PID(300,600);
    inertial_move(90,0,600);
    inertial_turn_PID(120,600);
    Clamp1.set(true); 
    Clamp2.set(true);
    wait(1,sec);
    inertial_turn_PID(180,600);
    inertial_move(90,0,600);



    // 70(-50,600);
    // inertial_move(100,0,600);
    // wait(1,sec);
    // inertial_turn_PID(1450,600);
    // inertial_move(140,0,600);


    



    

    
 














}





