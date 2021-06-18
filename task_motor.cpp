
#include "task_motor.h"
// #include "dc_motor_v2.h"
#include "AppDebug.h"
#include "EEPROM.h"
#include "soc/rtc_wdt.h"        //for turn of WDT



//----when all motor run done, ---> next step to run 
bool flag_when_run_done[MAX_NUMBER_MOTOR] = {false, false, false, false, false, false};

//----save distant when motor stop, in mode get edit text on app or mode run step on app
bool save_distant_from_setup[MAX_NUMBER_MOTOR] = {false, false, false, false, false, false};
bool status_motor_is_running[MAX_NUMBER_MOTOR] = {false, false, false, false, false, false};
bool flag_check_slow_speed[MAX_NUMBER_MOTOR] = {false, false, false, false, false, false};

uint8_t status_current_motor[MAX_NUMBER_MOTOR] = {MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP}; 
uint8_t percent_low_speed[MAX_NUMBER_MOTOR] = {10, 10, 10, 10, 10, 10};
uint8_t pwm_slow_speed[MAX_NUMBER_MOTOR] = {200, 200, 200, 200, 200, 200};
uint8_t time_return_stop[MAX_NUMBER_MOTOR] = {10, 10, 10, 10, 10, 10};

struct current_motor current_distant_motor;

struct distant_motor value_distant_motor;

bool flag_send_data_to_app = false;

const int freq = 5000;
const int resolution = 8;



void sendDistanttoApp(){
    ECHOLN("Send distant to the app!");
    flag_send_data_to_app = true;
}


void init_motor(){
    // configure LED PWM functionalitites
    ledcSetup(CHANEL_MOTOR_1_UP, freq, resolution);
    ledcSetup(CHANEL_MOTOR_1_DOWN, freq, resolution);
    ledcSetup(CHANEL_MOTOR_2_UP, freq, resolution);
    ledcSetup(CHANEL_MOTOR_2_DOWN, freq, resolution);
    ledcSetup(CHANEL_MOTOR_3_UP, freq, resolution);
    ledcSetup(CHANEL_MOTOR_3_DOWN, freq, resolution);
    ledcSetup(CHANEL_MOTOR_4_UP, freq, resolution);
    ledcSetup(CHANEL_MOTOR_4_DOWN, freq, resolution);
    ledcSetup(CHANEL_MOTOR_5_UP, freq, resolution);
    ledcSetup(CHANEL_MOTOR_5_DOWN, freq, resolution);
    ledcSetup(CHANEL_MOTOR_6_UP, freq, resolution);
    ledcSetup(CHANEL_MOTOR_6_DOWN, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(L1_UP, CHANEL_MOTOR_1_UP);
    ledcAttachPin(L1_DOWN, CHANEL_MOTOR_1_DOWN);
    ledcAttachPin(L2_UP, CHANEL_MOTOR_2_UP);
    ledcAttachPin(L2_DOWN, CHANEL_MOTOR_2_DOWN);
    ledcAttachPin(L3_UP, CHANEL_MOTOR_3_UP);
    ledcAttachPin(L3_DOWN, CHANEL_MOTOR_3_DOWN);
    ledcAttachPin(L4_UP, CHANEL_MOTOR_4_UP);
    ledcAttachPin(L4_DOWN, CHANEL_MOTOR_4_DOWN);
    ledcAttachPin(L5_UP, CHANEL_MOTOR_5_UP);
    ledcAttachPin(L5_DOWN, CHANEL_MOTOR_5_DOWN);
    ledcAttachPin(L6_UP, CHANEL_MOTOR_6_UP);
    ledcAttachPin(L6_DOWN, CHANEL_MOTOR_6_DOWN);
    delay(10);
    ledcWrite(L1_UP, STOP_PWM_SPEED); 
    ledcWrite(L1_DOWN, STOP_PWM_SPEED); 
    ledcWrite(L2_UP, STOP_PWM_SPEED); 
    ledcWrite(L2_DOWN, STOP_PWM_SPEED); 
    ledcWrite(L3_UP, STOP_PWM_SPEED); 
    ledcWrite(L3_DOWN, STOP_PWM_SPEED); 
    ledcWrite(L4_UP, STOP_PWM_SPEED); 
    ledcWrite(L4_DOWN, STOP_PWM_SPEED); 
    ledcWrite(L5_UP, STOP_PWM_SPEED); 
    ledcWrite(L5_DOWN, STOP_PWM_SPEED); 
    ledcWrite(L6_UP, STOP_PWM_SPEED); 
    ledcWrite(L6_DOWN, STOP_PWM_SPEED); 

    
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

// void motor1_stop_dao_chieu(){
//     ECHOLN("MORTOR 1 STOP DAO CHIEU");
//     ledcWrite(L1_UP, STOP_PWM_SPEED); 
//     ledcWrite(L1_DOWN, STOP_PWM_SPEED); 
// }
// void motor2_stop_dao_chieu(){
//     ECHOLN("MORTOR 2 STOP DAO CHIEU");
//     ledcWrite(L2_UP, STOP_PWM_SPEED); 
//     ledcWrite(L2_DOWN, STOP_PWM_SPEED); 
// }
// void motor3_stop_dao_chieu(){
//     ECHOLN("MORTOR 3 STOP DAO CHIEU");
//     ledcWrite(L3_UP, STOP_PWM_SPEED); 
//     ledcWrite(L3_DOWN, STOP_PWM_SPEED); 
// }
// void motor4_stop_dao_chieu(){
//     ECHOLN("MORTOR 4 STOP DAO CHIEU");
//     ledcWrite(L4_UP, STOP_PWM_SPEED); 
//     ledcWrite(L4_DOWN, STOP_PWM_SPEED); 
// }
// void motor5_stop_dao_chieu(){
//     ECHOLN("MORTOR 5 STOP DAO CHIEU");
//     ledcWrite(L5_UP, STOP_PWM_SPEED); 
//     ledcWrite(L5_DOWN, STOP_PWM_SPEED); 
// }
// void motor6_stop_dao_chieu(){
//     ECHOLN("MORTOR 6 STOP DAO CHIEU");
//     ledcWrite(L6_UP, STOP_PWM_SPEED); 
//     ledcWrite(L6_DOWN, STOP_PWM_SPEED); 
// }

void motor1_stop(){
    ECHOLN("MORTOR 1 STOP");
    status_motor_is_running[MOTOR_1] = false;
    status_current_motor[MOTOR_1] = MOTOR_STOP;
    flag_check_slow_speed[MOTOR_1] = false;
    flag_when_run_done[MOTOR_1] = true;
	ledcWrite(L1_UP, STOP_PWM_SPEED); 
    ledcWrite(L1_DOWN, STOP_PWM_SPEED); 
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
    status_motor_is_running[MOTOR_2] = false;
    status_current_motor[MOTOR_2] = MOTOR_STOP;
    flag_check_slow_speed[MOTOR_2] = false;
    flag_when_run_done[MOTOR_2] = true;
	ledcWrite(L2_UP, STOP_PWM_SPEED); 
    ledcWrite(L2_DOWN, STOP_PWM_SPEED); 
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
    status_motor_is_running[MOTOR_3] = false;
    status_current_motor[MOTOR_3] = MOTOR_STOP;
    flag_check_slow_speed[MOTOR_3] = false;
    flag_when_run_done[MOTOR_3] = true;
	ledcWrite(L3_UP, STOP_PWM_SPEED); 
    ledcWrite(L3_DOWN, STOP_PWM_SPEED); 
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
    status_motor_is_running[MOTOR_4] = false;
    status_current_motor[MOTOR_4] = MOTOR_STOP;
    flag_check_slow_speed[MOTOR_4] = false;
    flag_when_run_done[MOTOR_4] = true;
	ledcWrite(L4_UP, STOP_PWM_SPEED); 
    ledcWrite(L4_DOWN, STOP_PWM_SPEED); 
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
    // rtc_wdt_feed();
    ECHOLN("MORTOR 5 STOP");
    status_motor_is_running[MOTOR_5] = false;
    status_current_motor[MOTOR_5] = MOTOR_STOP;
    flag_check_slow_speed[MOTOR_5] = false;
    flag_when_run_done[MOTOR_5] = true;
	ledcWrite(L5_UP, STOP_PWM_SPEED); 
    ledcWrite(L5_DOWN, STOP_PWM_SPEED); 
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
        ECHOLN("MORTOR 5 STOP");
        sendDistanttoApp();
        ECHOLN("MORTOR 5 STOP");
    }
}
void motor6_stop(){
    ECHOLN("MORTOR 6 STOP");
    status_motor_is_running[MOTOR_6] = false;
    status_current_motor[MOTOR_6] = MOTOR_STOP;
    flag_check_slow_speed[MOTOR_6] = false;
    flag_when_run_done[MOTOR_6] = true;
	ledcWrite(L6_UP, STOP_PWM_SPEED); 
    ledcWrite(L6_DOWN, STOP_PWM_SPEED); 
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
    status_motor_is_running[MOTOR_1] = true;
    status_current_motor[MOTOR_1] = MOTOR_OPEN;
    flag_check_slow_speed[MOTOR_1] = true;
	flag_when_run_done[MOTOR_1] = false;
    // digitalWrite(L1_UP, HIGH);
	// digitalWrite(L1_DOWN, LOW);
    ledcWrite(L1_UP, MAX_PWM_SPEED); 
    ledcWrite(L1_DOWN, STOP_PWM_SPEED); 
}
void motor1_open_slow(){
    // ledcWrite(L1_UP, MAX_PWM_SPEED); 
    ledcWrite(L1_UP, pwm_slow_speed[MOTOR_1]); 
    ledcWrite(L1_DOWN, STOP_PWM_SPEED); 
}
void motor2_open(){
    ECHOLN("MORTOR 2 OPEN");
    status_motor_is_running[MOTOR_2] = true;
    status_current_motor[MOTOR_2] = MOTOR_OPEN;
    flag_check_slow_speed[MOTOR_2] = true;
	flag_when_run_done[MOTOR_2] = false;
    // digitalWrite(L2_UP, HIGH);
	// digitalWrite(L2_DOWN, LOW);
    ledcWrite(L2_UP, MAX_PWM_SPEED); 
    ledcWrite(L2_DOWN, STOP_PWM_SPEED); 
}
void motor2_open_slow(){
    // ledcWrite(L2_UP, MAX_PWM_SPEED); 
    ledcWrite(L2_UP, pwm_slow_speed[MOTOR_2]); 
    ledcWrite(L2_DOWN, STOP_PWM_SPEED); 
}
void motor3_open(){
    ECHOLN("MORTOR 3 OPEN");
    status_motor_is_running[MOTOR_3] = true;
    status_current_motor[MOTOR_3] = MOTOR_OPEN;
    flag_check_slow_speed[MOTOR_3] = true;
	flag_when_run_done[MOTOR_3] = false;
    // digitalWrite(L3_UP, HIGH);
	// digitalWrite(L3_DOWN, LOW);
    ledcWrite(L3_UP, MAX_PWM_SPEED); 
    ledcWrite(L3_DOWN, STOP_PWM_SPEED); 
}
void motor3_open_slow(){
    // ledcWrite(L3_UP, MAX_PWM_SPEED); 
    ledcWrite(L3_UP, pwm_slow_speed[MOTOR_3]); 
    ledcWrite(L3_DOWN, STOP_PWM_SPEED); 
}
void motor4_open(){
    ECHOLN("MORTOR 4 OPEN");
    status_motor_is_running[MOTOR_4] = true;
    status_current_motor[MOTOR_4] = MOTOR_OPEN;
    flag_check_slow_speed[MOTOR_4] = true;
	flag_when_run_done[MOTOR_4] = false;
    // digitalWrite(L4_UP, HIGH);
	// digitalWrite(L4_DOWN, LOW);
    ledcWrite(L4_UP, MAX_PWM_SPEED); 
    ledcWrite(L4_DOWN, STOP_PWM_SPEED); 
}
void motor4_open_slow(){
    // ledcWrite(L4_UP, MAX_PWM_SPEED); 
    ledcWrite(L4_UP, pwm_slow_speed[MOTOR_4]); 
    ledcWrite(L4_DOWN, STOP_PWM_SPEED); 
}
void motor5_open(){
    ECHOLN("MORTOR 5 OPEN");
    status_motor_is_running[MOTOR_5] = true;
    status_current_motor[MOTOR_5] = MOTOR_OPEN;
    flag_check_slow_speed[MOTOR_5] = true;
	flag_when_run_done[MOTOR_5] = false;
    // digitalWrite(L5_UP, HIGH);
	// digitalWrite(L5_DOWN, LOW);
    ledcWrite(L5_UP, MAX_PWM_SPEED); 
    ledcWrite(L5_DOWN, STOP_PWM_SPEED); 
}
void motor5_open_slow(){
    // ledcWrite(L5_UP, MAX_PWM_SPEED); 
    ledcWrite(L5_UP, pwm_slow_speed[MOTOR_5]); 
    ledcWrite(L5_DOWN, STOP_PWM_SPEED); 
}
void motor6_open(){
    ECHOLN("MORTOR 6 OPEN");
    status_motor_is_running[MOTOR_6] = true;
    status_current_motor[MOTOR_6] = MOTOR_OPEN;
    flag_check_slow_speed[MOTOR_6] = true;
	flag_when_run_done[MOTOR_6] = false;
    // digitalWrite(L6_UP, HIGH);
	// digitalWrite(L6_DOWN, LOW);
    ledcWrite(L6_UP, MAX_PWM_SPEED); 
    ledcWrite(L6_DOWN, STOP_PWM_SPEED); 
}
void motor6_open_slow(){
    // ledcWrite(L6_UP, MAX_PWM_SPEED); 
    ledcWrite(L6_UP, pwm_slow_speed[MOTOR_6]); 
    ledcWrite(L6_DOWN, STOP_PWM_SPEED); 
}

void motor1_close(){
    ECHOLN("MORTOR 1 CLOSE");
    status_motor_is_running[MOTOR_1] = true;
    status_current_motor[MOTOR_1] = MOTOR_CLOSE;
    flag_check_slow_speed[MOTOR_1] = true;
	flag_when_run_done[MOTOR_1] = false;
    // digitalWrite(L1_UP, LOW);
	// digitalWrite(L1_DOWN, HIGH);
    ledcWrite(L1_UP, STOP_PWM_SPEED); 
    ledcWrite(L1_DOWN, MAX_PWM_SPEED); 
}
void motor1_close_slow(){
    ledcWrite(L1_UP, STOP_PWM_SPEED); 
    ledcWrite(L1_DOWN, pwm_slow_speed[MOTOR_1]); 
    // ledcWrite(L1_DOWN, STOP_PWM_SPEED); 
}
void motor2_close(){
    ECHOLN("MORTOR 2 CLOSE");
    status_motor_is_running[MOTOR_2] = true;
    status_current_motor[MOTOR_2] = MOTOR_CLOSE;
    flag_check_slow_speed[MOTOR_2] = true;
	flag_when_run_done[MOTOR_2] = false;
    // digitalWrite(L2_UP, LOW);
	// digitalWrite(L2_DOWN, HIGH);
    ledcWrite(L2_UP, STOP_PWM_SPEED); 
    ledcWrite(L2_DOWN, MAX_PWM_SPEED); 
}
void motor2_close_slow(){
    ledcWrite(L2_UP, STOP_PWM_SPEED); 
    ledcWrite(L2_DOWN, pwm_slow_speed[MOTOR_2]); 
    // ledcWrite(L2_DOWN, STOP_PWM_SPEED); 
}
void motor3_close(){
    ECHOLN("MORTOR 3 CLOSE");
    status_motor_is_running[MOTOR_3] = true;
    status_current_motor[MOTOR_3] = MOTOR_CLOSE;
    flag_check_slow_speed[MOTOR_3] = true;
	flag_when_run_done[MOTOR_3] = false;
    // digitalWrite(L3_UP, LOW);
	// digitalWrite(L3_DOWN, HIGH);
    ledcWrite(L3_UP, STOP_PWM_SPEED); 
    ledcWrite(L3_DOWN, MAX_PWM_SPEED); 
}
void motor3_close_slow(){
    ledcWrite(L3_UP, STOP_PWM_SPEED); 
    ledcWrite(L3_DOWN, pwm_slow_speed[MOTOR_3]); 
    // ledcWrite(L3_DOWN, STOP_PWM_SPEED); 
}
void motor4_close(){
    ECHOLN("MORTOR 4 CLOSE");
    status_motor_is_running[MOTOR_4] = true;
    status_current_motor[MOTOR_4] = MOTOR_CLOSE;
    flag_check_slow_speed[MOTOR_4] = true;
	flag_when_run_done[MOTOR_4] = false;
    // digitalWrite(L4_UP, LOW);
	// digitalWrite(L4_DOWN, HIGH);
    ledcWrite(L4_UP, STOP_PWM_SPEED); 
    ledcWrite(L4_DOWN, MAX_PWM_SPEED); 
}
void motor4_close_slow(){
    ledcWrite(L4_UP, STOP_PWM_SPEED); 
    ledcWrite(L4_DOWN, pwm_slow_speed[MOTOR_4]); 
    // ledcWrite(L4_DOWN, STOP_PWM_SPEED); 
}
void motor5_close(){
    ECHOLN("MORTOR 5 CLOSE");
    status_motor_is_running[MOTOR_5] = true;
    status_current_motor[MOTOR_5] = MOTOR_CLOSE;
    flag_check_slow_speed[MOTOR_5] = true;
	flag_when_run_done[MOTOR_5] = false;
    // digitalWrite(L5_UP, LOW);
	// digitalWrite(L5_DOWN, HIGH);
    ledcWrite(L5_UP, STOP_PWM_SPEED); 
    ledcWrite(L5_DOWN, MAX_PWM_SPEED); 
}
void motor5_close_slow(){
    ledcWrite(L5_UP, STOP_PWM_SPEED); 
    ledcWrite(L5_DOWN, pwm_slow_speed[MOTOR_5]); 
    // ledcWrite(L5_DOWN, STOP_PWM_SPEED); 
}
void motor6_close(){
    ECHOLN("MORTOR 6 CLOSE");
    status_motor_is_running[MOTOR_6] = true;
    status_current_motor[MOTOR_6] = MOTOR_CLOSE;
    flag_check_slow_speed[MOTOR_6] = true;
	flag_when_run_done[MOTOR_6] = false;
    // digitalWrite(L6_UP, LOW);
	// digitalWrite(L6_DOWN, HIGH);
    ledcWrite(L6_UP, STOP_PWM_SPEED); 
    ledcWrite(L6_DOWN, MAX_PWM_SPEED); 
}
void motor6_close_slow(){
    ledcWrite(L6_UP, STOP_PWM_SPEED); 
    ledcWrite(L6_DOWN, pwm_slow_speed[MOTOR_6]); 
    // ledcWrite(L6_DOWN, STOP_PWM_SPEED); 
}

 
