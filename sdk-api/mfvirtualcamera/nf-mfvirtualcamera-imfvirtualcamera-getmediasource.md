## Description

Gets an [IMFMediaSource](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfmediasource) that provides media data from the virtual camera.

## Parameters

### `ppMediaSource`

A shared-client **IMFMediaSource** from the virtual camera.

## Return value

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |

## Remarks

**GetMediaSource** may not be called until after [IMFVirtualCamera::Start](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-start) has been successfully called. The **IMFMediaSource** returned in the *ppMediaSource* parameter is a media source that has reduced functionality. It is internally marked as a shared client. This media source is intended for apps to use as a local preview during virtual camera activation and configuration process.

If a full function **IMFMediaSource** is needed, the app must call [MFCreateDeviceSource](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfcreatedevicesource) using the symbolic link name returned in the **IMFAttributes** after a **IMFVirtualCamera::Start** call. Doing so, however will result in an exclusive-control media source being created which, when activated, will lock out all other apps from using the virtual camera.

The lifetime of the **IMFMediaSource** retrieved by this method is directly tied to the lifetime of the [IMFVirtualCamera](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfvirtualcamera) from which it is obtained. If the **IMFVirtualCamera** is disposed or [IMFVirtualCamera::Shutdown](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-shutdown) is called, the IMFMediaSource obtained from this method will also be shutdown.

## See also

[IMFVirtualCamera::Start](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-start)

[MFCreateDeviceSource](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfcreatedevicesource)

[IMFVirtualCamera::Shutdown](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-shutdown)