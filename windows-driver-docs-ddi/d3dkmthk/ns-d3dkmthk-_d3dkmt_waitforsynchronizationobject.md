# _D3DKMT_WAITFORSYNCHRONIZATIONOBJECT structure

## Description

The D3DKMT_WAITFORSYNCHRONIZATIONOBJECT structure contains information about the synchronization events that the [D3DKMTWaitForSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject) function waits for to occur.

## Members

### `hContext` [in]

A kernel-mode handle to the context stream in which a wait for the synchronization events in the array that the **ObjectHandleArray** member specifies is inserted.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events that the context that is specified by the **hContext** member waits for. The D3DDDI_MAX_OBJECT_WAITED_ON constant, which is defined as 32, indicates the maximum number of synchronization events that the context can wait for.

## See also

[D3DKMTWaitForSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject)