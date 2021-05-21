
#include "task_motor.h"
//#include "dc_motor_v2.h"
#include "AppDebug.h"
#include "EEPROM.h"

//----when all motor run done, ---> next step to run 
bool flag_when_run_done[MAX_NUMBER_MOTOR] = {false, false, false, false, false, false};

//----save distant when motor stop, in mode get edit text on app or mode run step on app
bool save_distant_from_setup[MAX_NUMBER_MOTOR] = {false, false, false, false, false, false};

struct current_motor current_distant_motor;

struct distant_motor value_distant_motor;

bool flag_send_data_to_app = false;
void sendDistanttoApp(){
    ECHOLN("Send distant to the app!");
    flag_send_data_to_app = true;
}

bool check_done_step(){
    if(flag_when_run_done[MOTOR_1]
    && flag_when_run_done[MOTOR_2]
    && flag_when_run_done[MOTOR_3]
    && flag_when_run_done[MOTOR_4]
    && flag_when_run_done[MOTOR_5]
    && flag_when_run_done[MOTOR_6]
    ){
        return true;
    }
    else{
        return false;
    }
}

void motor1_stop(){
    ECHOLN("MORTOR 1 STOP");
    flag_when_run_done[MOTOR_1] = true;
	digitalWrite(L1_UP, LOW);
	digitalWrite(L1_DOWN, LOW);
    if(save_distant_from_setup[MOTOR_1]){
        save_distant_from_setup[MOTOR_1] = false;
        value_distant_motor.distant_motor_1 = current_distant_motor.current_motor_1;
        String data = String(value_distant_motor.distant_motor_1);
        for (int i = EEPROOM_CYCLE_MOTOR_1_START; i <= EEPROOM_CYCLE_MOTOR_1_END; i++){ 
            EEPROM.write(i, 0); 
        }
        for (int i = 0; i < data.length(); ++i){
            EEPROM.write(i+EEPROOM_CYCLE_MOTOR_1_START, data[i]);             
        }
        EEPROM.commit();
        sendDistanttoApp();
    }
}
void motor2_stop(){
    ECHOLN("MORTOR 2 STOP");
    flag_when_run_done[MOTOR_2] = true;
	digitalWrite(L2_UP, LOW);
	digitalWrite(L2_DOWN, LOW);
    if(save_distant_from_setup[MOTOR_2]){
        save_distant_from_setup[MOTOR_2] = false;
        value_distant_motor.distant_motor_2 = current_distant_motor.current_motor_2;
        String data = String(value_distant_motor.distant_motor_2);
        for (int i = EEPROOM_CYCLE_MOTOR_2_START; i <= EEPROOM_CYCLE_MOTOR_2_END; i++){ 
            EEPROM.write(i, 0); 
        }
        for (int i = 0; i < data.length(); ++i){
            EEPROM.write(i+EEPROOM_CYCLE_MOTOR_2_START, data[i]);             
        }
        EEPROM.commit();
        sendDistanttoApp();
    }
}
void motor3_stop(){
    ECHOLN("MORTOR 3 STOP");
    flag_when_run_done[MOTOR_3] = true;
	digitalWrite(L3_UP, LOW);
	digitalWrite(L3_DOWN, LOW);
    if(save_distant_from_setup[MOTOR_3]){
        save_distant_from_setup[MOTOR_3] = false;
        value_distant_motor.distant_motor_3 = current_distant_motor.current_motor_3;
        String data = String(value_distant_motor.distant_motor_3);
        for (int i = EEPROOM_CYCLE_MOTOR_3_START; i <= EEPROOM_CYCLE_MOTOR_3_END; i++){ 
            EEPROM.write(i, 0); 
        }
        for (int i = 0; i < data.length(); ++i){
            EEPROM.write(i+EEPROOM_CYCLE_MOTOR_3_START, data[i]);             
        }
        EEPROM.commit();
        sendDistanttoApp();
    }
}
void motor4_stop(){
    ECHOLN("MORTOR 4 STOP");
    flag_when_run_done[MOTOR_4] = true;
	digitalWrite(L4_UP, LOW);
	digitalWrite(L4_DOWN, LOW);
    if(save_distant_from_setup[MOTOR_4]){
        save_distant_from_setup[MOTOR_4] = false;
        value_distant_motor.distant_motor_4 = current_distant_motor.current_motor_4;
        String data = String(value_distant_motor.distant_motor_4);
        for (int i = EEPROOM_CYCLE_MOTOR_4_START; i <= EEPROOM_CYCLE_MOTOR_4_END; i++){ 
            EEPROM.write(i, 0); 
        }
        for (int i = 0; i < data.length(); ++i){
            EEPROM.write(i+EEPROOM_CYCLE_MOTOR_4_START, data[i]);             
        }
        EEPROM.commit();
        sendDistanttoApp();
    }
}
void motor5_stop(){
    ECHOLN("MORTOR 5 STOP");
    flag_when_run_done[MOTOR_5] = true;
	digitalWrite(L5_UP, LOW);
	digitalWrite(L5_DOWN, LOW);
    if(save_distant_from_setup[MOTOR_5]){
        save_distant_from_setup[MOTOR_5] = false;
        value_distant_motor.distant_motor_5 = current_distant_motor.current_motor_5;
        String data = String(value_distant_motor.distant_motor_5);
        for (int i = EEPROOM_CYCLE_MOTOR_5_START; i <= EEPROOM_CYCLE_MOTOR_5_END; i++){ 
            EEPROM.write(i, 0); 
        }
        for (int i = 0; i < data.length(); ++i){
            EEPROM.write(i+EEPROOM_CYCLE_MOTOR_5_START, data[i]);             
        }
        EEPROM.commit();
        sendDistanttoApp();
    }
}
void motor6_stop(){
    ECHOLN("MORTOR 6 STOP");
    flag_when_run_done[MOTOR_6] = true;
	digitalWrite(L6_UP, LOW);
	digitalWrite(L6_DOWN, LOW);
    if(save_distant_from_setup[MOTOR_6]){
        save_distant_from_setup[MOTOR_6] = false;
        value_distant_motor.distant_motor_6 = current_distant_motor.current_motor_6;
        String data = String(value_distant_motor.distant_motor_6);
        for (int i = EEPROOM_CYCLE_MOTOR_6_START; i <= EEPROOM_CYCLE_MOTOR_6_END; i++){ 
            EEPROM.write(i, 0); 
        }
        for (int i = 0; i < data.length(); ++i){
            EEPROM.write(i+EEPROOM_CYCLE_MOTOR_6_START, data[i]);             
        }
        EEPROM.commit();
        sendDistanttoApp();
    }
}

void motor1_open(){
    ECHOLN("MORTOR 1 OPEN");
	flag_when_run_done[MOTOR_1] = false;
    digitalWrite(L1_UP, HIGH);
	digitalWrite(L1_DOWN, LOW);
}
void motor2_open(){
    ECHOLN("MORTOR 2 OPEN");
	flag_when_run_done[MOTOR_2] = false;
    digitalWrite(L2_UP, HIGH);
	digitalWrite(L2_DOWN, LOW);
}
void motor3_open(){
    ECHOLN("MORTOR 3 OPEN");
	flag_when_run_done[MOTOR_3] = false;
    digitalWrite(L3_UP, HIGH);
	digitalWrite(L3_DOWN, LOW);
}
void motor4_open(){
    ECHOLN("MORTOR 4 OPEN");
	flag_when_run_done[MOTOR_4] = false;
    digitalWrite(L4_UP, HIGH);
	digitalWrite(L4_DOWN, LOW);
}
void motor5_open(){
    ECHOLN("MORTOR 5 OPEN");
	flag_when_run_done[MOTOR_5] = false;
    digitalWrite(L5_UP, HIGH);
	digitalWrite(L5_DOWN, LOW);
}
void motor6_open(){
    ECHOLN("MORTOR 6 OPEN");
	flag_when_run_done[MOTOR_6] = false;
    digitalWrite(L6_UP, HIGH);
	digitalWrite(L6_DOWN, LOW);
}

void motor1_close(){
    ECHOLN("MORTOR 1 CLOSE");
	flag_when_run_done[MOTOR_1] = false;
    digitalWrite(L1_UP, LOW);
	digitalWrite(L1_DOWN, HIGH);
}
void motor2_close(){
    ECHOLN("MORTOR 2 CLOSE");
	flag_when_run_done[MOTOR_2] = false;
    digitalWrite(L2_UP, LOW);
	digitalWrite(L2_DOWN, HIGH);
}
void motor3_close(){
    ECHOLN("MORTOR 3 CLOSE");
	flag_when_run_done[MOTOR_3] = false;
    digitalWrite(L3_UP, LOW);
	digitalWrite(L3_DOWN, HIGH);
}
void motor4_close(){
    ECHOLN("MORTOR 4 CLOSE");
	flag_when_run_done[MOTOR_4] = false;
    digitalWrite(L4_UP, LOW);
	digitalWrite(L4_DOWN, HIGH);
}
void motor5_close(){
    ECHOLN("MORTOR 5 CLOSE");
	flag_when_run_done[MOTOR_5] = false;
    digitalWrite(L5_UP, LOW);
	digitalWrite(L5_DOWN, HIGH);
}
void motor6_close(){
    ECHOLN("MORTOR 6 CLOSE");
	flag_when_run_done[MOTOR_6] = false;
    digitalWrite(L6_UP, LOW);
	digitalWrite(L6_DOWN, HIGH);
}

 
