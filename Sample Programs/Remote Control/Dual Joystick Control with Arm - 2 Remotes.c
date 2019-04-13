#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 2 Remotes -                           *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses the Left and the Right joysticks on Remote Control 1 to run the robot using     *|
|*  "tank control". The Group 6 buttons on the top-right of Remote Control 2 are used to raise and    *|
|*  lower the arm.                                                                                    *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
|*    Motor - Port 6          armMotor             VEX Motor           Arm motor                      *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{
  while(1 == 1)
  {
    //Driving Motor Control with Remote Control 1
    motor[leftMotor] = vexRT[Ch3] / 2;
    motor[rightMotor] = vexRT[Ch2] / 2;

    //Arm Control with Remote Control 2
    if(vexRT[Btn6UXmtr2] == 1)
    {
      motor[armMotor] = 40;
    }
    else if(vexRT[Btn6DXmtr2] == 1)
    {
      motor[armMotor] = -40;
    }
    else
    {
      motor[armMotor] = 0;
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
