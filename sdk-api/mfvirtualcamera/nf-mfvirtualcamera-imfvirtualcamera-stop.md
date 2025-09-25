## Description

Disables the registered virtual camera, blocking apps from being able to enumerate or activate the virtual camera.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_ACCESSDENIED | The virtual camera is a system wide camera and the caller does not have permissions to remove it.

## Remarks

Calling **Stop** while the virtual camera is in use will result in those applications receiving a MF_E_VIDEO_RECORDING_DEVICE_INVALIDATED error.

## See also