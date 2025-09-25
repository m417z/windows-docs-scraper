# D3D11_DRAW_INSTANCED_INDIRECT_ARGS structure

## Description

Arguments for draw instanced indirect.

## Members

### `VertexCountPerInstance`

The number of vertices to draw.

### `InstanceCount`

The number of instances to draw.

### `StartVertexLocation`

The index of the first vertex.

### `StartInstanceLocation`

A value added to each index before reading per-instance data from a vertex buffer.

## Remarks

The members of this structure serve the same purpose as the parameters of
[ID3D11DeviceContext::DrawInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawinstanced).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)