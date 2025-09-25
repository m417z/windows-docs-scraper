# XInputEnable function

## Description

Sets the reporting state of XInput.

## Parameters

### `enable` [in]

If enable is **FALSE**, XInput will only send neutral data in response to [XInputGetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetstate) (all buttons up, axes centered, and triggers at 0). [XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate) calls will be registered but not sent to the device. Sending any value other than **FALSE**  will restore reading and writing functionality to normal.

## Remarks

This function is meant to be called when an application gains or loses focus (such as via [WM_ACTIVATEAPP](https://learn.microsoft.com/windows/desktop/winmsg/wm-activateapp)). Using this function, you will not have to change the XInput query loop in your application as neutral data will always be reported if XInput is disabled.

In a controller that supports vibration effects:

* Passing **FALSE** will stop any vibration effects currently playing. In this state, calls to [XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate) will be registered, but not passed to the device.
* Passing **TRUE** will pass the last vibration request (even if it is 0) sent to [XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate) to the device.

**Windows 10 or later:** *Deprecated*, as game controller input is automatically enabled/disabled by the system based on the application window focus.

### Platform Requirements

Windows 8 (XInput 1.4), DirectX SDK (XInput 1.3)

## See also

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad)

[XINPUT_STATE](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_state)

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)

[XInputGetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetstate)

[XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate)