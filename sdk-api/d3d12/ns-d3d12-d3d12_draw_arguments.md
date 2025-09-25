# D3D12_DRAW_ARGUMENTS structure

## Description

Describes parameters for drawing instances.

## Members

### `VertexCountPerInstance`

Specifies the number of vertices to draw, per instance.

### `InstanceCount`

Specifies the number of instances.

### `StartVertexLocation`

Specifies an index to the first vertex to start drawing from.

### `StartInstanceLocation`

Specifies an index to the first instance to start drawing from.

## Remarks

The members of this structure serve the same purpose as the parameters of [DrawInstanced](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-drawinstanced).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)