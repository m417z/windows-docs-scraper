# D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMCPU structure

## Description

**D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMCPU** is used with [pfnSignalSynchronizationObjectFromCpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromcpucb) to enable a driver to signal a monitored fence.

## Members

### `ObjectCount` [in]

The number of synchronization objects in the **ObjectHandleArray** and fence values in the **FenceValueArray**.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events to signal.

### `FenceValueArray` [in]

An array of 64 bit monitored fence values to signal, each corresponding to an object in the **ObjectHandleArray**.

## See also

[pfnSignalSynchronizationObjectFromCpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromcpucb)