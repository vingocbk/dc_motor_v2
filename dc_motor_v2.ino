#include "dc_motor_v2.h"

int cycle_distant[6];

BluetoothSerial SerialBT;


void IRAM_ATTR dirhallSensor1(){

}
void IRAM_ATTR dirhallSensor2(){
    
}
void IRAM_ATTR dirhallSensor3(){
    
}
void IRAM_ATTR dirhallSensor4(){
    
}
void IRAM_ATTR dirhallSensor5(){
    
}
void IRAM_ATTR dirhallSensor6(){
    
}

void setPinMode(){
	pinMode(L1_UP, OUTPUT);
	pinMode(L1_DOWN, OUTPUT);
	pinMode(L2_UP, OUTPUT);
	pinMode(L2_DOWN, OUTPUT);
	pinMode(L3_UP, OUTPUT);
	pinMode(L3_DOWN, OUTPUT);
	pinMode(L4_UP, OUTPUT);
	pinMode(L4_DOWN, OUTPUT);
	pinMode(L5_UP, OUTPUT);
	pinMode(L5_DOWN, OUTPUT);
	pinMode(L6_UP, OUTPUT);
	pinMode(L6_DOWN, OUTPUT);
	

	pinMode(hallSensor1a, INPUT);
	pinMode(hallSensor2a, INPUT);
	pinMode(hallSensor3a, INPUT);
	pinMode(hallSensor4a, INPUT);
	pinMode(hallSensor5a, INPUT);
	pinMode(hallSensor6a, INPUT);
	pinMode(pinSetUp, INPUT);
	pinMode(PIN_SWITCH_MODE_SETUP, INPUT);

	delay(10);
}


void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
    if(event == ESP_SPP_SRV_OPEN_EVT){
        ECHOLN("Client Connected");
    }
    if(event == ESP_SPP_DATA_IND_EVT){
        if (param->data_ind.len < MAX_RESPONSE_LENGTH) {
            String data;
            for(int i = 0; i < param->data_ind.len; i++){
                data += (char)param->data_ind.data[i];
            }
            ECHO("data bluetooth: ");
            ECHOLN(data);
            StaticJsonBuffer<MAX_RESPONSE_LENGTH> jsonBuffer;
            JsonObject& rootData = jsonBuffer.parseObject(data);
        }
    }
}



void setup(){
    // put your setup code here, to run once:
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
	Serial.begin(BAUD_RATE_SERIAL);
    EEPROM.begin(MAX_SIZE_EEPROM_BUFFER);

	setPinMode();
	readDataEeprom();


	attachInterrupt(digitalPinToInterrupt(hallSensor1a), dirhallSensor1, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor2a), dirhallSensor2, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor3a), dirhallSensor3, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor4a), dirhallSensor4, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor5a), dirhallSensor5, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor6a), dirhallSensor6, RISING);


	SerialBT.register_callback(callbackBluetooth);
    if(!SerialBT.begin("Test Motor")){
        ECHOLN("An error occurred initializing Bluetooth");
    }else{
        ECHOLN("Bluetooth initialized");
    }

}

void loop(){
	static bool fisrt_switch_mode_setup = false;
	if(digitalRead(PIN_SWITCH_MODE_SETUP) && fisrt_switch_mode_setup){
		fisrt_switch_mode_setup = true;
		isModeConfig = true;
	}
	else if(!digitalRead(PIN_SWITCH_MODE_SETUP) && fisrt_switch_mode_setup){
		isModeConfig = false;
	}
    vTaskDelay(100 / portTICK_PERIOD_MS);
}
