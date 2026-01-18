#include "vex.h"

void Heading( double heading, double error_threshold) {
    double heading_error, heading_pre_error = 0, trn_kp = 1, trn_kd = 0;
    int count = 0;
    while(count<10){
        heading_error = heading - gyro1.heading(degrees);
        if (heading_error > 180){
            heading_error -= 360;
        } else if (heading_error < -180){
            heading_error += 360;
        }
        double trn_speed = heading_error * trn_kp + (heading_error - heading_pre_error) * trn_kd;
        trn_speed = fmax( fmin(trn_speed, 12), -12);
        Left.spin(fwd, trn_speed, volt);
        Right.spin(fwd, -trn_speed, volt);
        heading_pre_error = heading_error;
        if (fabs(heading_error) < error_threshold) {
            count++;
        } else {
            count=0;
        }
        wait(10, msec);
    }
    Left.stop(brake);
    Right.stop(brake);
}
void Move(double deg, double max_speed, double heading) {
    double heading_error, heading_pre_error = 0, trn_kp = 1, trn_kd = 0, 
    deg_error = 0, move_kp = 1, position = 0, base_speed = 1;
    Left.resetPosition();
    Right.resetPosition();
    while(position < deg){
        position = (Left.position(degrees) + Right.position(degrees)) * 0.5;
        double str_error = deg - position;
        double str_speed = str_error * move_kp + base_speed;
        str_speed = fmax ( fmin(str_speed, max_speed), -max_speed);
        heading_error = heading - gyro1.heading(degrees);
        if (heading_error > 180){
            heading_error -= 360;
        } else if (heading_error < -180){
            heading_error += 360;
        }
        double trn_speed = heading_error * trn_kp + (heading_error - heading_pre_error) * trn_kd;
        trn_speed = fmax( fmin(trn_speed, 12), -12);
        Left.spin(fwd, str_speed + trn_speed, volt);
        Right.spin(fwd, str_speed -trn_speed, volt);
        heading_pre_error = heading_error;
        wait(10, msec);
    }
}