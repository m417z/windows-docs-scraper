# D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS structure

## Description

Arguments for draw indexed instanced indirect.

## Members

### `IndexCountPerInstance`

The number of indices read from the index buffer for each instance.

### `InstanceCount`

The number of instances to draw.

### `StartIndexLocation`

The location of the first index read by the GPU from the index buffer.

### `BaseVertexLocation`

A value added to each index before reading a vertex from the vertex buffer.

### `StartInstanceLocation`

A value added to each index before reading per-instance data from a vertex buffer.

## Remarks

The members of this structure serve the same purpose as the parameters of
[ID3D11DeviceContext::DrawIndexedInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexedinstanced).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)