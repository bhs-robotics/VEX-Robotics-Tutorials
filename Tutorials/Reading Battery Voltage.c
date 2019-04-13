#pragma config(Sensor, dgtl1,  touch,          sensorTouch)
#pragma config(Sensor, dgtl2,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           spinMotor,     tmotorVex393_MC29, openLoop)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)

task main() {
	bLCDBacklight = true;

	while (true) {

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		string mainBattery, backupBattery;
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
		displayNextLCDString(mainBattery);
	}

	while (SensorValue[leftEncoder] > 500) {
		motor[spinMotor] = 10;
	}
}
