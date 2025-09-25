# joyReleaseCapture function

## Description

The **joyReleaseCapture** function releases the specified captured joystick.

## Parameters

### `uJoyID`

Identifier of the joystick to be released. Valid values for *uJoyID* range from zero (JOYSTICKID1) to 15.

## Return value

Returns JOYERR_NOERROR if successful or one of the following error values.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NODRIVER** | The joystick driver is not present. |
| **MMSYSERR_INVALIDPARAM** | The specified joystick device identifier *uJoyID* is invalid. |
| **JOYERR_PARMS** | The specified joystick device identifier *uJoyID* is invalid. |

## Remarks

This method returns JOYERR_NOERROR when passed a valid joystick identifier that has not been captured.

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)