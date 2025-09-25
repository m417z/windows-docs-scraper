## Description

Shuts down the [IMFCameraSyncObject](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfcamerasyncobject).

## Remarks

**Shutdown** must be called on all sync objects created with calls to [IMFVirtualCamera::CreateSyncEvent](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-createsyncevent) or [IMFVirtualCamera::CreateSyncSemaphore](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-createsyncsemaphore).

For non-ONESHOT event or semaphore objects, **Shutdown** will unregister the event or semaphore handle with the virtual camera.

## See also

[IMFVirtualCamera::CreateSyncEvent](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-createsyncevent)
[IMFVirtualCamera::CreateSyncSemaphore](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-createsyncsemaphore)