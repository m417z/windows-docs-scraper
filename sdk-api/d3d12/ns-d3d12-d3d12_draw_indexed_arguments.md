# D3D12_DRAW_INDEXED_ARGUMENTS structure

## Description

Describes parameters for drawing indexed instances.

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
[DrawIndexedInstanced](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-drawindexedinstanced).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)