//
//  Syntax.c
//  A Syntax File for RobotC
//
//  Created by Ty Lavergne on 3/28/19.
//




//: HEAD: Motors

// Pragma Configuration for VEX Motors
#pragma config(Motor, /*Motor Port Index*/, /*Motor Name*/, tmotorVex393_HBridge, openLoop)




//: HEAD: Foundation

// String - A TEXT value
string stringVar = "Text";

// Bool - A TRUE or FALSE value
bool trueBoolVar = true;
bool falseBoolVar = false;

// Int - A non-decimal numerical value; (Negative Infinity to Positive Infinity)
int intVar = 10;

// Float - A decimal numerical value; (Negative Infinity to Positive Infinity)
float floatVar = 10.1;




//: HEAD: Voids

// Void - A FUNCTION in RobotC
void name(/*parameters*/) {
	// Code
}

void moveForward(int speed) {
	// Code
	motor[/*Motor Name*/] = speed;
}




task main() {
	// Code
}
