# D3D12_VERTEX_BUFFER_VIEW structure

## Description

Describes a vertex buffer view.

## Members

### `BufferLocation`

Specifies a D3D12_GPU_VIRTUAL_ADDRESS that identifies the address of the buffer.

### `SizeInBytes`

Specifies the size in bytes of the buffer.

### `StrideInBytes`

Specifies the size in bytes of each vertex entry.

## Remarks

Use this structure with the [IASetVertexBuffers](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-iasetvertexbuffers) method.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)