# _D3DDDICB_CREATEHWQUEUE structure

## Description

A structure that holds information to create a hardware queue.

## Members

### `hHwContext`

Handle to the context the queue is created for.

### `Flags`

Queue creation flags.

### `PrivateDriverDataSize`

 Size of private driver data.

### `pPrivateDriverData`

Pointer to private driver data.

### `hHwQueue`

Handle to the created queue.

### `hHwQueueProgressFence`

Handle to the hardware queue progress fence object.

### `HwQueueProgressFenceCPUVirtualAddress`

Read-only mapping of the fence value for the CPU

### `HwQueueProgressFenceGPUVirtualAddress`

Read/write mapping of the fence value for the GPU