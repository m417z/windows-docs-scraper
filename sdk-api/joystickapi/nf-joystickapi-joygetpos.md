# joyGetPos function

## Description

The **joyGetPos** function queries a joystick for its position and button status.

## Parameters

### `uJoyID`

Identifier of the joystick to be queried. Valid values for *uJoyID* range from zero (JOYSTICKID1) to 15.

### `pji`

Pointer to a [JOYINFO](https://learn.microsoft.com/previous-versions/dd757110(v=vs.85)) structure that contains the position and button status of the joystick.

## Return value

Returns JOYERR_NOERROR if successful or one of the following error values.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NODRIVER** | The joystick driver is not present. |
| **MMSYSERR_INVALPARAM** | An invalid parameter was passed. |
| **JOYERR_UNPLUGGED** | The specified joystick is not connected to the system. |

## Remarks

For devices that have four to six axes of movement, a point-of-view control, or more than four buttons, use the [joyGetPosEx](https://learn.microsoft.com/previous-versions/dd757108(v=vs.85)) function.

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)