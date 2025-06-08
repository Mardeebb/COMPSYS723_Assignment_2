COMPSYS 723 Assignment 2 - Cruise Control

Authors: 
Mardee Bayron, mbay613
Joel Henderson, jhen559

This is Group 19's implementation of a basic cruise control system designed in Esterel. 

The necessary files needed to run are CruiseControl.strl, CruiseControl.h, CruiseControl_data.c, and also the necessary files to compile Esterel programs (which we have put in already).

How to run:

run these commands in Ubuntu Linux 20.04 command terminal:
make CruiseControl.xes
./CruiseControl.xes

- There should be a CruiseControl.xes file inside, but if it doesn't run  when doing ./CruiseControl.xes
Delete it and follow the commands above. 

Inputs:
On(pure) 
Off(pure) 
Set(pure) 
Resume(pure) 
QuickDecel(pure) 
QuickAccel(pure) 
Accel(float)
Brake(float)

Outputs:
CruiseSpeed(float) 
ThrottleCmd(float) 
CruiseState(integer) 
