#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

  motor[leftMotor] = 63;
  motor[rightMotor] = 63;
  wait1Msec(2000);

  motor[leftMotor] = -63;
  motor[rightMotor] = 63;
  wait1Msec(700);

}
