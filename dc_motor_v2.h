#ifndef APP_DC_MOTOR
#define APP_DC_MOTOR

#include <Arduino.h>
#include "config.h"
#include "soc/soc.h"  //Brownout detector was triggered
#include "soc/rtc_cntl_reg.h"
#include "task_motor.h"
#include "EEPROM.h"
#include "ArduinoJson.h"
#include "BluetoothSerial.h"
#include "AppDebug.h"





void IRAM_ATTR dirhallSensor1();
void IRAM_ATTR dirhallSensor2();
void IRAM_ATTR dirhallSensor3();
void IRAM_ATTR dirhallSensor4();
void IRAM_ATTR dirhallSensor5();
void IRAM_ATTR dirhallSensor6();

void setPinMode();
void loadDataEeprom();

void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);

#endif
