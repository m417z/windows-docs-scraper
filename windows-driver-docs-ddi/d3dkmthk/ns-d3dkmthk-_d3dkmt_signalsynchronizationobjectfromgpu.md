# _D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU structure

## Description

**D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU** is used with [D3DKMTSignalSynchronizationObjectFromGpu](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobjectfromgpu) to signal a monitored fence.

## Members

### `hContext` [in]

A kernel-mode handle to the context stream.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array and fence values in **MonitoredFenceValueArray** arrays.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events that the **hContext** member signals.

### `MonitoredFenceValueArray` [in]

An array of 64-bit monitored fence values to signal, each of which correspond to a synchronization object in **ObjectHandleArray**.

### `Reserved`

This member is reserved and should be set to zero.

## See also

[D3DKMTSignalSynchronizationObjectFromGpu](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobjectfromgpu)