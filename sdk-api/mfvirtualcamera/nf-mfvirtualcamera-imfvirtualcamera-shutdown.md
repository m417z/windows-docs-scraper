## Description

Releases all of the virtual camera's internal resources.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |

## Remarks

When **Shutdown** is called, all objects created through the **IMFVirtualCamera** APIs will also be shutdown. This includes [IMFCameraSyncObject](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfcamerasyncobject) objects obtained through calls to [IMFVirtualCamera::CreateSyncEvent](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-createsyncevent) or [CreateSyncSemaphore](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-createsyncsemaphore) and [IMFMediaSource](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfmediasource) objects obtained through a call to [IMFVirtualCamera::GetMediaSource](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-getmediasource). Attempts to use any object obtained from the **IMFVirtualCamera** after **Shutdown** has been called will result in an MF_E_SHUTDOWN error.

For virtual cameras created with a lifetime value of [MFVirtualCameraLifeTime_Session](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/ne-mfvirtualcamera-mfvirtualcameralifetime), when **Shutdown** is called, the virtual camera will be removed from the system. Any application using the virtual camera will receive the device invalidated error MF_E_VIDEO_RECORDING_DEVICE_INVALIDATED.

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfmediasource)
[IMFVirtualCamera::GetMediaSource](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-getmediasource)