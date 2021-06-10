#ifndef TASK_MOTOR
#define TASK_MOTOR
#include <Arduino.h>
#include "config.h"

extern bool flag_when_run_done[MAX_NUMBER_MOTOR];
extern bool save_distant_from_setup[MAX_NUMBER_MOTOR];
extern bool status_motor_is_running[MAX_NUMBER_MOTOR];
extern bool flag_send_data_to_app;
//---variable for value current off positon motor
struct current_motor
{
    /* data */
    uint32_t current_motor_1;
    uint32_t current_motor_2;
    uint32_t current_motor_3;
    uint32_t current_motor_4;
    uint32_t current_motor_5;
    uint32_t current_motor_6;
};

//---value save in eeprom----
struct distant_motor
{
    /* data */
    uint32_t distant_motor_1;
    uint32_t distant_motor_2;
    uint32_t distant_motor_3;
    uint32_t distant_motor_4;
    uint32_t distant_motor_5;
    uint32_t distant_motor_6;
};

extern struct current_motor current_distant_motor;
extern struct distant_motor value_distant_motor;


void sendDistanttoApp();
bool check_done_step();
////////////////////////
void motor1_stop();
void motor2_stop();
void motor3_stop();
void motor4_stop();
void motor5_stop();
void motor6_stop();
///////////////////////
void motor1_open();
void motor2_open();
void motor3_open();
void motor4_open();
void motor5_open();
void motor6_open();
/////////////////////////
void motor1_close();
void motor2_close();
void motor3_close();
void motor4_close();
void motor5_close();
void motor6_close();
#endif
