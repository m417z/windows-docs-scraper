# D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2 structure

## Description

**D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2** is used with [pfnSignalSynchronizationObjectFromGpu2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromgpu2cb) to signal a monitored fence.

## Members

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array and fence values in **MonitoredFenceValueArray** arrays.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events that the context that is specified by the **hContext** member waits for.

### `Flags` [in]

A [D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags) structure that indicates, in bit-field flags, signaling behavior.

### `BroadcastContextCount` [in]

The number of contexts this signal operation will be broadcast to.

### `BroadcastContextArray` [in]

An array of kernel-mode handles to the context streams in which a signal for the synchronization events in the array that the **ObjectHandleArray** member specifies is inserted. The synchronization events are considered signaled only when all broadcast contexts reach the signal insertion point.

### `FenceValue` [in]

A 64-bit value that specifies the current fence value of the GPU synchronization object. This value applies only if the GPU synchronization object is of type **D3DDDI_FENCE**.

### `CpuEventHandle` [in]

The handle of an event object that will be signaled when the signal command is processed. This member must be set only when **Flags.EnqueueCpuEvent** is specified.

### `MonitoredFenceValueArray` [in]

An array of 64-bit monitored fence values to signal, each of which correspond to a synchronization object in **ObjectHandleArray**.

### `Reserved`

This member is reserved and should be set to zero.

## See also

[D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags)

[pfnSignalSynchronizationObjectFromGpu2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectfromgpu2cb)