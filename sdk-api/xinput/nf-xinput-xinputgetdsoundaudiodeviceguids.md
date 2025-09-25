# XInputGetDSoundAudioDeviceGuids function

## Description

Gets the sound rendering and sound capture device GUIDs that are associated with the headset connected to the specified controller.

## Parameters

### `dwUserIndex`

[in] Index of the user's controller. It can be a value in the range 0–3. For information about how this value is determined and how the value maps to indicators on the controller, see [Multiple Controllers](https://learn.microsoft.com/windows/desktop/xinput/getting-started-with-xinput).

### `pDSoundRenderGuid`

[out] Pointer that receives the GUID of the headset sound rendering device.

### `pDSoundCaptureGuid`

[out] Pointer that receives the GUID of the headset sound capture device.

## Return value

If the function successfully retrieves the device IDs for render and capture, the return code is **ERROR_SUCCESS**.

If there is no headset connected to the controller, the function also retrieves **ERROR_SUCCESS** with **GUID_NULL** as the values for *pDSoundRenderGuid* and *pDSoundCaptureGuid*.

If the controller port device is not physically connected, the function returns **ERROR_DEVICE_NOT_CONNECTED**.

If the function fails, it returns a valid Win32 error code.

## Remarks

Use of legacy [DirectSound](https://learn.microsoft.com/previous-versions/windows/desktop/ee416960(v=vs.85)) is not recommended, and DirectSound is not available for Windows Store apps.

**Note** **XInputGetDSoundAudioDeviceGuids** is deprecated because it isn't supported by Windows 8 (XInput 1.4).

### Platform Requirements

DirectX SDK (XInput 1.3), Windows Vista (XInput 9.1.0)

## See also

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)

[XInputGetState](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetstate)