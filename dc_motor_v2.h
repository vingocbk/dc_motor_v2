#ifndef APP_DC_MOTOR
#define APP_DC_MOTOR

#include <Arduino.h>
#include "config.h"
#include "soc/soc.h"  //Brownout detector was triggered
#include "soc/rtc_cntl_reg.h"
//#include "task_motor.h"
#include "EEPROM.h"
#include "ArduinoJson.h"
#include "BluetoothSerial.h"
#include <Ticker.h>
#include "AppDebug.h"
#include "soc/rtc_wdt.h"        //for turn of WDT

extern BluetoothSerial SerialBT;

//--------for MODE OPEN SWITCH-----
enum
{
    OPEN_STEP_1,
    OPEN_STEP_2,
    OPEN_STEP_3,
    DONE_MODE_OPEN,
    STOP_MODE_OPEN
};
//--------for MODE CLOSE SWITCH-----
enum
{
    CLOSE_STEP_1,
    CLOSE_STEP_2,
    CLOSE_STEP_3,
    DONE_MODE_CLOSE,
    STOP_MODE_CLOSE
};
//----mode run for each motor in each step
enum
{
    RUN_OPEN,
    RUN_STOP,
    RUN_CLOSE
};


//--------mode open for each motor----------
uint8_t MODE_OPEN_STEP_1[MAX_NUMBER_MOTOR] = {RUN_OPEN, RUN_OPEN, RUN_OPEN, RUN_STOP, RUN_STOP, RUN_STOP};
uint8_t MODE_OPEN_STEP_2[MAX_NUMBER_MOTOR] = {RUN_STOP, RUN_STOP, RUN_STOP, RUN_OPEN, RUN_OPEN, RUN_OPEN};
uint8_t MODE_OPEN_STEP_3[MAX_NUMBER_MOTOR] = {RUN_CLOSE, RUN_CLOSE, RUN_STOP, RUN_STOP, RUN_STOP, RUN_STOP};
//--------mode close for each motor----------
uint8_t MODE_CLOSE_STEP_1[MAX_NUMBER_MOTOR] = {RUN_OPEN, RUN_OPEN, RUN_STOP, RUN_STOP, RUN_STOP, RUN_STOP};
uint8_t MODE_CLOSE_STEP_2[MAX_NUMBER_MOTOR] = {RUN_STOP, RUN_STOP, RUN_STOP, RUN_CLOSE, RUN_CLOSE, RUN_CLOSE};
uint8_t MODE_CLOSE_STEP_3[MAX_NUMBER_MOTOR] = {RUN_CLOSE, RUN_CLOSE, RUN_CLOSE, RUN_STOP, RUN_STOP, RUN_STOP};

uint32_t time_check_motor_qua_tai[MAX_NUMBER_MOTOR];
uint32_t pulse_current_check_motor_qua_tai[MAX_NUMBER_MOTOR] = {1,1,1,1,1,1};

bool isModeConfig = true;

//variable for begin change step.
bool beginChangeStep = true;

//variable from mode step run on app
bool mode_run_step_from_app = false;
uint8_t step_run_to_stop_app;
uint32_t distant_in_time_press_step_run;

bool mode_run_test_distant = false;

int mode_run_open;
int mode_run_close;
bool fisrt_switch_mode_setup = true;

uint8_t count_check_return_motor[MAX_NUMBER_MOTOR] = {0, 0, 0, 0, 0, 0}; 
uint8_t trang_thai_truoc_khi_dao_chieu[MAX_NUMBER_MOTOR] = {MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP};

void IRAM_ATTR dirhallSensor1();
void IRAM_ATTR dirhallSensor2();
void IRAM_ATTR dirhallSensor3();
void IRAM_ATTR dirhallSensor4();
void IRAM_ATTR dirhallSensor5();
void IRAM_ATTR dirhallSensor6();

void setPinMode();
void restartCurrentDistant();
void readDataEeprom();
void checkButtonSwitchSetup();
void check_motor_stop_qua_tai();
void check_motor_slow_speed();
void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);
void ticker_update();
void check_return_motor_1();
void check_return_motor_2();
void check_return_motor_3();
void check_return_motor_4();
void check_return_motor_5();
void check_return_motor_6();

Ticker checkReturnMotor1(check_return_motor_1, 100);   //every 100ms
Ticker checkReturnMotor2(check_return_motor_2, 100);   //every 100ms
Ticker checkReturnMotor3(check_return_motor_3, 100);   //every 100ms
Ticker checkReturnMotor4(check_return_motor_4, 100);   //every 100ms
Ticker checkReturnMotor5(check_return_motor_5, 100);   //every 100ms
Ticker checkReturnMotor6(check_return_motor_6, 100);   //every 100ms

#endif
