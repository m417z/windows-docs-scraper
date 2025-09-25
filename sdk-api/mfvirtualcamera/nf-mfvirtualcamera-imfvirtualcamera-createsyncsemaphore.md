## Description

A wrapper around the [IKsControl::KsEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ikscontrol-ksevent) method, which enables or disables an semaphore.

## Parameters

### `kseventSet`

A GUID representing the [KSEVENT.Set](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure) field.

### `kseventId`

A ULONG representing the **KSEVENT.Id** field.

### `kseventFlags`

A set of bit-wise or-ed flags representing the **KSEVENT.Flags** field.

### `semaphoreHandle`

A handle representing the **KSEVENTDATA.SemaphoreHandle.Semaphore** field.

### `semaphoreAdjustment`

An adjustment value representing the **KSEVENTDATA.SemaphoreHandle.Adjustment** field.

### `cameraSyncObject`

An output parameter that receives an [IMFSyncObject](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfcamerasyncobject) interface. The caller is responsible for releasing this object.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |

## Remarks

This method allows the caller to create a semaphore object between the caller and the virtual camera for synchronization. The virtual camera implementation will receive a call to **IKsControl::KsEvent** when this API is called. The resulting [IMFCameraSyncObject](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfcamerasyncobject) can be used to block on the event from the virtual camera.

When the **IMFCameraSyncObject** is obtained, the caller may choose to use the [IMFCameraSyncObject::WaitOnSignal](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfcamerasyncobject-waitonsignal) method or call [WaitForSingleObject](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) or [WaitForMultipleObjects](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjects) on the HANDLE that was provided to the **CreateSyncObject** method. The caller must not wait on both, as the signal on the event may only be set once by the driver.

The caller must call [IMFCameraSyncObject::Shutdown](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfvirtualcamera-shutdown) when the synchronization object is no longer needed regardless of whether the wait operation succeeded or not.

## See also

[IKsControl::KsEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ikscontrol-ksevent)

[IMFCameraSyncObject](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nn-mfvirtualcamera-imfcamerasyncobject)

[IMFCameraSyncObject::WaitOnSignal](https://learn.microsoft.com/windows/win32/api/mfvirtualcamera/nf-mfvirtualcamera-imfcamerasyncobject-waitonsignal)

[WaitForSingleObject](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject)

[WaitForMultipleObjects](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjects)