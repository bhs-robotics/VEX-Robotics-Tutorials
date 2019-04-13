#pragma config(Sensor, dgtl9,  potent1,        sensorQuadEncoder)
#pragma config(Sensor, dgtl11, potent2,        sensorQuadEncoder)
#pragma config(Motor,  port2,           spinMotor,     tmotorVex393_MC29, openLoop)

//: TOP PINs on Encoder - Digital Port 9
//: BOTTOM PINs on Encoder - Digital Port 10

const float _rotations = 360.0;

void Forward(float r) {
  SensorValue[potent1] = 0;
  SensorValue[potent2]  = 0;

  while(SensorValue[potent2] < (r * _rotations) && SensorValue[potent1] < (r * _rotations)) {
    motor[spinMotor] = 20;
  }

  motor[spinMotor] = 0;
}

task main() {
	while (true) {
		if (vexRT[Btn7U]) {
			Forward(2);
		}
	}
}
