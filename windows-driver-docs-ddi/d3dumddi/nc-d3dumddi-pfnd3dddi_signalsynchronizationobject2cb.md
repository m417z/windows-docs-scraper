# PFND3DDDI_SIGNALSYNCHRONIZATIONOBJECT2CB callback function

## Description

Inserts a signal on the specified synchronization objects in the specified context direct memory access (DMA) stream. Used by WDDM 1.2 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to a display device (that is, the graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject2) structure that describes the synchronization objects and context DMA stream that signaling is set up on.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The signaling was successfully set up.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The [pfnCreateSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobject2cb) function returns a kernel-mode handle to the newly created synchronization object in the **hSyncObject** member of the [D3DDDICB_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject2) structure that the *pData* parameter points to. The user-mode display driver passes this handle in calls to the following functions:

* [pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)
* *pfnSignalSynchronizationObject2Cb*
* [pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb)

The *pfnSignalSynchronizationObject2Cb* function submits a signal command to the command stream of all Microsoft Direct3D contexts that are specified by the **hContext** and **BroadcastContext** members of the [D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject2) structure. The synchronization objects are signaled only when all submitted signal commands are processed.

If synchronization objects are of type **D3DDDI_FENCE** (where [D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2).**Type** = **D3DDDI_FENCE**), they must be submitted only one at a time, and [D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject2).*ObjectCount* must have a value of 1.

## See also

[D3DDDICB_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject2)

[D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject2)

[pfnCreateSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobject2cb)

[pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)

[pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb)