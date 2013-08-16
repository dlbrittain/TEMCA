/**********************************************************************
TEMPLATE FOR STAGE CONTROL

TODO:
MANUAL POSITON [x]
GRID MOVEMENT  [ ]
HARD LIMITS    [ ]
ERROR STATE    [ ]





**********************************************************************/
#include "stdafx.h"
#include "windows.h"
#include <conio.h>
#include <ctype.h>

// ######################################################################################
#include "MCSControl.h"												// include MCS Control
#pragma comment( lib, "MCSControl.lib" )

// ######################################################################################
int _tmain(int argc, _TCHAR* argv[]) {								// main application

	int error;														// variables
	unsigned int systemIndex = 0;
	unsigned int channelIndex = 0;
	unsigned int sensorType;
	bool linearSensorPresent = false;  
	int key;
	unsigned int status;
	int position
;	// ----------------------------------------------------------------------------------
	error = SA_InitSystems(SA_SYNCHRONOUS_COMMUNICATION);			// init systems
	printf("Init systems: Error: %i\n\n", error);
	// ----------------------------------------------------------------------------------
	error = SA_GetSensorType_S(systemIndex, channelIndex,
		&sensorType);												// check linear sensor
	if (sensorType == SA_S_SENSOR_TYPE ||
		sensorType == SA_SC_SENSOR_TYPE ||
		sensorType == SA_SP_SENSOR_TYPE) {
			linearSensorPresent = true;
			printf("Linear sensor present\r\n");
		} else {
			linearSensorPresent = false;
			printf("No linear sensor present\r\n");
		}
	// ----------------------------------------------------------------------------------
	printf("Operation\n");											// display operation
	printf("---------\n");
	if (linearSensorPresent) {
		printf("Arrow up    Move positioner up by 100um\n");
		printf("Arrow down  Move positioner down by 100um\n");
		printf("Other key   Display current position\n");
	} else {
		printf("Arrow up    Move positioner up by 200 steps\n");
		printf("Arrow down  Move positioner down by 200 steps\n");
		printf("Other key   Display current position\n");
	}
	printf("Enter       Exit program\n\n");

	// ----------------------------------------------------------------------------------
	do {
		key = _getch();												// get key press
		if (key == 224) {
			key = _getch();
			if (key == 72)											// arrow up
				if (linearSensorPresent)							// -> move up
					SA_GotoPositionRelative_S(
						systemIndex, channelIndex, -100000, 1000);	// with sensor
				else
					SA_StepMove_S(systemIndex, channelIndex,
						-200, 4095, 10000);							// without sensor

			if (key == 80)											// arrow down
				if (linearSensorPresent)							// -> move down
					SA_GotoPositionRelative_S(
						systemIndex, channelIndex, 100000, 1000);	// with sensor
				else
					SA_StepMove_S(systemIndex, channelIndex,
						200, 4095, 10000);							// without sensor
		}
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		do {
			SA_GetStatus_S(systemIndex, channelIndex, &status);		// get status
			Sleep(50);
		} while (status == SA_TARGET_STATUS);						// until target reach.
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if (linearSensorPresent) {
			SA_GetPosition_S(systemIndex, channelIndex, &position);	// get position
			printf("Position: %d nm\r\n", position);
		}
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	} while (key != 13);											// until enter-press

	// ----------------------------------------------------------------------------------
	error = SA_ReleaseSystems();									// release system
	printf("Release systems: Error: %i\n", error);

	return 0;
}