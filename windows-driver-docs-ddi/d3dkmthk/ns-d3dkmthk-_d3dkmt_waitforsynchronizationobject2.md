# _D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 structure

## Description

The D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 structure contains information about the synchronization events that the [D3DKMTWaitForSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject2) function waits for to occur.

## Members

### `hContext` [in]

A kernel-mode handle to the context stream in which a wait for the synchronization events in the array that the **ObjectHandleArray** member specifies is inserted.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events that the context that is specified by the **hContext** member waits for. The D3DDDI_MAX_OBJECT_WAITED_ON constant, which is defined as 32, indicates the maximum number of synchronization events that the context can wait for.

### `Fence`

A structure that contains information about a fence. The union in D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 can hold a Fence structure, which contains the following member:

### `Fence.FenceValue`

A 64-bit value that specifies the fence value to wait for.

### `Reserved`

An array of 64-bit values that are reserved for future use. The union in D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 can hold this array.

## See also

[D3DKMTWaitForSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject2)