# D3DDDI_CREATECONTEXTFLAGS structure

## Description

The **D3DDDI_CREATECONTEXTFLAGS** structure describes how to create a context in a call to the [**pfnCreateContextCb**](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function.

## Members

### `NullRendering`

Specifies whether the GPU should process any commands that are sent by the context that is created. The **NullRendering** bit-field flag is set to inform the GPU not to process any commands that are sent by the context. The **NullRendering** bit-field flag is set only during performance investigating and debugging to simulate an infinitely fast rendering engine that still must perform the overhead of DMA buffer submission and signaling. **NullRendering** is never set during typical operations.

### `InitialData`

When set, indicates that the context is created with initial data.

### `DisableGpuTimeout`

When set, indicates that the GPU timeout is disabled for the context.

### `SynchronizationOnly`

When set, indicates that the context is created for synchronization purposes only, and not for rendering.

### `HwQueueSupported`

When set, indicates that the context supports hardware queues, which can improve efficiency in command processing.

### `NoKmdAccess`

When set, indicates that the context is created without kernel-mode driver (KMD) access. Added in WDDM 2.3.

### `TestContext`

When set, indicates that the context is created for testing purposes. Added in WDDM 2.3.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A member in the union that is contained in D3DDDI_CREATECONTEXTFLAGS that can hold one 32-bit value that identifies how to create the context.

## See also

[**D3DDDICB_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createcontext)

[**pfnCreateContextCb**](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85))