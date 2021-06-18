/***********************************************************
* When Start: Button switch mode setup or run must on in mode run
*
* Button switch mode Open or Close in mode run must on in Open
*
************************************************************/


#include "dc_motor_v2.h"
#include "task_motor.h"

BluetoothSerial SerialBT;

//because send data on interrupt may be error on wdt, so can send on loop()
bool change_stop_function_from_iar_to_loop[MAX_NUMBER_MOTOR] = {false, false, false, false, false, false};



void IRAM_ATTR dirhallSensor1(){
	static uint32_t timerFillterMotor1 = 0;
	if(millis() >= (timerFillterMotor1 + TIMER_FILLTER)){
		timerFillterMotor1 = millis();
		if(!mode_run_step_from_app){	//check for count -- step
			current_distant_motor.current_motor_1 ++;
		}
		else{
			if(digitalRead(L1_UP)){
				current_distant_motor.current_motor_1 ++;
			}
			else{
				current_distant_motor.current_motor_1 --;
			}
		}
		// ECHO("current_motor_1: ");
		// ECHOLN(current_distant_motor.current_motor_1);
		if(!isModeConfig){	//check normal mode run
			if(current_distant_motor.current_motor_1 == value_distant_motor.distant_motor_1){
				change_stop_function_from_iar_to_loop[MOTOR_1] = true;		//set motor 1 stop
				flag_when_run_done[MOTOR_1] = true;
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
			}
		}
		else{	//check setup mode run
			if(mode_run_step_from_app){		//when stop on mode run step then save data distaant
				if(digitalRead(L1_UP)){
					if(current_distant_motor.current_motor_1 == (distant_in_time_press_step_run + step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_1] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_1] = true;
						change_stop_function_from_iar_to_loop[MOTOR_1] = true;		//set motor 1 stop
					}
				}
				else{
					if(current_distant_motor.current_motor_1 == (distant_in_time_press_step_run - step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_1] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_1] = true;
						change_stop_function_from_iar_to_loop[MOTOR_1] = true;		//set motor 1 stop
					}
				}
			}
			else if(mode_run_test_distant){
				if(current_distant_motor.current_motor_1 == value_distant_motor.distant_motor_1){
					mode_run_test_distant = false;
					change_stop_function_from_iar_to_loop[MOTOR_1] = true;		//set motor 1 stop
				}
			}
		}
	}
	
}
void IRAM_ATTR dirhallSensor2(){
	static uint32_t timerFillterMotor2 = 0;
	if(millis() >= (timerFillterMotor2 + TIMER_FILLTER)){
		timerFillterMotor2 = millis();
		if(!mode_run_step_from_app){	//check for count -- step
			current_distant_motor.current_motor_2 ++;
		}
		else{
			if(digitalRead(L2_UP)){
				current_distant_motor.current_motor_2 ++;
			}
			else{
				current_distant_motor.current_motor_2 --;
			}
		}
		// ECHO("current_motor_2: ");
		// ECHOLN(current_distant_motor.current_motor_2);
		if(!isModeConfig){	//check normal mode run
			if(current_distant_motor.current_motor_2 == value_distant_motor.distant_motor_2){
				change_stop_function_from_iar_to_loop[MOTOR_2] = true;		//set motor 2 stop
				flag_when_run_done[MOTOR_2] = true;
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
			}
		}
		else{	//check setup mode run
			if(mode_run_step_from_app){		//when stop on mode run step then save data distaant
				if(digitalRead(L2_UP)){
					if(current_distant_motor.current_motor_2 == (distant_in_time_press_step_run + step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_2] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_2] = true;
						change_stop_function_from_iar_to_loop[MOTOR_2] = true;		//set motor 2 stop
					}
				}
				else{
					if(current_distant_motor.current_motor_2 == (distant_in_time_press_step_run - step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_2] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_2] = true;
						change_stop_function_from_iar_to_loop[MOTOR_2] = true;		//set motor 2 stop
					}
				}
			}
			else if(mode_run_test_distant){
				if(current_distant_motor.current_motor_2 == value_distant_motor.distant_motor_2){
					mode_run_test_distant = false;
					change_stop_function_from_iar_to_loop[MOTOR_2] = true;		//set motor 2 stop
				}
			}
		}
	}
}
void IRAM_ATTR dirhallSensor3(){
	static uint32_t timerFillterMotor3 = 0;
	if(millis() >= (timerFillterMotor3 + TIMER_FILLTER)){
		timerFillterMotor3 = millis();
		if(!mode_run_step_from_app){	//check for count -- step
			current_distant_motor.current_motor_3 ++;
		}
		else{
			if(digitalRead(L3_UP)){
				current_distant_motor.current_motor_3 ++;
			}
			else{
				current_distant_motor.current_motor_3 --;
			}
		}
		// ECHO("current_motor_3: ");
		// ECHOLN(current_distant_motor.current_motor_3);
		if(!isModeConfig){	//check normal mode run
			if(current_distant_motor.current_motor_3 == value_distant_motor.distant_motor_3){
				change_stop_function_from_iar_to_loop[MOTOR_3] = true;		//set motor 3 stop
				flag_when_run_done[MOTOR_3] = true;
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
			}
		}
		else{	//check setup mode run
			if(mode_run_step_from_app){		//when stop on mode run step then save data distaant
				if(digitalRead(L3_UP)){
					if(current_distant_motor.current_motor_3 == (distant_in_time_press_step_run + step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_3] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_3] = true;
						change_stop_function_from_iar_to_loop[MOTOR_3] = true;		//set motor 3 stop
					}
				}
				else{
					if(current_distant_motor.current_motor_3 == (distant_in_time_press_step_run - step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_3] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_3] = true;
						change_stop_function_from_iar_to_loop[MOTOR_3] = true;		//set motor 3 stop
					}
				}
			}
			else if(mode_run_test_distant){
				if(current_distant_motor.current_motor_3 == value_distant_motor.distant_motor_3){
					mode_run_test_distant = false;
					change_stop_function_from_iar_to_loop[MOTOR_3] = true;		//set motor 3 stop
				}
			}
		}
	}
}
void IRAM_ATTR dirhallSensor4(){
	static uint32_t timerFillterMotor4 = 0;
	if(millis() >= (timerFillterMotor4 + TIMER_FILLTER)){
		timerFillterMotor4 = millis();
		if(!mode_run_step_from_app){	//check for count -- step
			current_distant_motor.current_motor_4 ++;
		}
		else{
			if(digitalRead(L4_UP)){
				current_distant_motor.current_motor_4 ++;
			}
			else{
				current_distant_motor.current_motor_4 --;
			}
		}
		// ECHO("current_motor_4: ");
		// ECHOLN(current_distant_motor.current_motor_4);
		if(!isModeConfig){	//check normal mode run
			if(current_distant_motor.current_motor_4 == value_distant_motor.distant_motor_4){
				change_stop_function_from_iar_to_loop[MOTOR_4] = true;		//set motor 4 stop
				flag_when_run_done[MOTOR_4] = true;
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
			}
		}
		else{	//check setup mode run
			if(mode_run_step_from_app){		//when stop on mode run step then save data distaant
				if(digitalRead(L4_UP)){
					if(current_distant_motor.current_motor_4 == (distant_in_time_press_step_run + step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_4] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_4] = true;
						change_stop_function_from_iar_to_loop[MOTOR_4] = true;		//set motor 4 stop
					}
				}
				else{
					if(current_distant_motor.current_motor_4 == (distant_in_time_press_step_run - step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_4] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_4] = true;
						change_stop_function_from_iar_to_loop[MOTOR_4] = true;		//set motor 4 stop
					}
				}
			}
			else if(mode_run_test_distant){
				if(current_distant_motor.current_motor_4 == value_distant_motor.distant_motor_4){
					mode_run_test_distant = false;
					change_stop_function_from_iar_to_loop[MOTOR_4] = true;		//set motor 4 stop
				}
			}
		}
	}
}
void IRAM_ATTR dirhallSensor5(){
	static uint32_t timerFillterMotor5 = 0;
	if(millis() >= (timerFillterMotor5 + TIMER_FILLTER)){
		timerFillterMotor5 = millis();
		if(!mode_run_step_from_app){	//check for count -- step
			current_distant_motor.current_motor_5 ++;
		}
		else{
			if(digitalRead(L5_UP)){
				current_distant_motor.current_motor_5 ++;
			}
			else{
				current_distant_motor.current_motor_5 --;
			}
		}
		// ECHO("current_motor_5: ");
		// ECHOLN(current_distant_motor.current_motor_5);
		if(!isModeConfig){	//check normal mode run
			if(current_distant_motor.current_motor_5 == value_distant_motor.distant_motor_5){
				change_stop_function_from_iar_to_loop[MOTOR_5] = true;		//set motor 5 stop
				flag_when_run_done[MOTOR_5] = true;
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
			}
		}
		else{	//check setup mode run
			if(mode_run_step_from_app){		//when stop on mode run step then save data distaant
				if(digitalRead(L5_UP)){
					if(current_distant_motor.current_motor_5 == (distant_in_time_press_step_run + step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_5] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_5] = true;
						change_stop_function_from_iar_to_loop[MOTOR_5] = true;		//set motor 5 stop
					}
				}
				else{
					if(current_distant_motor.current_motor_5 == (distant_in_time_press_step_run - step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_5] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_5] = true;
						change_stop_function_from_iar_to_loop[MOTOR_5] = true;		//set motor 5 stop
					}
				}
			}
			else if(mode_run_test_distant){
				if(current_distant_motor.current_motor_5 == value_distant_motor.distant_motor_5){
					mode_run_test_distant = false;
					change_stop_function_from_iar_to_loop[MOTOR_5] = true;		//set motor 5 stop
				}
			}
		}
	}
}
void IRAM_ATTR dirhallSensor6(){
	static uint32_t timerFillterMotor6 = 0;
	if(millis() >= (timerFillterMotor6 + TIMER_FILLTER)){
		timerFillterMotor6 = millis();
		if(!mode_run_step_from_app){	//check for count -- step
			current_distant_motor.current_motor_6 ++;
		}
		else{
			if(digitalRead(L6_UP)){
				current_distant_motor.current_motor_6 ++;
			}
			else{
				current_distant_motor.current_motor_6 --;
			}
		}
		// ECHO("current_motor_6: ");
		// ECHOLN(current_distant_motor.current_motor_6);
		if(!isModeConfig){	//check normal mode run
			if(current_distant_motor.current_motor_6 == value_distant_motor.distant_motor_6){
				change_stop_function_from_iar_to_loop[MOTOR_6] = true;		//set motor 6 stop
				flag_when_run_done[MOTOR_6] = true;
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
			}
		}
		else{	//check setup mode run
			if(mode_run_step_from_app){		//when stop on mode run step then save data distaant
				if(digitalRead(L6_UP)){
					if(current_distant_motor.current_motor_6 == (distant_in_time_press_step_run + step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_6] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_6] = true;
						change_stop_function_from_iar_to_loop[MOTOR_6] = true;		//set motor 6 stop
					}
				}
				else{
					if(current_distant_motor.current_motor_6 == (distant_in_time_press_step_run - step_run_to_stop_app)){
						// send_data_to_app_iar_err[MOTOR_6] = true;
						mode_run_step_from_app = false;
						save_distant_from_setup[MOTOR_6] = true;
						change_stop_function_from_iar_to_loop[MOTOR_6] = true;		//set motor 6 stop
					}
				}
			}
			else if(mode_run_test_distant){
				if(current_distant_motor.current_motor_6 == value_distant_motor.distant_motor_6){
					mode_run_test_distant = false;
					change_stop_function_from_iar_to_loop[MOTOR_6] = true;		//set motor 6 stop
				}
			}
		}
	}
}

void setPinMode(){
	// pinMode(L1_UP, OUTPUT);
	// pinMode(L1_DOWN, OUTPUT);
	// pinMode(L2_UP, OUTPUT);
	// pinMode(L2_DOWN, OUTPUT);
	// pinMode(L3_UP, OUTPUT);
	// pinMode(L3_DOWN, OUTPUT);
	// pinMode(L4_UP, OUTPUT);
	// pinMode(L4_DOWN, OUTPUT);
	// pinMode(L5_UP, OUTPUT);
	// pinMode(L5_DOWN, OUTPUT);
	// pinMode(L6_UP, OUTPUT);
	// pinMode(L6_DOWN, OUTPUT);
	init_motor();

	pinMode(hallSensor1a, INPUT);
	pinMode(hallSensor2a, INPUT);
	pinMode(hallSensor3a, INPUT);
	pinMode(hallSensor4a, INPUT);
	pinMode(hallSensor5a, INPUT);
	pinMode(hallSensor6a, INPUT);
	pinMode(PIN_SET_UP_OPEN_CLOSE, INPUT);
	pinMode(PIN_SWITCH_MODE_SETUP, INPUT);

	delay(10);
}

void restartCurrentDistant(){
	current_distant_motor.current_motor_1 = 0;
	current_distant_motor.current_motor_2 = 0;
	current_distant_motor.current_motor_3 = 0;
	current_distant_motor.current_motor_4 = 0;
	current_distant_motor.current_motor_5 = 0;
	current_distant_motor.current_motor_6 = 0;
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
    value_distant_motor.distant_motor_4 = distantMotor4.toInt();
    ECHO("Read Distant Motor 4: ");
    ECHOLN(value_distant_motor.distant_motor_4);
    //--------------Motor 5------------------------
    String distantMotor5 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_5_START; i < EEPROOM_CYCLE_MOTOR_5_END; ++i){
        distantMotor5 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_5 = distantMotor5.toInt();
    ECHO("Read Distant Motor 5: ");
    ECHOLN(value_distant_motor.distant_motor_5);
    //--------------Motor 6------------------------
    String distantMotor6 = "";
    for (int i = EEPROOM_CYCLE_MOTOR_6_START; i < EEPROOM_CYCLE_MOTOR_6_END; ++i){
        distantMotor6 += char(EEPROM.read(i));
    }
    value_distant_motor.distant_motor_6 = distantMotor6.toInt();
    ECHO("Read Distant Motor 6: ");
    ECHOLN(value_distant_motor.distant_motor_6);

	percent_low_speed[MOTOR_1] = EEPROM.read(EEPROOM_PERCENT_SLOW_MOTOR_1);
	ECHO("percent_low_speed 1: ");
    ECHOLN(percent_low_speed[MOTOR_1]);
	percent_low_speed[MOTOR_2] = EEPROM.read(EEPROOM_PERCENT_SLOW_MOTOR_2);
	ECHO("percent_low_speed 2: ");
    ECHOLN(percent_low_speed[MOTOR_2]);
	percent_low_speed[MOTOR_3] = EEPROM.read(EEPROOM_PERCENT_SLOW_MOTOR_3);
	ECHO("percent_low_speed 3: ");
    ECHOLN(percent_low_speed[MOTOR_3]);
	percent_low_speed[MOTOR_4] = EEPROM.read(EEPROOM_PERCENT_SLOW_MOTOR_4);
	ECHO("percent_low_speed 4: ");
    ECHOLN(percent_low_speed[MOTOR_4]);
	percent_low_speed[MOTOR_5] = EEPROM.read(EEPROOM_PERCENT_SLOW_MOTOR_5);
	ECHO("percent_low_speed 5: ");
    ECHOLN(percent_low_speed[MOTOR_5]);
	percent_low_speed[MOTOR_6] = EEPROM.read(EEPROOM_PERCENT_SLOW_MOTOR_6);
	ECHO("percent_low_speed 6: ");
    ECHOLN(percent_low_speed[MOTOR_6]);

	pwm_slow_speed[MOTOR_1] = EEPROM.read(EEPROOM_SPEED_MOTOR_1);
	ECHO("pwm_slow_speed 1: ");
    ECHOLN(pwm_slow_speed[MOTOR_1]);
	pwm_slow_speed[MOTOR_2] = EEPROM.read(EEPROOM_SPEED_MOTOR_2);
	ECHO("pwm_slow_speed 2: ");
    ECHOLN(pwm_slow_speed[MOTOR_2]);
	pwm_slow_speed[MOTOR_3] = EEPROM.read(EEPROOM_SPEED_MOTOR_3);
	ECHO("pwm_slow_speed 3: ");
    ECHOLN(pwm_slow_speed[MOTOR_3]);
	pwm_slow_speed[MOTOR_4] = EEPROM.read(EEPROOM_SPEED_MOTOR_4);
	ECHO("pwm_slow_speed 4: ");
    ECHOLN(pwm_slow_speed[MOTOR_4]);
	pwm_slow_speed[MOTOR_5] = EEPROM.read(EEPROOM_SPEED_MOTOR_5);
	ECHO("pwm_slow_speed 5: ");
    ECHOLN(pwm_slow_speed[MOTOR_5]);
	pwm_slow_speed[MOTOR_6] = EEPROM.read(EEPROOM_SPEED_MOTOR_6);
	ECHO("pwm_slow_speed 6: ");
    ECHOLN(pwm_slow_speed[MOTOR_6]);

	time_return_stop[MOTOR_1] = EEPROM.read(EEPROOM_TIME_RETURN_MOTOR_1);
	ECHO("time_return_stop 1: ");
    ECHOLN(time_return_stop[MOTOR_1]);
	time_return_stop[MOTOR_2] = EEPROM.read(EEPROOM_TIME_RETURN_MOTOR_2);
	ECHO("time_return_stop 2: ");
    ECHOLN(time_return_stop[MOTOR_2]);
	time_return_stop[MOTOR_3] = EEPROM.read(EEPROOM_TIME_RETURN_MOTOR_3);
	ECHO("time_return_stop 3: ");
    ECHOLN(time_return_stop[MOTOR_3]);
	time_return_stop[MOTOR_4] = EEPROM.read(EEPROOM_TIME_RETURN_MOTOR_4);
	ECHO("time_return_stop 4: ");
    ECHOLN(time_return_stop[MOTOR_4]);
	time_return_stop[MOTOR_5] = EEPROM.read(EEPROOM_TIME_RETURN_MOTOR_5);
	ECHO("time_return_stop 5: ");
    ECHOLN(time_return_stop[MOTOR_5]);
	time_return_stop[MOTOR_6] = EEPROM.read(EEPROOM_TIME_RETURN_MOTOR_6);
	ECHO("time_return_stop 6: ");
    ECHOLN(time_return_stop[MOTOR_6]);
}


void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
    switch (event)
	{
	case ESP_SPP_SRV_OPEN_EVT:
		ECHOLN("Client Connected");
		break;
	case ESP_SPP_DATA_IND_EVT:	
		if (param->data_ind.len < MAX_RESPONSE_LENGTH) {
            String data;
            for(int i = 0; i < param->data_ind.len; i++){
                data += (char)param->data_ind.data[i];
            }
            ECHO("data bluetooth: ");
            ECHOLN(data);
            StaticJsonBuffer<MAX_RESPONSE_LENGTH> jsonBuffer;
            JsonObject& rootData = jsonBuffer.parseObject(data);
			if(isModeConfig){
				if (rootData.success()){
					String type = rootData["type"];
					String name = rootData["name"];
					if(type == "get_status"){
						sendDistanttoApp();
					}
					else if(type == "save_distant"){
						String data = rootData["data"];
						if(name == "motor1"){
							value_distant_motor.distant_motor_1 = data.toInt();
							for (int i = EEPROOM_CYCLE_MOTOR_1_START; i <= EEPROOM_CYCLE_MOTOR_1_END; i++){ 
								EEPROM.write(i, 0); 
							}
							for (int i = 0; i < data.length(); ++i){
								EEPROM.write(i+EEPROOM_CYCLE_MOTOR_1_START, data[i]);             
								// ECHO(data[i]);
							}
						}
						else if(name == "motor2"){
							value_distant_motor.distant_motor_2 = data.toInt();
							for (int i = EEPROOM_CYCLE_MOTOR_2_START; i <= EEPROOM_CYCLE_MOTOR_2_END; i++){ 
								EEPROM.write(i, 0); 
							}
							for (int i = 0; i < data.length(); ++i){
								EEPROM.write(i+EEPROOM_CYCLE_MOTOR_2_START, data[i]);             
								// ECHO(data[i]);
							}
						}
						else if(name == "motor3"){
							value_distant_motor.distant_motor_3 = data.toInt();
							for (int i = EEPROOM_CYCLE_MOTOR_3_START; i <= EEPROOM_CYCLE_MOTOR_3_END; i++){ 
								EEPROM.write(i, 0); 
							}
							for (int i = 0; i < data.length(); ++i){
								EEPROM.write(i+EEPROOM_CYCLE_MOTOR_3_START, data[i]);             
								// ECHO(data[i]);
							}
						}
						else if(name == "motor4"){
							value_distant_motor.distant_motor_4 = data.toInt();
							for (int i = EEPROOM_CYCLE_MOTOR_4_START; i <= EEPROOM_CYCLE_MOTOR_4_END; i++){ 
								EEPROM.write(i, 0); 
							}
							for (int i = 0; i < data.length(); ++i){
								EEPROM.write(i+EEPROOM_CYCLE_MOTOR_4_START, data[i]);             
								// ECHO(data[i]);
							}
						}
						else if(name == "motor5"){
							value_distant_motor.distant_motor_5 = data.toInt();
							for (int i = EEPROOM_CYCLE_MOTOR_5_START; i <= EEPROOM_CYCLE_MOTOR_5_END; i++){ 
								EEPROM.write(i, 0); 
							}
							for (int i = 0; i < data.length(); ++i){
								EEPROM.write(i+EEPROOM_CYCLE_MOTOR_5_START, data[i]);             
								// ECHO(data[i]);
							}
						}
						else if(name == "motor6"){
							value_distant_motor.distant_motor_6 = data.toInt();
							for (int i = EEPROOM_CYCLE_MOTOR_6_START; i <= EEPROOM_CYCLE_MOTOR_6_END; i++){ 
								EEPROM.write(i, 0); 
							}
							for (int i = 0; i < data.length(); ++i){
								EEPROM.write(i+EEPROOM_CYCLE_MOTOR_6_START, data[i]);             
								// ECHO(data[i]);
							}
						}
						EEPROM.commit();
						sendDistanttoApp();
					}
					else if(type == "run_no_step"){
						String command = rootData["command"];
						if(name == "motor1"){
							if(command == "open"){
								motor1_open();
							}
							else if(command == "stop"){
								motor1_stop();
							}
							else if(command == "close"){
								motor1_close();
							}
						}
						else if(name == "motor2"){
							if(command == "open"){
								motor2_open();
							}
							else if(command == "stop"){
								motor2_stop();
							}
							else if(command == "close"){
								motor2_close();
							}
						}
						else if(name == "motor3"){
							if(command == "open"){
								motor3_open();
							}
							else if(command == "stop"){
								motor3_stop();
							}
							else if(command == "close"){
								motor3_close();
							}
						}
						else if(name == "motor4"){
							if(command == "open"){
								motor4_open();
							}
							else if(command == "stop"){
								motor4_stop();
							}
							else if(command == "close"){
								motor4_close();
							}
						}
						else if(name == "motor5"){
							if(command == "open"){
								motor5_open();
							}
							else if(command == "stop"){
								motor5_stop();
							}
							else if(command == "close"){
								motor5_close();
							}
						}
						else if(name == "motor6"){
							if(command == "open"){
								motor6_open();
							}
							else if(command == "stop"){
								motor6_stop();
							}
							else if(command == "close"){
								motor6_close();
							}
						}
					}
					else if(type == "run_with_step"){
						String command = rootData["command"];
						String data = rootData["data"];
						step_run_to_stop_app = data.toInt();
						mode_run_step_from_app = true;
						if(name == "motor1"){
							distant_in_time_press_step_run = current_distant_motor.current_motor_1;
							if(command == "open"){
								motor1_open();
							}
							else if(command == "close"){
								motor1_close();
							}
						}
						else if(name == "motor2"){
							distant_in_time_press_step_run = current_distant_motor.current_motor_2;
							if(command == "open"){
								motor2_open();
							}
							else if(command == "close"){
								motor2_close();
							}
						}
						else if(name == "motor3"){
							distant_in_time_press_step_run = current_distant_motor.current_motor_3;
							if(command == "open"){
								motor3_open();
							}
							else if(command == "close"){
								motor3_close();
							}
						}
						else if(name == "motor4"){
							distant_in_time_press_step_run = current_distant_motor.current_motor_4;
							if(command == "open"){
								motor4_open();
							}
							else if(command == "close"){
								motor4_close();
							}
						}
						else if(name == "motor5"){
							distant_in_time_press_step_run = current_distant_motor.current_motor_5;
							if(command == "open"){
								motor5_open();
							}
							else if(command == "close"){
								motor5_close();
							}
						}
						else if(name == "motor6"){
							distant_in_time_press_step_run = current_distant_motor.current_motor_6;
							if(command == "open"){
								motor6_open();
							}
							else if(command == "close"){
								motor6_close();
							}
						}
					}
					else if(type == "run_save_distant"){
						String command = rootData["command"];
						if(name == "motor1"){
							if(command == "open"){
								current_distant_motor.current_motor_1 = 0;
								motor1_open();
							}
							else if(command == "stop"){
								save_distant_from_setup[MOTOR_1] = true;
								motor1_stop();
							}
						}
						else if(name == "motor2"){
							if(command == "open"){
								current_distant_motor.current_motor_2 = 0;
								motor2_open();
							}
							else if(command == "stop"){
								save_distant_from_setup[MOTOR_2] = true;
								motor2_stop();
							}
						}
						else if(name == "motor3"){
							if(command == "open"){
								current_distant_motor.current_motor_3 = 0;
								motor3_open();
							}
							else if(command == "stop"){
								save_distant_from_setup[MOTOR_3] = true;
								motor3_stop();
							}
						}
						else if(name == "motor4"){
							if(command == "open"){
								current_distant_motor.current_motor_4 = 0;
								motor4_open();
							}
							else if(command == "stop"){
								save_distant_from_setup[MOTOR_4] = true;
								motor4_stop();
							}
						}
						else if(name == "motor5"){
							if(command == "open"){
								current_distant_motor.current_motor_5 = 0;
								motor5_open();
							}
							else if(command == "stop"){
								save_distant_from_setup[MOTOR_5] = true;
								motor5_stop();
							}
						}
						else if(name == "motor6"){
							if(command == "open"){
								current_distant_motor.current_motor_6 = 0;
								motor6_open();
							}
							else if(command == "stop"){
								save_distant_from_setup[MOTOR_6] = true;
								motor6_stop();
							}
						}
					}
					else if(type == "run_test_distant"){
						String command = rootData["command"];
						if(name == "motor1"){
							mode_run_test_distant = true;
							current_distant_motor.current_motor_1 = 0;
							if(command == "open"){
								motor1_open();
							}
							else if(command == "close"){
								motor1_close();
							}
						}
						else if(name == "motor2"){
							mode_run_test_distant = true;
							current_distant_motor.current_motor_2 = 0;
							if(command == "open"){
								motor2_open();
							}
							else if(command == "close"){
								motor2_close();
							}
						}
						else if(name == "motor3"){
							mode_run_test_distant = true;
							current_distant_motor.current_motor_3 = 0;
							if(command == "open"){
								motor3_open();
							}
							else if(command == "close"){
								motor3_close();
							}
						}
						else if(name == "motor4"){
							mode_run_test_distant = true;
							current_distant_motor.current_motor_4 = 0;
							if(command == "open"){
								motor4_open();
							}
							else if(command == "close"){
								motor4_close();
							}
						}
						else if(name == "motor5"){
							mode_run_test_distant = true;
							current_distant_motor.current_motor_5 = 0;
							if(command == "open"){
								motor5_open();
							}
							else if(command == "close"){
								motor5_close();
							}
						}
						else if(name == "motor6"){
							mode_run_test_distant = true;
							current_distant_motor.current_motor_6 = 0;
							if(command == "open"){
								motor6_open();
							}
							else if(command == "close"){
								motor6_close();
							}
						}
					}
					else if(type == "config"){
						String slow = rootData["slow"];
						String speed = rootData["speed"];
						String returnn = rootData["return"];
						if(name == "0"){	//MOTOR 1
							if(slow != ""){
								percent_low_speed[MOTOR_1] = slow.toInt();
								EEPROM.write(EEPROOM_PERCENT_SLOW_MOTOR_1, percent_low_speed[MOTOR_1]);
							}
							if(speed != ""){
								pwm_slow_speed[MOTOR_1] = speed.toInt();
								EEPROM.write(EEPROOM_SPEED_MOTOR_1, pwm_slow_speed[MOTOR_1]);
							}
							if(returnn != ""){
								time_return_stop[MOTOR_1] = returnn.toInt();
								EEPROM.write(EEPROOM_TIME_RETURN_MOTOR_1, time_return_stop[MOTOR_1]);
							}
						}
						else if(name == "1"){	//MOTOR 2
							if(slow != ""){
								percent_low_speed[MOTOR_2] = slow.toInt();
								EEPROM.write(EEPROOM_PERCENT_SLOW_MOTOR_2, percent_low_speed[MOTOR_2]);
							}
							if(speed != ""){
								pwm_slow_speed[MOTOR_2] = speed.toInt();
								EEPROM.write(EEPROOM_SPEED_MOTOR_2, pwm_slow_speed[MOTOR_2]);
							}
							if(returnn != ""){
								time_return_stop[MOTOR_2] = returnn.toInt();
								EEPROM.write(EEPROOM_TIME_RETURN_MOTOR_2, time_return_stop[MOTOR_2]);
							}
						}
						else if(name == "2"){	//MOTOR 3
							if(slow != ""){
								percent_low_speed[MOTOR_3] = slow.toInt();
								EEPROM.write(EEPROOM_PERCENT_SLOW_MOTOR_3, percent_low_speed[MOTOR_3]);
							}
							if(speed != ""){
								pwm_slow_speed[MOTOR_3] = speed.toInt();
								EEPROM.write(EEPROOM_SPEED_MOTOR_3, pwm_slow_speed[MOTOR_3]);
							}
							if(returnn != ""){
								time_return_stop[MOTOR_3] = returnn.toInt();
								EEPROM.write(EEPROOM_TIME_RETURN_MOTOR_3, time_return_stop[MOTOR_3]);
							}
						}
						else if(name == "3"){	//MOTOR 4
							if(slow != ""){
								percent_low_speed[MOTOR_4] = slow.toInt();
								EEPROM.write(EEPROOM_PERCENT_SLOW_MOTOR_4, percent_low_speed[MOTOR_4]);
							}
							if(speed != ""){
								pwm_slow_speed[MOTOR_4] = speed.toInt();
								EEPROM.write(EEPROOM_SPEED_MOTOR_4, pwm_slow_speed[MOTOR_4]);
							}
							if(returnn != ""){
								time_return_stop[MOTOR_4] = returnn.toInt();
								EEPROM.write(EEPROOM_TIME_RETURN_MOTOR_4, time_return_stop[MOTOR_4]);
							}
						}
						else if(name == "4"){	//MOTOR 5
							if(slow != ""){
								percent_low_speed[MOTOR_5] = slow.toInt();
								EEPROM.write(EEPROOM_PERCENT_SLOW_MOTOR_5, percent_low_speed[MOTOR_5]);
							}
							if(speed != ""){
								pwm_slow_speed[MOTOR_5] = speed.toInt();
								EEPROM.write(EEPROOM_SPEED_MOTOR_5, pwm_slow_speed[MOTOR_5]);
							}
							if(returnn != ""){
								time_return_stop[MOTOR_5] = returnn.toInt();
								EEPROM.write(EEPROOM_TIME_RETURN_MOTOR_5, time_return_stop[MOTOR_5]);
							}
						}
						else if(name == "5"){	//MOTOR 6
							if(slow != ""){
								percent_low_speed[MOTOR_6] = slow.toInt();
								EEPROM.write(EEPROOM_PERCENT_SLOW_MOTOR_6, percent_low_speed[MOTOR_6]);
							}
							if(speed != ""){
								pwm_slow_speed[MOTOR_6] = speed.toInt();
								EEPROM.write(EEPROOM_SPEED_MOTOR_6, pwm_slow_speed[MOTOR_6]);
							}
							if(returnn != ""){
								time_return_stop[MOTOR_6] = returnn.toInt();
								EEPROM.write(EEPROOM_TIME_RETURN_MOTOR_6, time_return_stop[MOTOR_6]);
							}
						}
						EEPROM.commit();
						sendDistanttoApp();
					}
				}
			}
        }
		break;
	default:
		break;
	}
	
}
//------------------------CHECK BUTTOM SWITCH SETUP-------------------
void checkButtonSwitchSetup(){
	if(digitalRead(PIN_SWITCH_MODE_SETUP) && !fisrt_switch_mode_setup){
		delay(100);
		fisrt_switch_mode_setup = true;
		isModeConfig = false;
		restartCurrentDistant();
		if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){		//----MODE OPEN SWITCH
			mode_run_open = OPEN_STEP_1;
		}
		else{	//----MODE CLOSE SWITCH
			mode_run_close = CLOSE_STEP_1;
		}
		ECHOLN("Switch to NORMAL MODE RUN");
	}
	else if(!digitalRead(PIN_SWITCH_MODE_SETUP) && fisrt_switch_mode_setup){
		delay(100);
		fisrt_switch_mode_setup = false;
		isModeConfig = true;
		restartCurrentDistant();
		motor1_stop();
		motor2_stop();
		motor3_stop();
		motor4_stop();
		motor5_stop();
		motor6_stop();
		ECHOLN("Switch to mode SETUP");
	}
}


void check_motor_stop_qua_tai(){
	if(status_motor_is_running[MOTOR_1]){
		if(millis() >= time_check_motor_qua_tai[MOTOR_1] + TIME_CHECK_MOTOR_QUA_TAI){
			time_check_motor_qua_tai[MOTOR_1] = millis();
			if(pulse_current_check_motor_qua_tai[MOTOR_1] == current_distant_motor.current_motor_1){
				//QUA TAI
				ECHOLN("QUA TAI MOTOR 1!!!");
				if(!save_distant_from_setup[MOTOR_1]){
					current_distant_motor.current_motor_1 = 0;
					pulse_current_check_motor_qua_tai[MOTOR_1] = 1;
				}
				trang_thai_truoc_khi_dao_chieu[MOTOR_1] = status_current_motor[MOTOR_1];
				motor1_stop();
				
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
				checkReturnMotor1.start();
			}else{
				pulse_current_check_motor_qua_tai[MOTOR_1] = current_distant_motor.current_motor_1;
			}
		}
	}
	if(status_motor_is_running[MOTOR_2]){
		if(millis() >= time_check_motor_qua_tai[MOTOR_2] + TIME_CHECK_MOTOR_QUA_TAI){
			time_check_motor_qua_tai[MOTOR_2] = millis();
			if(pulse_current_check_motor_qua_tai[MOTOR_2] == current_distant_motor.current_motor_2){
				//QUA TAI
				ECHOLN("QUA TAI MOTOR 2!!!");
				if(!save_distant_from_setup[MOTOR_2]){
					current_distant_motor.current_motor_2 = 0;
					pulse_current_check_motor_qua_tai[MOTOR_2] = 1;
				}
				trang_thai_truoc_khi_dao_chieu[MOTOR_2] = status_current_motor[MOTOR_2];
				motor2_stop();
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
				checkReturnMotor2.start();
			}else{
				pulse_current_check_motor_qua_tai[MOTOR_2] = current_distant_motor.current_motor_2;
			}
		}
	}
	if(status_motor_is_running[MOTOR_3]){
		if(millis() >= time_check_motor_qua_tai[MOTOR_3] + TIME_CHECK_MOTOR_QUA_TAI){
			time_check_motor_qua_tai[MOTOR_3] = millis();
			if(pulse_current_check_motor_qua_tai[MOTOR_3] == current_distant_motor.current_motor_3){
				//QUA TAI
				ECHOLN("QUA TAI MOTOR 3!!!");
				if(!save_distant_from_setup[MOTOR_3]){
					current_distant_motor.current_motor_3 = 0;
					pulse_current_check_motor_qua_tai[MOTOR_3] = 1;
				}
				trang_thai_truoc_khi_dao_chieu[MOTOR_3] = status_current_motor[MOTOR_3];
				motor3_stop();
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
				checkReturnMotor3.start();
			}else{
				pulse_current_check_motor_qua_tai[MOTOR_3] = current_distant_motor.current_motor_3;
			}
		}
	}
	if(status_motor_is_running[MOTOR_4]){
		if(millis() >= time_check_motor_qua_tai[MOTOR_4] + TIME_CHECK_MOTOR_QUA_TAI){
			time_check_motor_qua_tai[MOTOR_4] = millis();
			if(pulse_current_check_motor_qua_tai[MOTOR_4] == current_distant_motor.current_motor_4){
				//QUA TAI
				ECHOLN("QUA TAI MOTOR 4!!!");
				if(!save_distant_from_setup[MOTOR_4]){
					current_distant_motor.current_motor_4 = 0;
					pulse_current_check_motor_qua_tai[MOTOR_4] = 1;
				}
				trang_thai_truoc_khi_dao_chieu[MOTOR_4] = status_current_motor[MOTOR_4];
				motor4_stop();
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
				checkReturnMotor4.start();
			}else{
				pulse_current_check_motor_qua_tai[MOTOR_4] = current_distant_motor.current_motor_4;
			}
		}
	}
	if(status_motor_is_running[MOTOR_5]){
		if(millis() >= time_check_motor_qua_tai[MOTOR_5] + TIME_CHECK_MOTOR_QUA_TAI){
			time_check_motor_qua_tai[MOTOR_5] = millis();
			if(pulse_current_check_motor_qua_tai[MOTOR_5] == current_distant_motor.current_motor_5){
				//QUA TAI
				ECHOLN("QUA TAI MOTOR 5!!!");
				if(!save_distant_from_setup[MOTOR_5]){
					current_distant_motor.current_motor_5 = 0;
					pulse_current_check_motor_qua_tai[MOTOR_5] = 1;
				}
				trang_thai_truoc_khi_dao_chieu[MOTOR_5] = status_current_motor[MOTOR_5];
				motor5_stop();
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
				checkReturnMotor5.start();
			}else{
				pulse_current_check_motor_qua_tai[MOTOR_5] = current_distant_motor.current_motor_5;
			}
		}
	}
	if(status_motor_is_running[MOTOR_6]){
		if(millis() >= time_check_motor_qua_tai[MOTOR_6] + TIME_CHECK_MOTOR_QUA_TAI){
			time_check_motor_qua_tai[MOTOR_6] = millis();
			if(pulse_current_check_motor_qua_tai[MOTOR_6] == current_distant_motor.current_motor_6){
				//QUA TAI
				ECHOLN("QUA TAI MOTOR 6!!!");
				if(!save_distant_from_setup[MOTOR_6]){
					current_distant_motor.current_motor_6 = 0;
					pulse_current_check_motor_qua_tai[MOTOR_6] = 1;
				}
				trang_thai_truoc_khi_dao_chieu[MOTOR_6] = status_current_motor[MOTOR_6];
				motor6_stop();
				if(check_done_step()){
					beginChangeStep = true;
					restartCurrentDistant();
					if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
						mode_run_open ++;
					}
					else{
						mode_run_close ++;
					}
				}
				checkReturnMotor6.start();
			}else{
				pulse_current_check_motor_qua_tai[MOTOR_6] = current_distant_motor.current_motor_6;
			}
		}
	}
}

void check_motor_slow_speed(){
	if(status_motor_is_running[MOTOR_1] && flag_check_slow_speed[MOTOR_1]){
		if(!isModeConfig || mode_run_test_distant){
			if(current_distant_motor.current_motor_1 >= (percent_low_speed[MOTOR_1]*value_distant_motor.distant_motor_1)/100){
				if(status_current_motor[MOTOR_1] == MOTOR_OPEN){
					motor1_open_slow();
				}else{
					motor1_close_slow();
				}
			}
		}
	}
	if(status_motor_is_running[MOTOR_2] && flag_check_slow_speed[MOTOR_2]){
		if(!isModeConfig || mode_run_test_distant){
			if(current_distant_motor.current_motor_2 >= (percent_low_speed[MOTOR_2]*value_distant_motor.distant_motor_2)/100){
				if(status_current_motor[MOTOR_2] == MOTOR_OPEN){
					motor2_open_slow();
				}else{
					motor2_close_slow();
				}
			}
		}
	}
	if(status_motor_is_running[MOTOR_3] && flag_check_slow_speed[MOTOR_3]){
		if(!isModeConfig || mode_run_test_distant){
			if(current_distant_motor.current_motor_3 >= (percent_low_speed[MOTOR_3]*value_distant_motor.distant_motor_3)/100){
				if(status_current_motor[MOTOR_3] == MOTOR_OPEN){
					motor3_open_slow();
				}else{
					motor3_close_slow();
				}
			}
		}
	}
	if(status_motor_is_running[MOTOR_4] && flag_check_slow_speed[MOTOR_4]){
		if(!isModeConfig || mode_run_test_distant){
			if(current_distant_motor.current_motor_4 >= (percent_low_speed[MOTOR_4]*value_distant_motor.distant_motor_4)/100){
				if(status_current_motor[MOTOR_4] == MOTOR_OPEN){
					motor4_open_slow();
				}else{
					motor4_close_slow();
				}
			}
		}
	}
	if(status_motor_is_running[MOTOR_5] && flag_check_slow_speed[MOTOR_5]){
		if(!isModeConfig || mode_run_test_distant){
			if(current_distant_motor.current_motor_5 >= (percent_low_speed[MOTOR_5]*value_distant_motor.distant_motor_5)/100){
				if(status_current_motor[MOTOR_5] == MOTOR_OPEN){
					motor5_open_slow();
				}else{
					motor5_close_slow();
				}
			}
		}
	}
	if(status_motor_is_running[MOTOR_6] && flag_check_slow_speed[MOTOR_6]){
		if(!isModeConfig || mode_run_test_distant){
			if(current_distant_motor.current_motor_6 >= (percent_low_speed[MOTOR_6]*value_distant_motor.distant_motor_6)/100){
				if(status_current_motor[MOTOR_6] == MOTOR_OPEN){
					motor6_open_slow();
				}else{
					motor6_close_slow();
				}
			}
		}
	}
}

void ticker_update(){
    checkReturnMotor1.update();
	checkReturnMotor2.update();
	checkReturnMotor3.update();
	checkReturnMotor4.update();
	checkReturnMotor5.update();
	checkReturnMotor6.update();
}

void check_return_motor_1(){
	count_check_return_motor[MOTOR_1]++;
	if(trang_thai_truoc_khi_dao_chieu[MOTOR_1] == MOTOR_CLOSE){
		motor1_open();
	}
	else if(trang_thai_truoc_khi_dao_chieu[MOTOR_1] == MOTOR_OPEN){
		motor1_close();
	}
	trang_thai_truoc_khi_dao_chieu[MOTOR_1] = MOTOR_STOP;
	if(count_check_return_motor[MOTOR_1] == time_return_stop[MOTOR_1]){
		count_check_return_motor[MOTOR_1] = 0;
		motor1_stop();
		checkReturnMotor1.stop();
	}
}
void check_return_motor_2(){
	count_check_return_motor[MOTOR_2]++;
	if(trang_thai_truoc_khi_dao_chieu[MOTOR_2] == MOTOR_CLOSE){
		motor2_open();
	}
	else if(trang_thai_truoc_khi_dao_chieu[MOTOR_2] == MOTOR_OPEN){
		motor2_close();
	}
	trang_thai_truoc_khi_dao_chieu[MOTOR_2] = MOTOR_STOP;
	if(count_check_return_motor[MOTOR_2] == time_return_stop[MOTOR_2]){
		count_check_return_motor[MOTOR_2] = 0;
		motor2_stop();
		checkReturnMotor2.stop();
	}
}
void check_return_motor_3(){
	count_check_return_motor[MOTOR_3]++;
	if(trang_thai_truoc_khi_dao_chieu[MOTOR_3] == MOTOR_CLOSE){
		motor3_open();
	}
	else if(trang_thai_truoc_khi_dao_chieu[MOTOR_3] == MOTOR_OPEN){
		motor3_close();
	}
	trang_thai_truoc_khi_dao_chieu[MOTOR_3] = MOTOR_STOP;
	if(count_check_return_motor[MOTOR_3] == time_return_stop[MOTOR_3]){
		count_check_return_motor[MOTOR_3] = 0;
		motor3_stop();
		checkReturnMotor3.stop();
	}
}
void check_return_motor_4(){
	count_check_return_motor[MOTOR_4]++;
	if(trang_thai_truoc_khi_dao_chieu[MOTOR_4] == MOTOR_CLOSE){
		motor4_open();
	}
	else if(trang_thai_truoc_khi_dao_chieu[MOTOR_4] == MOTOR_OPEN){
		motor4_close();
	}
	trang_thai_truoc_khi_dao_chieu[MOTOR_4] = MOTOR_STOP;
	if(count_check_return_motor[MOTOR_4] == time_return_stop[MOTOR_4]){
		count_check_return_motor[MOTOR_4] = 0;
		motor4_stop();
		checkReturnMotor4.stop();
	}
}
void check_return_motor_5(){
	count_check_return_motor[MOTOR_5]++;
	if(trang_thai_truoc_khi_dao_chieu[MOTOR_5] == MOTOR_CLOSE){
		motor5_open();
	}
	else if(trang_thai_truoc_khi_dao_chieu[MOTOR_5] == MOTOR_OPEN){
		motor5_close();
	}
	trang_thai_truoc_khi_dao_chieu[MOTOR_5] = MOTOR_STOP;
	if(count_check_return_motor[MOTOR_5] == time_return_stop[MOTOR_5]){
		count_check_return_motor[MOTOR_5] = 0;
		motor5_stop();
		checkReturnMotor5.stop();
	}
}
void check_return_motor_6(){
	count_check_return_motor[MOTOR_6]++;
	if(trang_thai_truoc_khi_dao_chieu[MOTOR_6] == MOTOR_CLOSE){
		motor6_open();
	}
	else if(trang_thai_truoc_khi_dao_chieu[MOTOR_6] == MOTOR_OPEN){
		motor6_close();
	}
	trang_thai_truoc_khi_dao_chieu[MOTOR_6] = MOTOR_STOP;
	if(count_check_return_motor[MOTOR_6] == time_return_stop[MOTOR_6]){
		count_check_return_motor[MOTOR_6] = 0;
		motor6_stop();
		checkReturnMotor6.stop();
	}
}

void setup(){
    // put your setup code here, to run once:
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
	// rtc_wdt_protect_off();			//for turn off WDT
	// rtc_wdt_disable();

	rtc_wdt_set_length_of_reset_signal(RTC_WDT_SYS_RESET_SIG, RTC_WDT_LENGTH_3_2us);
	rtc_wdt_set_stage(RTC_WDT_STAGE0, RTC_WDT_STAGE_ACTION_RESET_SYSTEM);
	rtc_wdt_set_time(RTC_WDT_STAGE0, 250);

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


	SerialBT.flush();
    SerialBT.end(); 
    if(!SerialBT.begin("Test Motor")){
        ECHOLN("An error occurred initializing Bluetooth");
    }else{
        ECHOLN("Bluetooth initialized");
    }
	SerialBT.register_callback(callbackBluetooth);
	

}

void loop(){
	//------------------------CHECK BUTTOM SWITCH SETUP-------------------
	checkButtonSwitchSetup();
	
	//----------------------MODE RUN NORMAL------------------------
	if(!isModeConfig){
		//-------------------MODE OPEN SWITCH RUN-----------------------
		if(digitalRead(PIN_SET_UP_OPEN_CLOSE)){
			mode_run_close = CLOSE_STEP_1;
			switch (mode_run_open)
			{
			case OPEN_STEP_1:
				if(beginChangeStep){
					ECHOLN("START MODE RUN OPEN STEP 1");
					beginChangeStep = false;
					restartCurrentDistant();
					switch (MODE_OPEN_STEP_1[MOTOR_1])
					{
					case RUN_OPEN:
						motor1_open();
						break;
					case RUN_STOP:
						// motor1_stop();
						break;
					case RUN_CLOSE:
						motor1_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_1[MOTOR_2])
					{
					case RUN_OPEN:
						motor2_open();
						break;
					case RUN_STOP:
						// motor2_stop();
						break;
					case RUN_CLOSE:
						motor2_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_1[MOTOR_3])
					{
					case RUN_OPEN:
						motor3_open();
						break;
					case RUN_STOP:
						// motor3_stop();
						break;
					case RUN_CLOSE:
						motor3_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_1[MOTOR_4])
					{
					case RUN_OPEN:
						motor4_open();
						break;
					case RUN_STOP:
						// motor4_stop();
						break;
					case RUN_CLOSE:
						motor4_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_1[MOTOR_5])
					{
					case RUN_OPEN:
						motor5_open();
						break;
					case RUN_STOP:
						// motor5_stop();
						break;
					case RUN_CLOSE:
						motor5_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_1[MOTOR_6])
					{
					case RUN_OPEN:
						motor6_open();
						break;
					case RUN_STOP:
						// motor6_stop();
						break;
					case RUN_CLOSE:
						motor6_close();
						break;
					default:
						break;
					}
				}
				break;
			case OPEN_STEP_2:
				if(beginChangeStep){
					ECHOLN("START MODE RUN OPEN STEP 2");
					beginChangeStep = false;
					restartCurrentDistant();
					switch (MODE_OPEN_STEP_2[MOTOR_1])
					{
					case RUN_OPEN:
						motor1_open();
						break;
					case RUN_STOP:
						// motor1_stop();
						break;
					case RUN_CLOSE:
						motor1_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_2[MOTOR_2])
					{
					case RUN_OPEN:
						motor2_open();
						break;
					case RUN_STOP:
						// motor2_stop();
						break;
					case RUN_CLOSE:
						motor2_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_2[MOTOR_3])
					{
					case RUN_OPEN:
						motor3_open();
						break;
					case RUN_STOP:
						// motor3_stop();
						break;
					case RUN_CLOSE:
						motor3_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_2[MOTOR_4])
					{
					case RUN_OPEN:
						motor4_open();
						break;
					case RUN_STOP:
						// motor4_stop();
						break;
					case RUN_CLOSE:
						motor4_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_2[MOTOR_5])
					{
					case RUN_OPEN:
						motor5_open();
						break;
					case RUN_STOP:
						// motor5_stop();
						break;
					case RUN_CLOSE:
						motor5_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_2[MOTOR_6])
					{
					case RUN_OPEN:
						motor6_open();
						break;
					case RUN_STOP:
						// motor6_stop();
						break;
					case RUN_CLOSE:
						motor6_close();
						break;
					default:
						break;
					}
				}
				break;
			case OPEN_STEP_3:
				if(beginChangeStep){
					ECHOLN("START MODE RUN OPEN STEP 3");
					beginChangeStep = false;
					restartCurrentDistant();
					switch (MODE_OPEN_STEP_3[MOTOR_1])
					{
					case RUN_OPEN:
						motor1_open();
						break;
					case RUN_STOP:
						// motor1_stop();
						break;
					case RUN_CLOSE:
						motor1_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_3[MOTOR_2])
					{
					case RUN_OPEN:
						motor2_open();
						break;
					case RUN_STOP:
						// motor2_stop();
						break;
					case RUN_CLOSE:
						motor2_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_3[MOTOR_3])
					{
					case RUN_OPEN:
						motor3_open();
						break;
					case RUN_STOP:
						// motor3_stop();
						break;
					case RUN_CLOSE:
						motor3_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_3[MOTOR_4])
					{
					case RUN_OPEN:
						motor4_open();
						break;
					case RUN_STOP:
						// motor4_stop();
						break;
					case RUN_CLOSE:
						motor4_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_3[MOTOR_5])
					{
					case RUN_OPEN:
						motor5_open();
						break;
					case RUN_STOP:
						// motor5_stop();
						break;
					case RUN_CLOSE:
						motor5_close();
						break;
					default:
						break;
					}
					switch (MODE_OPEN_STEP_3[MOTOR_6])
					{
					case RUN_OPEN:
						motor6_open();
						break;
					case RUN_STOP:
						// motor6_stop();
						break;
					case RUN_CLOSE:
						motor6_close();
						break;
					default:
						break;
					}
				}
				break;
			case DONE_MODE_OPEN:
				ECHOLN("DONE RUN OPEN MODE");
				mode_run_open++;
				break;
			default:
				break;
			}
		}
		//--------------------MODE CLOSE SWITCH RUN-----------------------
		else{
			mode_run_open = OPEN_STEP_1;
			switch (mode_run_close)
			{
			case CLOSE_STEP_1:
				if(beginChangeStep){
					ECHOLN("START MODE RUN CLOSE STEP 1");
					beginChangeStep = false;
					restartCurrentDistant();
					switch (MODE_CLOSE_STEP_1[MOTOR_1])
					{
					case RUN_OPEN:
						motor1_open();
						break;
					case RUN_STOP:
						// motor1_stop();
						break;
					case RUN_CLOSE:
						motor1_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_1[MOTOR_2])
					{
					case RUN_OPEN:
						motor2_open();
						break;
					case RUN_STOP:
						// motor2_stop();
						break;
					case RUN_CLOSE:
						motor2_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_1[MOTOR_3])
					{
					case RUN_OPEN:
						motor3_open();
						break;
					case RUN_STOP:
						// motor3_stop();
						break;
					case RUN_CLOSE:
						motor3_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_1[MOTOR_4])
					{
					case RUN_OPEN:
						motor4_open();
						break;
					case RUN_STOP:
						// motor4_stop();
						break;
					case RUN_CLOSE:
						motor4_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_1[MOTOR_5])
					{
					case RUN_OPEN:
						motor5_open();
						break;
					case RUN_STOP:
						// motor5_stop();
						break;
					case RUN_CLOSE:
						motor5_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_1[MOTOR_6])
					{
					case RUN_OPEN:
						motor6_open();
						break;
					case RUN_STOP:
						// motor6_stop();
						break;
					case RUN_CLOSE:
						motor6_close();
						break;
					default:
						break;
					}
				}
				break;
			case CLOSE_STEP_2:
				if(beginChangeStep){
					ECHOLN("START MODE RUN CLOSE STEP 2");
					beginChangeStep = false;
					restartCurrentDistant();
					switch (MODE_CLOSE_STEP_2[MOTOR_1])
					{
					case RUN_OPEN:
						motor1_open();
						break;
					case RUN_STOP:
						// motor1_stop();
						break;
					case RUN_CLOSE:
						motor1_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_2[MOTOR_2])
					{
					case RUN_OPEN:
						motor2_open();
						break;
					case RUN_STOP:
						// motor2_stop();
						break;
					case RUN_CLOSE:
						motor2_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_2[MOTOR_3])
					{
					case RUN_OPEN:
						motor3_open();
						break;
					case RUN_STOP:
						// motor3_stop();
						break;
					case RUN_CLOSE:
						motor3_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_2[MOTOR_4])
					{
					case RUN_OPEN:
						motor4_open();
						break;
					case RUN_STOP:
						// motor4_stop();
						break;
					case RUN_CLOSE:
						motor4_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_2[MOTOR_5])
					{
					case RUN_OPEN:
						motor5_open();
						break;
					case RUN_STOP:
						// motor5_stop();
						break;
					case RUN_CLOSE:
						motor5_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_2[MOTOR_6])
					{
					case RUN_OPEN:
						motor6_open();
						break;
					case RUN_STOP:
						// motor6_stop();
						break;
					case RUN_CLOSE:
						motor6_close();
						break;
					default:
						break;
					}
				}
				break;
			case CLOSE_STEP_3:
				if(beginChangeStep){
					ECHOLN("START MODE RUN CLOSE STEP 3");
					beginChangeStep = false;
					restartCurrentDistant();
					switch (MODE_CLOSE_STEP_3[MOTOR_1])
					{
					case RUN_OPEN:
						motor1_open();
						break;
					case RUN_STOP:
						// motor1_stop();
						break;
					case RUN_CLOSE:
						motor1_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_3[MOTOR_2])
					{
					case RUN_OPEN:
						motor2_open();
						break;
					case RUN_STOP:
						// motor2_stop();
						break;
					case RUN_CLOSE:
						motor2_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_3[MOTOR_3])
					{
					case RUN_OPEN:
						motor3_open();
						break;
					case RUN_STOP:
						// motor3_stop();
						break;
					case RUN_CLOSE:
						motor3_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_3[MOTOR_4])
					{
					case RUN_OPEN:
						motor4_open();
						break;
					case RUN_STOP:
						// motor4_stop();
						break;
					case RUN_CLOSE:
						motor4_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_3[MOTOR_5])
					{
					case RUN_OPEN:
						motor5_open();
						break;
					case RUN_STOP:
						// motor5_stop();
						break;
					case RUN_CLOSE:
						motor5_close();
						break;
					default:
						break;
					}
					switch (MODE_CLOSE_STEP_3[MOTOR_6])
					{
					case RUN_OPEN:
						motor6_open();
						break;
					case RUN_STOP:
						// motor6_stop();
						break;
					case RUN_CLOSE:
						motor6_close();
						break;
					default:
						break;
					}
				}
				break;
			case DONE_MODE_CLOSE:
				ECHOLN("DONE RUN CLOSE MODE");
				mode_run_close++;
				break;
			default:
				break;
			}
		}
	}
	//-------------------------MODE RUN SETUP-------------------------
	// else{

	// }

	if(flag_send_data_to_app){
		flag_send_data_to_app = false;
		String data = "{\"1-1\":\"";
		data += String(value_distant_motor.distant_motor_1);
		data += "\",\"2-1\":\"";
		data += String(value_distant_motor.distant_motor_2);
		data += "\",\"3-1\":\"";
		data += String(value_distant_motor.distant_motor_3);
		data += "\",\"4-1\":\"";
		data += String(value_distant_motor.distant_motor_4);
		data += "\",\"5-1\":\"";
		data += String(value_distant_motor.distant_motor_5);
		data += "\",\"6-1\":\"";
		data += String(value_distant_motor.distant_motor_6);
		//--------------------------
		data += "\",\"1-2\":\"";
		data += String(percent_low_speed[MOTOR_1]);
		data += "\",\"2-2\":\"";
		data += String(percent_low_speed[MOTOR_2]);
		data += "\",\"3-2\":\"";
		data += String(percent_low_speed[MOTOR_3]);
		data += "\",\"4-2\":\"";
		data += String(percent_low_speed[MOTOR_4]);
		data += "\",\"5-2\":\"";
		data += String(percent_low_speed[MOTOR_5]);
		data += "\",\"6-2\":\"";
		data += String(percent_low_speed[MOTOR_6]);
		//------------------------------
		data += "\",\"1-3\":\"";
		data += String(pwm_slow_speed[MOTOR_1]);
		data += "\",\"2-3\":\"";
		data += String(pwm_slow_speed[MOTOR_2]);
		data += "\",\"3-3\":\"";
		data += String(pwm_slow_speed[MOTOR_3]);
		data += "\",\"4-3\":\"";
		data += String(pwm_slow_speed[MOTOR_4]);
		data += "\",\"5-3\":\"";
		data += String(pwm_slow_speed[MOTOR_5]);
		data += "\",\"6-3\":\"";
		data += String(pwm_slow_speed[MOTOR_6]);
		//---------------------------
		data += "\",\"1-4\":\"";
		data += String(time_return_stop[MOTOR_1]);
		data += "\",\"2-4\":\"";
		data += String(time_return_stop[MOTOR_2]);
		data += "\",\"3-4\":\"";
		data += String(time_return_stop[MOTOR_3]);
		data += "\",\"4-4\":\"";
		data += String(time_return_stop[MOTOR_4]);
		data += "\",\"5-4\":\"";
		data += String(time_return_stop[MOTOR_5]);
		data += "\",\"6-4\":\"";
		data += String(time_return_stop[MOTOR_6]);
		data += "\"}";
		for(int i = 0; i<data.length(); i++){
			SerialBT.write(data[i]);
		}
	}


	check_motor_stop_qua_tai();
	check_motor_slow_speed();

	if(change_stop_function_from_iar_to_loop[MOTOR_1]){
		change_stop_function_from_iar_to_loop[MOTOR_1] = false;
		trang_thai_truoc_khi_dao_chieu[MOTOR_1] = status_current_motor[MOTOR_1];
		motor1_stop();
		checkReturnMotor1.start();
	}
	if(change_stop_function_from_iar_to_loop[MOTOR_2]){
		change_stop_function_from_iar_to_loop[MOTOR_2] = false;
		trang_thai_truoc_khi_dao_chieu[MOTOR_2] = status_current_motor[MOTOR_2];
		motor2_stop();
		checkReturnMotor2.start();
	}
	if(change_stop_function_from_iar_to_loop[MOTOR_3]){
		change_stop_function_from_iar_to_loop[MOTOR_3] = false;
		trang_thai_truoc_khi_dao_chieu[MOTOR_3] = status_current_motor[MOTOR_3];
		motor3_stop();
		checkReturnMotor3.start();
	}
	if(change_stop_function_from_iar_to_loop[MOTOR_4]){
		change_stop_function_from_iar_to_loop[MOTOR_4] = false;
		trang_thai_truoc_khi_dao_chieu[MOTOR_4] = status_current_motor[MOTOR_4];
		motor4_stop();
		checkReturnMotor4.start();
	}
	if(change_stop_function_from_iar_to_loop[MOTOR_5]){
		change_stop_function_from_iar_to_loop[MOTOR_5] = false;
		trang_thai_truoc_khi_dao_chieu[MOTOR_5] = status_current_motor[MOTOR_5];
		motor5_stop();
		checkReturnMotor5.start();
	}
	if(change_stop_function_from_iar_to_loop[MOTOR_6]){
		change_stop_function_from_iar_to_loop[MOTOR_6] = false;
		trang_thai_truoc_khi_dao_chieu[MOTOR_6] = status_current_motor[MOTOR_6];
		motor6_stop();
		checkReturnMotor6.start();
	}

	ticker_update();
	rtc_wdt_feed();
	// vTaskDelay(pdMS_TO_TICKS(100));
	delay(10);
	yield();

}
