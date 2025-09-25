# _D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2 structure

## Description

Describes the parameters that are required to set up signaling in a call to the [pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb) function.

## Members

### `hContext` [in]

A handle to a Direct3D context that signals the synchronization events in the array that the **ObjectHandleArray** member specifies.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array.

### `ObjectHandleArray` [in]

An array of handles to the synchronization events that the context that is specified by the **hContext** member signals. The **D3DDDI_MAX_OBJECT_SIGNALED** constant, which is defined as 32, indicates the maximum number of synchronization events that the context can signal.

All synchronization objects must be created on the same logical adapter as the context specified by **hContext**.

### `Flags` [in]

A [D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags) structure that indicates, in bit-field flags, signaling behavior.

### `BroadcastContextCount` [in]

The number of contexts to broadcast this signal buffer to.

### `BroadcastContext` [in]

An array of **D3DKMT_HANDLE** data types that represent kernel-mode handles to the additional contexts to broadcast the current signal command to. The **D3DDDI_MAX_BROADCAST_CONTEXT** constant, which is defined as 64, defines the maximum number of synchronization events that the context can signal to.

All contexts must be created for the same Direct3D device and the context that is specified by **hContext**.

### `FenceValue` [in]

A 64-bit value that specifies the current fence value of the GPU synchronization object.

This value applies only if the GPU synchronization object is of type **D3DDDI_FENCE**—namely, the **Type** member of the [D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2) structure has a value of **D3DDDI_FENCE**.

### `CpuEventHandle` [in]

The handle of an event object that will be signaled when the signal command is processed. This member must be set only when **Flags**.**EnqueueCpuEvent** is specified.

## See also

[D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags)

[D3DDDI_SYNCHRONIZATIONOBJECTINFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2)

[pfnSignalSynchronizationObject2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb)