#pragma config(Motor,  port3,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightLift,     tmotorVex393_MC29, openLoop)

void liftLeft(int speed) {
	motor[leftLift] = speed;
}

void liftRight(int speed) {
	motor[rightLift] = speed;
}

void moveLeft(int speed) {
	motor[leftFront] = speed;
	motor[leftBack] = speed;
}

void moveRight(int speed) {
	motor[rightFront] = speed;
	motor[rightBack] = speed;
}

void turnClaw(int speed) {
	motor[claw] = speed;
}

void Setup() {
	bLCDBacklight = true;
	displayFileName(0, 0);
}

bool standByClawPower = false;

void Loop() {

	while (true) {

		//: High Speed Lifts
		if (vexRT[Btn5U]) {
			liftLeft(-80);
			liftRight(80);
		}

		if (vexRT[Btn5D]) {
			liftLeft(60);
			liftRight(-60);
		}

		//: Low Speed Lifts
		if (vexRT[Btn6U]) {
			liftLeft(-40);
			liftRight(40);
		}

		if (vexRT[Btn6D]) {
			liftLeft(40);
			liftRight(-40);
		}

		if (!vexRT[Btn5U] && !vexRT[Btn5D] && !vexRT[Btn6U] && !vexRT[Btn6D]) {
			liftLeft(-2);
			liftRight(2);
		}

		//: Drive
		int leftPower = vexRT[Ch3];
		int rightPower = vexRT[Ch2];

		moveLeft(leftPower);
		moveRight(rightPower);

		//: Claw Turn HIGH
		if (vexRT[Btn8L]) {
			turnClaw(-30);
			} else {
			if (vexRT[Btn8R]) {
				standByClawPower = false;
				} else {
				turnClaw(0);
				standByClawPower = true;
			}
		}

		if (vexRT[Btn8R]) {
			turnClaw(30);
			} else {
			if (vexRT[Btn8L]) {
				standByClawPower = false;
				} else {
				turnClaw(0);
				standByClawPower = true;
			}
		}
	}

	//: Claw Turn LOW
	if (vexRT[Btn8U]) {
		turnClaw(-15);
		} else {
		if (vexRT[Btn8D]) {
			standByClawPower = false;
			} else {
			turnClaw(0);
			standByClawPower = true;
		}
	}

	if (vexRT[Btn8D]) {
		turnClaw(15);
		} else {
		if (vexRT[Btn8U]) {
			standByClawPower = false;
			} else {
			turnClaw(0);
			standByClawPower = true;
		}
	}

	if (standByClawPower) {
		turnClaw(0);
	}
}

task main() {
	Setup();
	Loop();
}
