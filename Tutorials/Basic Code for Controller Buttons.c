#pragma config(Sensor, dgtl1,  btn1,           sensorTouch)
#pragma config(Sensor, dgtl2,  btn2,           sensorTouch)
#pragma config(Motor,  port1,           testMotor,     tmotorVex393_HBridge, openLoop)

//
//  CodeForButtons.c
//  Code for Buttons
//
//  Created by Ty Lavergne on 3/27/19.
//  Copyright © 2019 Ty Lavergne. All rights reserved.
//

void btnHit(int btnIndex) {
	if (btnIndex == 0) {
		motor[testMotor] = 0;
	}

	if (btnIndex == 1) {
		motor[testMotor] = 100;
	}

	if (btnIndex == 2) {
		motor[testMotor] = -100;
	}
}

task main() {

	while (true) {

		if (SensorValue[btn1]) {
			btnHit(1);
		}

		if (SensorValue[btn2]) {
			btnHit(2);
		}

		if (!SensorValue[btn1] && !SensorValue[btn2]) {
			btnHit(0);
		}

	}

}
