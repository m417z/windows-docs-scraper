# XInputGetCapabilities function

## Description

Retrieves the capabilities and features of a connected controller.

## Parameters

### `dwUserIndex` [in]

Index of the user's controller. Can be a value in the range 0–3. For information about how this value is determined and how the value maps to indicators on the controller, see [Multiple Controllers](https://learn.microsoft.com/windows/desktop/xinput/getting-started-with-xinput).

### `dwFlags` [in]

Input flags that identify the controller type. If this value is 0, then the capabilities of all controllers connected to the system are returned. Currently, only one value is supported:

| Value | Description |
| --- | --- |
| **XINPUT_FLAG_GAMEPAD** | Limit query to devices of controller type. |

Any value of *dwflags* other than the above or 0 is illegal and will result in an error break when debugging.

### `pCapabilities` [out]

Pointer to an [XINPUT_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_capabilities) structure that receives the controller capabilities.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the controller is not connected, the return value is **ERROR_DEVICE_NOT_CONNECTED**.

If the function fails, the return value is an error code defined in WinError.h. The function does not use *SetLastError* to set the calling thread's last-error code.

## Remarks

**Note** The legacy XINPUT 9.1.0 version (included in Windows Vista and later) always returned a fixed set of capabilities regardless of attached device.

### Platform Requirements

Windows 8 (XInput 1.4), DirectX SDK (XInput 1.3), Windows Vista (XInput 9.1.0)

## See also

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)

[XInputGetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetstate)

[XInputSetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputsetstate)