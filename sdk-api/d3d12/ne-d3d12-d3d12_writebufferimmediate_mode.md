# D3D12_WRITEBUFFERIMMEDIATE_MODE enumeration

## Description

Specifies the mode used by a **WriteBufferImmediate** operation.

## Constants

### `D3D12_WRITEBUFFERIMMEDIATE_MODE_DEFAULT:0`

The write operation behaves the same as normal copy-write operations.

### `D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_IN:0x1`

The write operation is guaranteed to occur after all preceding commands in the command stream have started, including previous **WriteBufferImmediate** operations.

### `D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_OUT:0x2`

The write operation is deferred until all previous commands in the command stream have completed through the GPU pipeline, including previous **WriteBufferImmediate** operations. Write operations that specify **D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_OUT** don't block subsequent operations from starting. If there are no previous operations in the command stream, then the write operation behaves as if **D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_IN** was specified.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[ID3D12GraphicsCommandList::WriteBufferImmediate](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist2)