## Description

Specifies the access restrictions for a virtual camera.

## Constants

### `MFVirtualCameraAccess_CurrentUser`

The virtual camera can only be accessed by the current user.

### `MFVirtualCameraAccess_AllUsers`

The virtual camera can be accessed by all users.

## Remarks

Values from this enumeration are passed into [MFCreateVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-mfcreatevirtualcamera). To create a virtual camera with **MFVirtualCameraAccess_AllUsers**, the caller of **MFCreateVirtualCamera** must have administrator permissions.

## See also

[MFCreateVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-mfcreatevirtualcamera)