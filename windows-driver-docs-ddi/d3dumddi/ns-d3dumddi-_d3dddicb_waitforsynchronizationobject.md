# _D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT structure

## Description

The D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT structure describes the parameters that are required to set up the wait in a call to the [pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb) function.

## Members

### `hContext` [in]

A handle to a context that waits for the synchronization events in the array that the **ObjectHandleArray** member specifies to occur.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array.

### `ObjectHandleArray` [in]

An array of handles to the synchronization events that the context that is specified by the **hContext** member waits for. The **D3DDDI_MAX_OBJECT_WAITED_ON** constant, which is defined as 32, indicates the maximum number of synchronization events that the context can wait for.

## See also

[pfnWaitForSynchronizationObjectCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectcb)