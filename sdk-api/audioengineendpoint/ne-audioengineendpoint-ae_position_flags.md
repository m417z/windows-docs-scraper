# AE_POSITION_FLAGS enumeration

## Description

Defines constants for the [AE_CURRENT_POSITION](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/ns-audioengineendpoint-ae_current_position) structure. These constants describe the degree of validity of the current position.

## Constants

### `POSITION_INVALID`

The position is not valid and must not be used.

### `POSITION_DISCONTINUOUS`

The position is valid; however, there has been
a disruption such as a glitch or state transition.
This current position is not correlated with the previous position. The start of a stream should not reflect a discontinuity.

### `POSITION_CONTINUOUS`

The position is valid. The previous packet and the current packet are both synchronized with the timeline.

### `POSITION_QPC_ERROR`

The quality performance counter (QPC) timer value associated with this position is not accurate. This flag is set when a position error is encountered and the implementation is unable to compute an accurate QPC value that correlates with the position.

## Remarks

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.