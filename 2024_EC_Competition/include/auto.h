#include "vex.h"

// Reset Motors
void motors_reset();

// Stop motors with input brake type
void motors_stop(brakeType mode);

// stop motors with input velocity
void motors_spin(float L_speed, float R_speed);

// Spin motors with input voltage
void motors_spin(float L_speed, float R_speed, voltageUnits units);

// conver heading (deg) from 360 to -180 ~ 180
double heading_convert (double heading );

//
double in_range( double data, double high_limt, double low_limt);

// turn with given heading (deg) and speed (rpm), use Inertial Sensor
void inertial_turn_PID ( double heading, double speed_max);


void inertial_move(double dis, double heading, double speed_max, bool stop = true);

void auto_blueleft();

void auto_blueright();

void auto_redright();

void auto_redleft();

void bluerighttest();

void bluelefttest();

void auto_skill();