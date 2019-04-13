#pragma config(Sensor, dgtl1,  touch,          sensorTouch)
#pragma config(Motor,  port2,           vexMotor,      tmotorVex393_MC29, openLoop)

task main() {

	while (true) {
		if (SensorValue[touch]) {
			motor[vexMotor] = 20;
		} else {
			motor[vexMotor] = 0;
		}
	}

}
