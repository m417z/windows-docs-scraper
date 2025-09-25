# D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMGPU structure

## Description

**D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMGPU** is used with [pfnWaitForSynchronizationObjectFromGpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectfromgpucb) to wait for a monitored fence to reach a certain value.

## Members

### `hContext` [in]

A kernel-mode handle to the context stream in which a wait for the synchronization events in the array that the **ObjectHandleArray** member specifies is inserted.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array and fence values in **MonitoredFenceValueArray** arrays.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events that the context that is specified by the **hContext** member waits for.

### `MonitoredFenceValueArray` [in]

An array of 64-bit monitored fence values to wait for, each value corresponding to a synchronization object in **ObjectHandleArray**.

### `FenceValue` [in]

Fence value to wait for when the input object is of type **D3DDDI_FENCE**.

### `Reserved`

This member is reserved and should be set to zero.

## See also

[pfnWaitForSynchronizationObjectFromGpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectfromgpucb)