# _D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU structure

## Description

**D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU** is used with [D3DKMTSignalSynchronizationObjectFromCpu](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobjectfromcpu) to enable a driver to signal a monitored fence.

## Members

### `hDevice` [in]

The handle to the device.

### `ObjectCount` [in]

The number of synchronization objects in the **ObjectHandleArray** and fence values in the **FenceValueArray**.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events to signal.

### `FenceValueArray` [in]

An array of 64 bit monitored fence values to signal, each corresponding to an object in the **ObjectHandleArray**.

### `Flags`

Flag options.

## See also

[D3DKMTSignalSynchronizationObjectFromCpu](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobjectfromcpu)