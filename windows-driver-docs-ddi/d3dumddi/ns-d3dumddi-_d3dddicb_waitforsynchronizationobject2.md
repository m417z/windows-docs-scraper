# _D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT2 structure

## Description

Describes the parameters that are required to set up the wait in a call to the [pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb) function.

## Members

### `hContext` [in]

A handle to a Direct3D context that waits for the synchronization objects in the array that the **ObjectHandleArray** member specifies to occur.

### `ObjectCount` [in]

The number of synchronization objects in the **ObjectHandleArray** array.

**ObjectHandleArray** must be set to 1 if the GPU synchronization object is of type **D3DDDI_FENCE**—namely, the **Type** member of the [D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2) structure has a value of **D3DDDI_FENCE**.

### `ObjectHandleArray` [in]

An array of handles to the GPU synchronization objects that are to be signaled. The **D3DDDI_MAX_OBJECT_WAITED_ON** constant, which is defined as 32, indicates the maximum number of synchronization objects that the context can wait for.

All synchronization objects must be created on a logical adapter that has its context specified by the **hContext** member.

### `FenceValue` [in]

A 64-bit value that specifies the current fence value of the GPU synchronization object that is to be waited on.

This value applies only if the GPU synchronization object is of type **D3DDDI_FENCE**—namely, the **Type** member of the [D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2) structure has a value of **D3DDDI_FENCE**.

## Remarks

Synchronization objects of type **D3DDDI_CPU_NOTIFICATION** cannot be used to wait on calls to [pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb).

## See also

[D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2)

[pfnWaitForSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobject2cb)