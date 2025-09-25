# XInputSetState function

## Description

Sends data to a connected controller. This function is used to activate the vibration function of a controller.

## Parameters

### `dwUserIndex` [in]

Index of the user's controller. Can be a value from 0 to 3. For information about how this value is determined and how the value maps to indicators on the controller, see [Multiple Controllers](https://learn.microsoft.com/windows/desktop/xinput/getting-started-with-xinput).

### `pVibration` [in, out]

Pointer to an [XINPUT_VIBRATION](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_vibration) structure containing the vibration information to send to the controller.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the controller is not connected, the return value is **ERROR_DEVICE_NOT_CONNECTED**.

If the function fails, the return value is an error code defined in WinError.h. The function does not use *SetLastError* to set the calling thread's last-error code.

## See also

[XINPUT_VIBRATION](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_vibration)

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)

[XInputGetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetstate)