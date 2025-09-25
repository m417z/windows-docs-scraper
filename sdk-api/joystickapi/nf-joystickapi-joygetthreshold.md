# joyGetThreshold function

## Description

The **joyGetThreshold** function queries a joystick for its current movement threshold.

## Parameters

### `uJoyID`

Identifier of the joystick. Valid values for *uJoyID* range from zero (JOYSTICKID1) to 15.

### `puThreshold`

Pointer to a variable that contains the movement threshold value.

## Return value

Returns JOYERR_NOERROR if successful or one of the following error values.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NODRIVER** | The joystick driver is not present. |
| **MMSYSERR_INVALPARAM** | An invalid parameter was passed. |

## Remarks

The movement threshold is the distance the joystick must be moved before a joystick position-change message ([MM_JOY1MOVE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-joy1move), [MM_JOY1ZMOVE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-joy1zmove), [MM_JOY2MOVE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-joy2move), or [MM_JOY2ZMOVE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-joy2zmove)) is sent to a window that has captured the device. The threshold is initially zero.

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)