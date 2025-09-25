# XInputGetKeystroke function

## Description

Retrieves a gamepad input event.

## Parameters

### `dwUserIndex`

[in] Index of the signed-in gamer associated with the device. Can be a value in the range 0–XUSER_MAX_COUNT − 1, or XUSER_INDEX_ANY to fetch the next available input event from any user.

### `dwReserved`

[in] Reserved

### `pKeystroke`

[out] Pointer to an [XINPUT_KEYSTROKE](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_keystroke) structure that receives an input event.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If no new keys have been pressed, the return value is **ERROR_EMPTY**.

If the controller is not connected or the user has not activated it, the return value is **ERROR_DEVICE_NOT_CONNECTED**. See the Remarks section below.

If the function fails, the return value is an error code defined in Winerror.h. The function does not use [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set the calling thread's last-error code.

## Remarks

Wireless controllers are not considered active upon system startup, and calls to any of the *XInput* functions before a wireless controller is made active return **ERROR_DEVICE_NOT_CONNECTED**. Game titles must examine the return code and be prepared to handle this condition. Wired controllers are automatically activated when they are inserted. Wireless controllers are activated when the user power on the controller.

### Platform Requirements

Windows 8 (XInput 1.4), DirectX SDK (XInput 1.3)

## See also

[XINPUT_KEYSTROKE](https://learn.microsoft.com/windows/desktop/api/xinput/ns-xinput-xinput_keystroke)

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)