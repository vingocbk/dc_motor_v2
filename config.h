#ifndef APP_CONFIG
#define APP_CONFIG

#define L1_UP                   4
#define L1_DOWN                 5
#define L2_UP                   13
#define L2_DOWN                 14
#define L3_UP                   16
#define L3_DOWN                 17
#define L4_UP                   18
#define L4_DOWN                 19
#define L5_UP                   21
#define L5_DOWN                 22
#define L6_UP                   23
#define L6_DOWN                 25
#define hallSensor1a            26
#define hallSensor2a            27
#define hallSensor3a            32
#define hallSensor4a            33
#define hallSensor5a            34
#define hallSensor6a            35
//#define hallSensor6a            15
#define PIN_SET_UP_OPEN_CLOSE   0       //ON NORMAL MODE
#define PIN_SWITCH_MODE_SETUP   15      //ON SETUP MODE

#define CHANEL_MOTOR_1_UP       0
#define CHANEL_MOTOR_1_DOWN     1
#define CHANEL_MOTOR_2_UP       2
#define CHANEL_MOTOR_2_DOWN     3
#define CHANEL_MOTOR_3_UP       4
#define CHANEL_MOTOR_3_DOWN     5
#define CHANEL_MOTOR_4_UP       6
#define CHANEL_MOTOR_4_DOWN     7
#define CHANEL_MOTOR_5_UP       8
#define CHANEL_MOTOR_5_DOWN     9
#define CHANEL_MOTOR_6_UP       10
#define CHANEL_MOTOR_6_DOWN     11

#define EEPROOM_CYCLE_MOTOR_1_START     1
#define EEPROOM_CYCLE_MOTOR_1_END       10
#define EEPROOM_CYCLE_MOTOR_2_START     11
#define EEPROOM_CYCLE_MOTOR_2_END       20
#define EEPROOM_CYCLE_MOTOR_3_START     21
#define EEPROOM_CYCLE_MOTOR_3_END       30
#define EEPROOM_CYCLE_MOTOR_4_START     31
#define EEPROOM_CYCLE_MOTOR_4_END       40
#define EEPROOM_CYCLE_MOTOR_5_START     41
#define EEPROOM_CYCLE_MOTOR_5_END       50
#define EEPROOM_CYCLE_MOTOR_6_START     51
#define EEPROOM_CYCLE_MOTOR_6_END       60

#define EEPROOM_PERCENT_SLOW_MOTOR_1    61
#define EEPROOM_PERCENT_SLOW_MOTOR_2    62
#define EEPROOM_PERCENT_SLOW_MOTOR_3    63
#define EEPROOM_PERCENT_SLOW_MOTOR_4    64
#define EEPROOM_PERCENT_SLOW_MOTOR_5    65
#define EEPROOM_PERCENT_SLOW_MOTOR_6    66            

#define EEPROOM_SPEED_MOTOR_1           67
#define EEPROOM_SPEED_MOTOR_2           68
#define EEPROOM_SPEED_MOTOR_3           69
#define EEPROOM_SPEED_MOTOR_4           70
#define EEPROOM_SPEED_MOTOR_5           71
#define EEPROOM_SPEED_MOTOR_6           72

#define EEPROOM_TIME_RETURN_MOTOR_1     73
#define EEPROOM_TIME_RETURN_MOTOR_2     74
#define EEPROOM_TIME_RETURN_MOTOR_3     75
#define EEPROOM_TIME_RETURN_MOTOR_4     76
#define EEPROOM_TIME_RETURN_MOTOR_5     77
#define EEPROOM_TIME_RETURN_MOTOR_6     78

#define STOP_PWM_SPEED      0
#define MAX_PWM_SPEED       255


#define BAUD_RATE_SERIAL		    115200
#define MAX_SIZE_EEPROM_BUFFER	    256
#define MAX_RESPONSE_LENGTH         512
#define MAX_NUMBER_MOTOR            6
#define TIME_CHECK_MOTOR_QUA_TAI    1000

#define TIMER_FILLTER           10      //ms
enum
{
    MOTOR_1 = 0,
    MOTOR_2,
    MOTOR_3,
    MOTOR_4,
    MOTOR_5,
    MOTOR_6
};

enum
{
    MOTOR_STOP = 0,
    MOTOR_OPEN,
    MOTOR_CLOSE
};

#endif
