# PFND3DDDI_WAITFORSYNCHRONIZATIONOBJECT2CB callback function

## Description

Inserts a wait command for the specified synchronization objects in the specified context command stream. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to a display device (that is, the graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_waitforsynchronizationobject2) structure that describes the synchronization objects and context DMA stream that are required to set up the wait.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The wait was successfully set up. |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect. |

This function might also return other HRESULT values.

## Remarks

The [pfnCreateSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobject2cb) function returns a kernel-mode handle to the newly created synchronization object in the **hSyncObject** member of the [D3DDDICB_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject2) structure that the *pData* parameter points to. The user-mode display driver passes this handle in calls to the following functions:

* [pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)
* [pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb)
* *pfnWaitForSynchronizationObject2Cb*

Do not call this function if the synchronization object is of type **D3DDDI_CPU_NOTIFICATION**—namely, the **Type** member of the [D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2) structure has a value of **D3DDDI_CPU_NOTIFICATION**.[pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)

## See also

[D3DDDICB_CREATESYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject2)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2)

[pfnCreateSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createsynchronizationobject2cb)

[pfnDestroySynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroysynchronizationobjectcb)

[pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb)