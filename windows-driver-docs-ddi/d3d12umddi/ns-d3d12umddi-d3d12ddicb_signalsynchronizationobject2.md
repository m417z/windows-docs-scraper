# D3D12DDICB_SIGNALSYNCHRONIZATIONOBJECT2 structure

## Description

Signals a synchronization object.

## Members

### `hContext` [in]

Specify the context that should signal the objects.

### `ObjectCount` [in]

Number of object to signal.

### `ObjectHandleArray` [in]

A handle to an array of synchronization objects to signal.

### `Flags` [in]

Specify signal behavior.

### `BroadcastContextCount` [in]

Specifies the number of context to broadcast this signal buffer to.

### `BroadcastContext` [in]

A handle an array of context to broadcast to.

### `FenceValue` [in]

Fence value to be signaled.

### `CpuEventHandle` [in]

Handle of a CPU event to be signaled.

## Remarks

## See also