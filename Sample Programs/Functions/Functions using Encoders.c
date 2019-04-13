#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This program demonstrates how to write functions that use
// encoders to control a robot moving straight and turning.

void moveUntilDistance(int distanceInDegrees)
{

  SensorValue(rightEncoder) = 0; // Reset the right motor encoder
  SensorValue(leftEncoder) = 0;  // Reset the left motor encoder
  wait1Msec(1000);

  while(SensorValue[rightEncoder] < distanceInDegrees)  // While the value of the right encoder is less than distance
  {
    motor[rightMotor] = 75; // right motor is given a power level of 75.
    motor[leftMotor] = 75;  // left motor is given a power level of 75.
  }
  motor[rightMotor] = 0;    // right motor is given a power level of 0 (stop).
  motor[leftMotor] = 0;    // left motor is given a power level of 0 (stop).
  wait1Msec(1000);   //pause one second
}

void pointTurnRight(int turnDistanceRight)
{

  SensorValue(rightEncoder) = 0; // Reset the right motor encoder
  SensorValue(leftEncoder) = 0;  // Reset the left motor encoder
  wait1Msec(1000); //wait one second

  while(SensorValue[leftEncoder] < turnDistanceRight)  // While the Motor Encoder of leftMotor has not yet reached 360 counts:
  {
    motor[rightMotor] = -75; // right motor is given a power level of -75.
    motor[leftMotor] = 75;  // left motor is given a power level of 75.
  }
  motor[rightMotor] = 0;    // right motor is given a power level of 0 (stop).
  motor[leftMotor] = 0;    // left motor is given a power level of 0 (stop).
  wait1Msec(1000);   //pause one second

}

void pointTurnLeft(int turnDistanceLeft)
{

  SensorValue(rightEncoder) = 0; // Reset the right motor encoder
  SensorValue(leftEncoder) = 0;  // Reset the left motor encoder
  wait1Msec(1000); //wait one second

  while(SensorValue[rightEncoder] < turnDistanceLeft)  // While the Motor Encoder of leftMotor has not yet reached 360 counts:
  {
    motor[rightMotor] = 75;   // right motor is given a power level of 75.
    motor[leftMotor] = -75;   // left motor is given a power level of 75.
  }
  motor[rightMotor] = 0;    // right motor is given a power level of 0 (stop).
  motor[leftMotor] = 0;    // left motor is given a power level of 0 (stop).
  wait1Msec(1000);   //pause one second

}

task main()
{
  moveUntilDistance(360); //change the value of 360 to change the distance traveled
  pointTurnLeft(360);
  pointTurnRight(360);
}
