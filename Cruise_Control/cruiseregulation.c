#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "Cruise_Control.h"

/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: throttleIn - throttle input
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float saturateThrottle(float throttleIn, bool* saturate)
{
	static const float THROTTLESATMAX = 45.0;
	if (throttleIn > THROTTLESATMAX) {
		*saturate = true;
		return THROTTLESATMAX;
	}
	else if (throttleIn < 0) {
		*saturate = true;
		return 0;
	}
	else {
		*saturate = false;
		return throttleIn;
	}
}

int saturateThrottleInt(int throttleIn, int saturate)
{
	float throttleInFloat = throttleIn/100;
	bool saturatebool = saturate;
	if (saturate == 0) {
		saturatebool = 0;
	} else {
		saturatebool = 1;
	}
	
	float output = saturateThrottle(throttleInFloat, *saturatebool)
	output = output * 100;
	return output;
}


/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: isGoingOn - true if the cruise control has just gone into the ON state 
                        from another state; false otherwise
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float regulateThrottle(bool isGoingOn, float cruiseSpeed, float vehicleSpeed)
{
	static const float KP = 8.113;
	static const float KI = 0.5;
	static bool saturate = true;
	static float iterm = 0;
	
	if (isGoingOn) {
		iterm = 0;	// reset the integral action
		saturate = true;	
	}
	float error = cruiseSpeed - vehicleSpeed;
	float proportionalAction = error * KP;
	if (saturate)
		error = 0;	// integral action is hold when command is saturated
	iterm = iterm + error;
	float integralAction = KI * iterm;
	return saturateThrottle(proportionalAction + integralAction, &saturate);
}

int regulateThrottleInt(int isGoingOn, int cruiseSpeed, int vehicleSpeed)
{
	float cruiseSpeedFloat = cruiseSpeed / 100;
	float vehicleSpeedFloat = vehicleSpeed / 100;
	bool isGoingOnBool;
	if (isGoingOn == 0) {
		isGoingBool = 0;
	} else {
		isGoingBool = 1;
	}
	float output = regulateThrottle(isGoingOnBool, cruiseSpeedFloat, vehicleSpeedFloat);
	output = output * 100;
	return output;
}
