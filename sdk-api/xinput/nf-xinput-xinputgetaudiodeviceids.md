# XInputGetAudioDeviceIds function

## Description

Retrieves the sound rendering and sound capture audio device IDs that are associated with the headset connected to the specified controller.

## Parameters

### `dwUserIndex` [in]

Index of the gamer associated with the device.

### `pRenderDeviceId` [out, optional]

Windows Core Audio device ID string for render (speakers).

### `pRenderCount` [in, out, optional]

Size, in wide-chars, of the render device ID string buffer.

### `pCaptureDeviceId` [out, optional]

Windows Core Audio device ID string for capture (microphone).

### `pCaptureCount` [in, out, optional]

Size, in wide-chars, of capture device ID string buffer.

## Return value

If the function successfully retrieves the device IDs for render and capture, the return code is **ERROR_SUCCESS**.

If there is no headset connected to the controller, the function will also retrieve **ERROR_SUCCESS** with **NULL** as the values for *pRenderDeviceId* and *pCaptureDeviceId*.

If the controller port device is not physically connected, the function will return **ERROR_DEVICE_NOT_CONNECTED**.

If the function fails, it will return a valid Win32 error code.

## Remarks

Callers must allocate the memory for the buffers passed to **XInputGetAudioDeviceIds**. The resulting strings can be of arbitrary length.

### Platform Requirements

Windows 8 (XInput 1.4)

## See also

[Core Audio APIs](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-apis-in-windows-vista)

[XInput Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)

[XInputGetDSoundAudioDeviceGuids](https://learn.microsoft.com/windows/desktop/api/xinput/nf-xinput-xinputgetdsoundaudiodeviceguids)