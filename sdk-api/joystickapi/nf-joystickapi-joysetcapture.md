# joySetCapture function

## Description

The **joySetCapture** function captures a joystick by causing its messages to be sent to the specified window.

## Parameters

### `hwnd`

Handle to the window to receive the joystick messages.

### `uJoyID`

Identifier of the joystick to be captured. Valid values for *uJoyID* range from zero (JOYSTICKID1) to 15.

### `uPeriod`

Polling frequency, in milliseconds.

### `fChanged`

Change position flag. Specify **TRUE** for this parameter to send messages only when the position changes by a value greater than the joystick movement threshold. Otherwise, messages are sent at the polling frequency specified in *uPeriod*.

## Return value

Returns JOYERR_NOERROR if successful or one of the following error values.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NODRIVER** | The joystick driver is not present. |
| **MMSYSERR_INVALPARAM** | Invalid joystick ID or hwnd is **NULL**. |
| **JOYERR_NOCANDO** | Cannot capture joystick input because a required service (such as a Windows timer) is unavailable. |
| **JOYERR_UNPLUGGED** | The specified joystick is not connected to the system. |
| **JOYERR_PARMS** | Invalid joystick ID or hwnd is **NULL**. |

## Remarks

If the specified joystick is currently captured, the function returns undefined behavior. Call the [joyReleaseCapture](https://learn.microsoft.com/previous-versions/dd757113(v=vs.85)) function to release the captured joystick, or destroy the window to release the joystick automatically.

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)