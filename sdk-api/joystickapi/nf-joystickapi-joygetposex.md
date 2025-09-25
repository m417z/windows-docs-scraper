# joyGetPosEx function

## Description

The **joyGetPosEx** function queries a joystick for its position and button status.

## Parameters

### `uJoyID`

Identifier of the joystick to be queried. Valid values for *uJoyID* range from zero (JOYSTICKID1) to 15.

### `pji`

Pointer to a [JOYINFOEX](https://learn.microsoft.com/previous-versions/dd757112(v=vs.85)) structure that contains extended position information and button status of the joystick. You must set the **dwSize** and **dwFlags** members or **joyGetPosEx** will fail. The information returned from **joyGetPosEx** depends on the flags you specify in **dwFlags**.

## Return value

Returns JOYERR_NOERROR if successful or one of the following error values.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NODRIVER** | The joystick driver is not present. |
| **MMSYSERR_INVALPARAM** | An invalid parameter was passed. |
| **MMSYSERR_BADDEVICEID** | The specified joystick identifier is invalid. |
| **JOYERR_UNPLUGGED** | The specified joystick is not connected to the system. |
| **JOYERR_PARMS** | The specified joystick identifier is invalid. |

## Remarks

This function provides access to extended devices such as rudder pedals, point-of-view hats, devices with a large number of buttons, and coordinate systems using up to six axes. For joystick devices that use three axes or fewer and have fewer than four buttons, use the [joyGetPos](https://learn.microsoft.com/previous-versions/dd757107(v=vs.85)) function.

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)