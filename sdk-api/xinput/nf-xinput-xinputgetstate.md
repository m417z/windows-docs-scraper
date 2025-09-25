# XInputGetState function

## Description

Retrieves the current state of the specified controller.

## Parameters

### `dwUserIndex` [in]

Index of the user's controller. Can be a value from 0 to 3. For information about how this value is determined and how the value maps to indicators on the controller, see [Multiple Controllers](https://learn.microsoft.com/windows/desktop/xinput/getting-started-with-xinput).

### `pState` [out]

Pointer to an [XINPUT_STATE](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_state) structure that receives the current state of the controller.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the controller is not connected, the return value is **ERROR_DEVICE_NOT_CONNECTED**.

If the function fails, the return value is an error code defined in Winerror.h. The function does not use **SetLastError** to set the calling thread's last-error code.

## Remarks

When **XInputGetState** is used to retrieve controller data, the left and right triggers are each reported separately. For legacy reasons, when DirectInput retrieves controller data, the two triggers share the same axis. The legacy behavior is noticeable in the current Game Device Control Panel, which uses DirectInput for controller state.

### Platform Requirements

Windows 8 (XInput 1.4), DirectX SDK (XInput 1.3), Windows Vista (XInput 9.1.0)

## See also

[XINPUT_GAMEPAD](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_gamepad)

[XINPUT_STATE](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_state)

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)

[XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate)