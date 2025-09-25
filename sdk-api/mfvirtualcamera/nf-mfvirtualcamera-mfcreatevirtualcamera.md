## Description

Creates a virtual camera object which can be used by the caller to register, unregister, or remove the virtual camera from the system.

## Parameters

### `type`

A member of the [MFVirtualCameraType](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameratype) enumeration specifying the virtual camera type. In the current release, only **MFVirtualCameraType_SoftwareCameraSource** is supported.

### `lifetime`

A member of the [MFVirtualCameraLifetime](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameralifetime) enumeration specifying the lifetime of the camera. If **MFVirtualCameraLifetime_Session** is specified, when the returned [IMFVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfvirtualcamera) object is disposed or [IMFVirtualCamera::Shutdown](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-shutdown) is called, the virtual camera will no longer be enumerable or activatable on the device. If you want the virtual camera to persist across sessions and/or across reboots, you must specify the value **MFVirtualCameraLifetime_System**.

### `access`

A member of the [MFVirtualCameraAccess](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameraaccess) enumeration specifying the access scope of the created virtual camera. If **MFVirtualCameraAccess_CurrentUser** is specified, the virtual camera is only created for the user account that called the **MFCreateVirtualCamera**. If **MFVirtualCameraAccess_AllUsers** is specified, all users on the device will be able to enumerate or activate the virtual camera. To create a virtual camera with **MFVirtualCameraAccess_AllUsers**, the caller of **MFCreateVirtualCamera** must have administrator permissions.

### `friendlyName`

A null-terminated, user-readable Unicode string friendly name for the created virtual camera. The pipeline will automatically append “Windows Virtual Camera” to the provided friendly name to ensure end users can distinguish virtual cameras from physical cameras based on the friendly name. This parameter must not be nullptr.

### `sourceId`

The unique CLSID of the custom media source to be activated for this virtual camera. The string must be in the “{CLSID}” format. This parameter must not be nullptr.

### `categories`

An optional list of device interface categories under which the virtual camera is registered. If a non-administrator user is invoking **MFCreateVirtualCamera**, the categories must be a subset of the following values:
- [KSCATEGORY_VIDEO_CAMERA](https://learn.microsoft.com/windows-hardware/drivers/install/kscategory-video-camera)
- [KSCATEGORY_VIDEO](https://learn.microsoft.com/windows-hardware/drivers/install/kscategory-video)
- [KSCATEGORY_CAPTURE](https://learn.microsoft.com/windows-hardware/drivers/install/kscategory-capture)
- [KSCATEGORY_SENSOR_CAMERA](https://learn.microsoft.com/windows-hardware/drivers/install/kscategory-sensor-camera)

If nullptr is specified, the virtual camera is registered under the KSCATEGORY_VIDEO_CAMERA, KSCATEGORY_VIDEO and KSCATEGORY_CAPTURE categories.

### `categoryCount`

The number of categories provided in the *categories* parameter. If *categories* is nullptr, *categoryCount* must be 0.

### `virtualCamera`

Output parameter that receives the newly created [IMFVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfvirtualcamera). This parameter must not be nullptr.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_INVALIDARG | An input parameter is invalid. |
| E_POINTER | The *virtualCamera* parameter is nullptr. |
| E_ACCESSDENIED | Privacy control is set to deny access to the camera for the app, user, or system. Or the caller is not an administrator and the parameters provided are only valid for administrator access. |

## Remarks

The virtual camera created by **MFCreateVirtualCamera** is keyed off the parameters passed in to this API. By keeping the same parameters, applications can re-open the same virtual camera. When called for the first time, the resulting [IMFVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfvirtualcamera) contains a set of configuration information which may be modified or updated by the caller to create a new instance of a virtual camera. If the same parameters are used for this function on subsequent calls, the resulting **IMFVirtualCamera** will open the existing virtual camera when the [IMFVirtualCamera::Start](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-start) or [IMFVirtualCamera::Stop](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-stop) method is called. Calling [IMFVirtualCamera::Remove](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-remove) will remove the existing virtual camera. If MFVirtualCameraAccess_CurrentUser is specified for the *access* parameter, each user account gets a unique virtual camera.

UWP and Packaged Application must declare the *webcam* device capability in their manifest in order to use this API. This API is also subject to the webcam privacy control so when privacy is set to deny access, this API will result in an E_ACCESSDENIED failure.

> [!NOTE]
> UWP and Packaged Apps must not invoke **MFCreateVirtualCamera** on their UI thread. Doing so will potentially trigger a deadlock as the Capability Access Manager check for the webcam access consent dialog will be blocked.

## See also

[IMFVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfvirtualcamera)
[MFVirtualCameraType](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameratype)
[MFVirtualCameraLifetime](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameralifetime)
[MFVirtualCameraAccess](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameraaccess)