# PFND3DDDI_CREATESYNCHRONIZATIONOBJECTCB callback function

## Description

The **pfnCreateSynchronizationObjectCb** function creates a synchronization object that a device context can signal and wait for.

## Parameters

### `hDevice`

A handle to the display device (that is, the graphics context) that will own the synchronization object that **pfnCreateSynchronizationObjectCb** creates.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_CREATESYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject) structure that describes the synchronization object to create.

## Return value

**pfnCreateSynchronizationObjectCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The synchronization object was successfully created.|
|E_OUTOFMEMORY|pfnCreateSynchronizationObjectCb could not allocate memory that was required for it to complete.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The **pfnCreateSynchronizationObjectCb** function returns a kernel-mode handle to the newly created synchronization object in the **hSyncObject** member of the [D3DDDICB_CREATESYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject) structure that the *pData* parameter points to. The user-mode display driver passes this handle in calls to the following functions:

* [pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)
* [pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb)
* [pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb)

## See also

[D3DDDICB_CREATESYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)

[pfnSignalSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb)

[pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb)