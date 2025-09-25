## Description

Specifies the lifetime of a virtual camera.

## Constants

### `MFVirtualCameraLifetime_Session`

The camera persists until the [IMFVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfvirtualcamera) object is disposed or [IMFVirtualCamera::Shutdown](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-shutdown) is called. Afterwards, the virtual camera will no longer be enumerable or activatable on the device.

### `MFVirtualCameraLifetime_System`

The virtual camera persists across sessions and reboots.

## Remarks

Values from this enumeration are passed into [MFCreateVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-mfcreatevirtualcamera).

## See also

[MFCreateVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-mfcreatevirtualcamera)