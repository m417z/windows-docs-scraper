# PFND3DDDI_CREATESYNCHRONIZATIONOBJECT2CB callback function

## Description

Creates a GPU synchronization object that a device context can signal and wait for. Used by WDDM 1.2 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (that is, the graphics context) that will own the synchronization object that *pfnCreateSynchronizationObject2Cb* creates.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject2) structure that describes the synchronization object to create.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The synchronization object was successfully created.|
|E_OUTOFMEMORY|The function could not allocate memory that was required for it to complete.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The *pfnCreateSynchronizationObject2Cb* function returns a kernel-mode handle to the newly created synchronization object in the **hSyncObject** member of the [D3DDDICB_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject2) structure that the *pData* parameter points to. The user-mode display driver passes this handle in calls to the following functions:

* [pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)
* [pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb)
* [pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb)
* [pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb)
* [pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb)

## See also

[D3DDDICB_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject2)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)

[pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb)

[pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb)