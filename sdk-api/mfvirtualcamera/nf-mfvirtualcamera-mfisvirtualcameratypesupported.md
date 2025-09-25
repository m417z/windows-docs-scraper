## Description

Returns a value indicating if a particular virtual camera is supported on the current device.

## Parameters

### `type`

A member of the [MFVirtualCameraType](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameratype) enumeration specifying the virtual camera type for which support is being queried. In the current release, only **MFVirtualCameraType_SoftwareCameraSource** is supported.

### `supported`

An output parameter that receives a boolean indicating if the specified camera type is supported on the current device.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_INVALIDARG | An input parameter is invalid. |
| E_POINTER | The *supported* parameter is nullptr. |
| E_ACCESSDENIED | Privacy control is set to deny access to the camera for the app, user, or system. Or the caller is not an administrator and the parameters provided are only valid for administrator access. |

## Remarks

## See also

[MFVirtualCameraType](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameratype)