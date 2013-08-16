/**********************************************************************
* Copyright (c) 2006-2009 SmarAct GmbH
*
* File name: MCSControl.h
* Author   : Marc Schiffner
* Version  : 1.6
*
* This is the software interface to the Modular Control System.
* Please refer to the Programmer's Guide for a detailed documentation.
*
* THIS  SOFTWARE, DOCUMENTS, FILES AND INFORMATION ARE PROVIDED 'AS IS'
* WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
* BUT  NOT  LIMITED  TO,  THE  IMPLIED  WARRANTIES  OF MERCHANTABILITY,
* FITNESS FOR A PURPOSE, OR THE WARRANTY OF NON-INFRINGEMENT.
* THE  ENTIRE  RISK  ARISING OUT OF USE OR PERFORMANCE OF THIS SOFTWARE
* REMAINS WITH YOU.
* IN  NO  EVENT  SHALL  THE  SMARACT  GMBH  BE  LIABLE  FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL, CONSEQUENTIAL OR OTHER DAMAGES ARISING
* OUT OF THE USE OR INABILITY TO USE THIS SOFTWARE.
**********************************************************************/

#ifndef MCSCONTROL_H
#define MCSCONTROL_H

#ifdef MCSCONTROL_EXPORTS
#define MCSCONTROL_API __declspec(dllexport)
#else
#define MCSCONTROL_API __declspec(dllimport)
#endif

typedef unsigned int SA_STATUS;
typedef unsigned int SA_INDEX;
typedef unsigned int SA_PACKET_TYPE;

// defines a data packet for the asynchronous mode
typedef struct SA_packet {
	SA_PACKET_TYPE packetType;					// type of packet (see below)
	SA_INDEX channelIndex;						// source channel
	unsigned int data1;							// data field
	signed int data2;							// data field
	signed int data3;							// data field
	unsigned int data4;							// data field
} SA_PACKET;

// function status return values
#define	SA_OK									0
#define	SA_INITIALIZATION_ERROR					1
#define	SA_NOT_INITIALIZED_ERROR				2
#define	SA_NO_SYSTEMS_FOUND_ERROR				3
#define	SA_TOO_MANY_SYSTEMS_ERROR				4
#define	SA_INVALID_SYSTEM_INDEX_ERROR			5
#define	SA_INVALID_CHANNEL_INDEX_ERROR			6
#define	SA_TRANSMIT_ERROR						7
#define	SA_WRITE_ERROR							8
#define	SA_INVALID_PARAMETER_ERROR				9
#define	SA_READ_ERROR							10
#define	SA_INTERNAL_ERROR						12
#define SA_WRONG_MODE_ERROR						13
#define SA_PROTOCOL_ERROR						14
#define SA_TIMEOUT_ERROR						15
#define SA_NOTIFICATION_ALREADY_SET_ERROR		16
#define SA_ID_LIST_TOO_SMALL_ERROR				17
#define SA_SYSTEM_ALREADY_ADDED_ERROR			18
#define SA_WRONG_CHANNEL_TYPE_ERROR				19
#define SA_NO_SENSOR_PRESENT_ERROR				129
#define SA_AMPLITUDE_TOO_LOW_ERROR				130
#define SA_AMPLITUDE_TOO_HIGH_ERROR				131
#define SA_FREQUENCY_TOO_LOW_ERROR				132
#define SA_FREQUENCY_TOO_HIGH_ERROR				133
#define SA_SCAN_TARGET_TOO_HIGH_ERROR			135
#define SA_SCAN_SPEED_TOO_LOW_ERROR				136
#define SA_SCAN_SPEED_TOO_HIGH_ERROR			137
#define SA_SENSOR_DISABLED_ERROR				140
#define SA_COMMAND_OVERRIDDEN_ERROR				141
#define SA_END_STOP_REACHED_ERROR				142
#define SA_WRONG_SENSOR_TYPE_ERROR				143
#define SA_COULD_NOT_FIND_REF_ERROR				144
#define SA_WRONG_END_EFFECTOR_TYPE_ERROR		145
#define SA_RANGE_LIMIT_REACHED_ERROR			147
#define SA_PHYSICAL_POSITION_UNKNOWN_ERROR		148
#define SA_UNKNOWN_COMMAND_ERROR				240
#define	SA_OTHER_ERROR							255

// configuration flags for SA_InitDevices
#define SA_SYNCHRONOUS_COMMUNICATION			0
#define SA_ASYNCHRONOUS_COMMUNICATION			1
#define SA_HARDWARE_RESET						2

// configuration flags for SA_SetStepWhileScan_X
#define SA_NO_STEP_WHILE_SCAN					0
#define SA_STEP_WHILE_SCAN						1

// configuration flags for SA_SetSensorEnabled_X
#define SA_SENSOR_DISABLED						0
#define SA_SENSOR_ENABLED						1
#define SA_SENSOR_POWERSAVE						2

// configuration flags for SA_SetReportOnComplete_A
#define SA_NO_REPORT_ON_COMPLETE				0
#define SA_REPORT_ON_COMPLETE					1

// configuration flags for SA_SetAccumulateRelativePositions_X
#define SA_NO_ACCUMULATE_RELATIVE_POSITIONS		0
#define SA_ACCUMULATE_RELATIVE_POSITIONS		1

// packet types (for asynchronous mode)
#define SA_NO_PACKET_TYPE						0
#define SA_ERROR_PACKET_TYPE					1
#define SA_POSITION_PACKET_TYPE					2
#define SA_COMPLETED_PACKET_TYPE				3
#define SA_STATUS_PACKET_TYPE					4
#define SA_ANGLE_PACKET_TYPE					5
#define SA_VOLTAGE_LEVEL_PACKET_TYPE			6
#define SA_SENSOR_TYPE_PACKET_TYPE				7
#define SA_SENSOR_ENABLED_PACKET_TYPE			8
#define SA_END_EFFECTOR_TYPE_PACKET_TYPE		9
#define SA_GRIPPER_OPENING_PACKET_TYPE			10
#define SA_FORCE_PACKET_TYPE					11
#define SA_MOVE_SPEED_PACKET_TYPE				12
#define SA_PHYSICAL_POSITION_KNOWN_PACKET_TYPE	13
#define SA_POSITION_LIMIT_PACKET_TYPE			14
#define SA_ANGLE_LIMIT_PACKET_TYPE				15
#define SA_INVALID_PACKET_TYPE					255

// channel status codes
#define SA_STOPPED_STATUS						0
#define SA_STEPPING_STATUS						1
#define SA_SCANNING_STATUS						2
#define SA_HOLDING_STATUS						3
#define SA_TARGET_STATUS						4
#define SA_MOVE_DELAY_STATUS					5
#define SA_CALIBRATING_STATUS					6
#define SA_FINDING_REF_STATUS					7
#define SA_OPENING_STATUS						8

// HCM enabled levels (for SA_SetHCMEnabled)
#define SA_HCM_DISABLED							0
#define SA_HCM_ENABLED							1
#define SA_HCM_CONTROLS_DISABLED				2

// sensor types (for SA_SetSensorType_X and SA_GetSensorType_X)
#define SA_NO_SENSOR_TYPE						0
#define SA_S_SENSOR_TYPE						1
#define SA_SR_SENSOR_TYPE						2
#define SA_ML_SENSOR_TYPE						3
#define SA_MR_SENSOR_TYPE						4
#define SA_SP_SENSOR_TYPE						5
#define SA_SC_SENSOR_TYPE						6

// compatibility definitions
#define SA_LIN20UMS_SENSOR_TYPE					SA_S_SENSOR_TYPE
#define SA_ROT3600S_SENSOR_TYPE					SA_SR_SENSOR_TYPE
#define SA_ROT50LS_SENSOR_TYPE					SA_ML_SENSOR_TYPE
#define SA_ROT50RS_SENSOR_TYPE					SA_MR_SENSOR_TYPE
#define SA_LINEAR_SENSOR_TYPE					SA_S_SENSOR_TYPE
#define SA_ROTARY_SENSOR_TYPE					SA_SR_SENSOR_TYPE

// movement directions (for SA_FindReferenceMark_X)
#define SA_FORWARD_DIRECTION					0
#define SA_BACKWARD_DIRECTION					1

// auto zero (for SA_FindReferenceMark_X)
#define SA_NO_AUTO_ZERO							0
#define SA_AUTO_ZERO							1

// physical position (for SA_GetPhyscialPositionKnown_X)
#define SA_PHYSICAL_POSITION_UNKNOWN			0
#define SA_PHYSICAL_POSITION_KNOWN				1

// channel types (for SA_GetChannelType)
#define SA_POSITIONER_CHANNEL_TYPE				0
#define SA_END_EFFECTOR_CHANNEL_TYPE			1

// end effector types
#define SA_ANALOG_SENSOR_END_EFFECTOR_TYPE		0
#define SA_GRIPPER_END_EFFECTOR_TYPE			1
#define SA_FORCE_SENSOR_END_EFFECTOR_TYPE		2
#define SA_FORCE_GRIPPER_END_EFFECTOR_TYPE		3

#ifdef __cplusplus
extern "C" {
#endif

/**********************
General note:
All functions have a return value of SA_STATUS
indicating success (SA_OK) or failure of execution. See the above
definitions for a list of error codes.
***********************/


/************************************************************************
*************************************************************************
**                 Section I: Initialization Functions                 **
*************************************************************************
************************************************************************/
MCSCONTROL_API
SA_STATUS SA_GetDLLVersion(unsigned int *version);

MCSCONTROL_API
SA_STATUS SA_GetAvailableSystems(unsigned int *idList, unsigned int *idListSize);

MCSCONTROL_API
SA_STATUS SA_AddSystemToInitSystemsList(unsigned int systemId);

MCSCONTROL_API
SA_STATUS SA_ClearInitSystemsList();

MCSCONTROL_API
SA_STATUS SA_InitSystems(unsigned int configuration);

MCSCONTROL_API
SA_STATUS SA_ReleaseSystems();

MCSCONTROL_API
SA_STATUS SA_GetNumberOfSystems(unsigned int *number);

MCSCONTROL_API
SA_STATUS SA_GetSystemID(SA_INDEX systemIndex, unsigned int *systemId);

MCSCONTROL_API
SA_STATUS SA_GetNumberOfChannels(SA_INDEX systemIndex, unsigned int *channels);

MCSCONTROL_API
SA_STATUS SA_GetChannelType(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *type);

MCSCONTROL_API
SA_STATUS SA_SetHCMEnabled(SA_INDEX systemIndex, unsigned int enabled);



/************************************************************************
*************************************************************************
**        Section IIa:  Functions for SYNCHRONOUS communication        **
*************************************************************************
************************************************************************/

/*************************************************
**************************************************
**    Section IIa.1: Configuration Functions    **
**************************************************
*************************************************/
MCSCONTROL_API // Positioner
SA_STATUS SA_SetClosedLoopMaxFrequency_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int frequency);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetClosedLoopMoveSpeed_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int speed);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetClosedLoopMoveSpeed_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *speed);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetPosition_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int position);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetZeroPosition_S(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetPhysicalPositionKnown_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *known);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetPositionLimit_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int minPosition, signed int maxPosition);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetPositionLimit_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int *minPosition, signed int *maxPosition);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetAngleLimit_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int minAngle, signed int minRevolution, unsigned int maxAngle, signed int maxRevolution);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetAngleLimit_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *minAngle, signed int *minRevolution, unsigned int *maxAngle, signed int *maxRevolution);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetStepWhileScan_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int step);

MCSCONTROL_API
SA_STATUS SA_SetSensorEnabled_S(SA_INDEX systemIndex, unsigned int enabled);

MCSCONTROL_API
SA_STATUS SA_GetSensorEnabled_S(SA_INDEX systemIndex, unsigned int *enabled);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetSensorType_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int type);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetSensorType_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *type);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetAccumulateRelativePositions_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int accumulate);

MCSCONTROL_API // End effector
SA_STATUS SA_SetEndEffectorType_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int type, signed int param1, signed int param2);

MCSCONTROL_API // End effector
SA_STATUS SA_GetEndEffectorType_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *type, signed int *param1, signed int *param2);

MCSCONTROL_API // End effector
SA_STATUS SA_SetZeroForce_S(SA_INDEX systemIndex, SA_INDEX channelIndex);

/*************************************************
**************************************************
**  Section IIa.2: Movement Control Functions   **
**************************************************
*************************************************/
MCSCONTROL_API // Positioner
SA_STATUS SA_StepMove_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int steps, unsigned int amplitude, unsigned int frequency);

MCSCONTROL_API // Positioner
SA_STATUS SA_ScanMoveAbsolute_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int target, unsigned int scanSpeed);

MCSCONTROL_API // Positioner
SA_STATUS SA_ScanMoveRelative_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int diff, unsigned int scanSpeed);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoPositionAbsolute_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int position, unsigned int holdTime);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoPositionRelative_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int diff, unsigned int holdTime);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoAngleAbsolute_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int angle, signed int revolution, unsigned int holdTime);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoAngleRelative_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int angleDiff, signed int revolutionDiff, unsigned int holdTime);

MCSCONTROL_API // Positioner, End effector
SA_STATUS SA_Stop_S(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_CalibrateSensor_S(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_FindReferenceMark_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int direction, unsigned int holdTime, unsigned int autoZero);

MCSCONTROL_API // End effector
SA_STATUS SA_GotoGripperOpeningAbsolute_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int opening, unsigned int speed);

MCSCONTROL_API // End effector
SA_STATUS SA_GotoGripperOpeningRelative_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int diff, unsigned int speed);

MCSCONTROL_API // End effector
SA_STATUS SA_GotoGripperForceAbsolute_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int force, unsigned int speed, unsigned int holdTime);

/************************************************
*************************************************
**  Section IIa.3: Channel Feedback Functions  **
*************************************************
*************************************************/
MCSCONTROL_API // Positioner
SA_STATUS SA_GetVoltageLevel_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *level);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetPosition_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int *position);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetAngle_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *angle, signed int *revolution);

MCSCONTROL_API // Positioner, End effector
SA_STATUS SA_GetStatus_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *status);

MCSCONTROL_API // End effector
SA_STATUS SA_GetGripperOpening_S(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int *opening);

MCSCONTROL_API // End effector
SA_STATUS SA_GetForce_S(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int *force);

/************************************************************************
*************************************************************************
**       Section IIb:  Functions for ASYNCHRONOUS communication        **
*************************************************************************
************************************************************************/

/*************************************************
**************************************************
**    Section IIb.1: Configuration Functions    **
**************************************************
*************************************************/
MCSCONTROL_API // Positioner
SA_STATUS SA_SetClosedLoopMaxFrequency_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int frequency);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetClosedLoopMoveSpeed_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int speed);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetClosedLoopMoveSpeed_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetPosition_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int position);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetZeroPosition_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetPhysicalPositionKnown_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetPositionLimit_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int minPosition, signed int maxPosition);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetPositionLimit_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetAngleLimit_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int minAngle, signed int minRevolution, unsigned int maxAngle, signed int maxRevolution);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetAngleLimit_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner, End effector
SA_STATUS SA_SetReportOnComplete_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int report);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetStepWhileScan_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int step);

MCSCONTROL_API
SA_STATUS SA_SetSensorEnabled_A(SA_INDEX systemIndex, unsigned int enabled);

MCSCONTROL_API
SA_STATUS SA_GetSensorEnabled_A(SA_INDEX systemIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetSensorType_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int type);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetSensorType_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_SetAccumulateRelativePositions_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int accumulate);

MCSCONTROL_API // End effector
SA_STATUS SA_SetEndEffectorType_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int type, signed int param1, signed int param2);

MCSCONTROL_API // End effector
SA_STATUS SA_GetEndEffectorType_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // End effector
SA_STATUS SA_SetZeroForce_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

/*************************************************
**************************************************
**  Section IIb.2: Movement Control Functions   **
**************************************************
*************************************************/
MCSCONTROL_API // Positioner
SA_STATUS SA_StepMove_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int steps, unsigned int amplitude, unsigned int frequency);

MCSCONTROL_API // Positioner
SA_STATUS SA_ScanMoveAbsolute_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int target, unsigned int scanSpeed);

MCSCONTROL_API // Positioner
SA_STATUS SA_ScanMoveRelative_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int diff, unsigned int scanSpeed);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoPositionAbsolute_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int position, unsigned int holdTime);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoPositionRelative_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int diff, unsigned int holdTime);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoAngleAbsolute_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int angle, signed int revolution, unsigned int holdTime);

MCSCONTROL_API // Positioner
SA_STATUS SA_GotoAngleRelative_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int angleDiff, signed int revolutionDiff, unsigned int holdTime);

MCSCONTROL_API // Positioner, End effector
SA_STATUS SA_Stop_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_CalibrateSensor_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_FindReferenceMark_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int direction, unsigned int holdTime, unsigned int autoZero);

MCSCONTROL_API // End effector
SA_STATUS SA_GotoGripperOpeningAbsolute_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int opening, unsigned int speed);

MCSCONTROL_API // End effector
SA_STATUS SA_GotoGripperOpeningRelative_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int diff, unsigned int speed);

MCSCONTROL_API // End effector
SA_STATUS SA_GotoGripperForceAbsolute_A(SA_INDEX systemIndex, SA_INDEX channelIndex, signed int force, unsigned int speed, unsigned int holdTime);

/************************************************
*************************************************
**  Section IIb.3: Channel Feedback Functions  **
*************************************************
************************************************/
MCSCONTROL_API // Positioner
SA_STATUS SA_GetVoltageLevel_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetPosition_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner
SA_STATUS SA_GetAngle_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // Positioner, End effector
SA_STATUS SA_GetStatus_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // End effector
SA_STATUS SA_GetGripperOpening_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

MCSCONTROL_API // End effector
SA_STATUS SA_GetForce_A(SA_INDEX systemIndex, SA_INDEX channelIndex);

/******************
* Answer retrieval
******************/
MCSCONTROL_API
SA_STATUS SA_SetReceiveNotification_A(SA_INDEX systemIndex, HANDLE event);

MCSCONTROL_API
SA_STATUS SA_ReceiveNextPacket_A(SA_INDEX systemIndex, unsigned int timeout, SA_PACKET *packet);

MCSCONTROL_API
SA_STATUS SA_ReceiveNextPacketIfChannel_A(SA_INDEX systemIndex, SA_INDEX channelIndex, unsigned int timeout, SA_PACKET *packet);

MCSCONTROL_API
SA_STATUS SA_LookAtNextPacket_A(SA_INDEX systemIndex, unsigned int timeout, SA_PACKET *packet);

MCSCONTROL_API
SA_STATUS SA_DiscardPacket_A(SA_INDEX systemIndex);

#ifdef __cplusplus
}
#endif

#endif /* MCSCONTROL_H */
