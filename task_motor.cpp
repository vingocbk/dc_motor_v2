#include "task_motor.h"
#include "AppDebug.h"
#include "config.h"
#include "EEPROM.h"

QueueHandle_t motorCommandQ;
bool isModeConfig;

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
}current_distant_motor;

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
}value_distant_motor;


void motor1_stop(){
	digitalWrite(L1_UP, LOW);
	digitalWrite(L1_DOWN, LOW);
}
void motor2_stop(){
	digitalWrite(L2_UP, LOW);
	digitalWrite(L2_DOWN, LOW);
}
void motor3_stop(){
	digitalWrite(L3_UP, LOW);
	digitalWrite(L3_DOWN, LOW);
}
void motor4_stop(){
	digitalWrite(L4_UP, LOW);
	digitalWrite(L4_DOWN, LOW);
}
void motor5_stop(){
	digitalWrite(L5_UP, LOW);
	digitalWrite(L5_DOWN, LOW);
}
void motor6_stop(){
	digitalWrite(L6_UP, LOW);
	digitalWrite(L6_DOWN, LOW);
}

void motor1_open(){
	digitalWrite(L1_UP, HIGH);
	digitalWrite(L1_DOWN, LOW);
}
void motor2_open(){
	digitalWrite(L2_UP, HIGH);
	digitalWrite(L2_DOWN, LOW);
}
void motor3_open(){
	digitalWrite(L3_UP, HIGH);
	digitalWrite(L3_DOWN, LOW);
}
void motor4_open(){
	digitalWrite(L4_UP, HIGH);
	digitalWrite(L4_DOWN, LOW);
}
void motor5_open(){
	digitalWrite(L5_UP, HIGH);
	digitalWrite(L5_DOWN, LOW);
}
void motor6_open(){
	digitalWrite(L6_UP, HIGH);
	digitalWrite(L6_DOWN, LOW);
}

void motor1_close(){
	digitalWrite(L1_UP, LOW);
	digitalWrite(L1_DOWN, HIGH);
}
void motor2_close(){
	digitalWrite(L2_UP, LOW);
	digitalWrite(L2_DOWN, HIGH);
}
void motor3_close(){
	digitalWrite(L3_UP, LOW);
	digitalWrite(L3_DOWN, HIGH);
}
void motor4_close(){
	digitalWrite(L4_UP, LOW);
	digitalWrite(L4_DOWN, HIGH);
}
void motor5_close(){
	digitalWrite(L5_UP, LOW);
	digitalWrite(L5_DOWN, HIGH);
}
void motor6_close(){
	digitalWrite(L6_UP, LOW);
	digitalWrite(L6_DOWN, HIGH);
}

 



void readDataEeprom(){
    //--------------Motor 1------------------------
    String distantMotor1 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_1_START; i < EEPROOM_CYCLE_MOTOR_1_END; ++i){
        distantMotor1 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_1 = distantMotor1.toInt();
    ECHO("Read Distant Motor 1: ");
    ECHOLN(value_distant_motor.distant_motor_1);
    //--------------Motor 2------------------------
    String distantMotor2 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_2_START; i < EEPROOM_CYCLE_MOTOR_2_END; ++i){
        distantMotor2 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_2 = distantMotor2.toInt();
    ECHO("Read Distant Motor 2: ");
    ECHOLN(value_distant_motor.distant_motor_2);
    //--------------Motor 3------------------------
    String distantMotor3 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_3_START; i < EEPROOM_CYCLE_MOTOR_3_END; ++i){
        distantMotor3 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_3 = distantMotor3.toInt();
    ECHO("Read Distant Motor 3: ");
    ECHOLN(value_distant_motor.distant_motor_3);
    //--------------Motor 4------------------------
    String distantMotor4 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_4_START; i < EEPROOM_CYCLE_MOTOR_4_END; ++i){
        distantMotor4 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_4 = distantMotor1.toInt();
    ECHO("Read Distant Motor 4: ");
    ECHOLN(value_distant_motor.distant_motor_4);
    //--------------Motor 5------------------------
    String distantMotor5 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_5_START; i < EEPROOM_CYCLE_MOTOR_5_END; ++i){
        distantMotor5 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_5 = distantMotor1.toInt();
    ECHO("Read Distant Motor 5: ");
    ECHOLN(value_distant_motor.distant_motor_5);
    //--------------Motor 6------------------------
    String distantMotor6 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_6_START; i < EEPROOM_CYCLE_MOTOR_6_END; ++i){
        distantMotor6 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_6 = distantMotor1.toInt();
    ECHO("Read Distant Motor 6: ");
    ECHOLN(value_distant_motor.distant_motor_6);
}
