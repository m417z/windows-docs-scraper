# _D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 structure

## Description

The D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 structure contains information about the synchronization events that the [D3DKMTSignalSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobject2) function signals.

## Members

### `hContext` [in]

A kernel-mode handle to a context that signals the synchronization events in the array that the **ObjectHandleArray** member specifies.

### `ObjectCount` [in]

The number of synchronization events in the **ObjectHandleArray** array.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events that the context that is specified by the **hContext** member signals. The D3DDDI_MAX_OBJECT_SIGNALED constant, which is defined as 32, indicates the maximum number of synchronization events that the context can signal.

### `Flags` [in]

A [D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags) structure that indicates, in bit-field flags, signaling behavior.

### `BroadcastContextCount` [in]

The number of additional contexts in the array that **BroadcastContext** specifies.

### `BroadcastContext` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the additional contexts to broadcast the event to. The D3DDDI_MAX_BROADCAST_CONTEXT constant, which is defined as 64, defines the maximum number of contexts that the OpenGL ICD can broadcast the event to.

The original context that the **hContext** member specifies and that owns the event is not an element in the **BroadcastContext** array. For example, if the **BroadcastContext** array contains one element, the OpenGL ICD sends the event to the owning context (**hContext**) and broadcasts to that one additional context.

### `Fence`

A structure that contains information about a fence. The union in D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 can hold a Fence structure, which contains the following member:

### `Fence.FenceValue`

A 64-bit value that specifies the fence value to signal.

### `CpuEventHandle`

A handle to a CPU event that is to be signaled.

Supported starting with Windows 8.

### `Reserved`

An array of 64-bit values that are reserved for future use. The union in D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 can hold this array.

## See also

[D3DDDICB_SIGNALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_signalflags)

[D3DKMTSignalSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobject2)