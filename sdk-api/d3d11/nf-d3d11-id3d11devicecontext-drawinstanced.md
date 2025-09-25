# ID3D11DeviceContext::DrawInstanced

## Description

Draw non-indexed, instanced primitives.

## Parameters

### `VertexCountPerInstance` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of vertices to draw.

### `InstanceCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of instances to draw.

### `StartVertexLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first vertex.

### `StartInstanceLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value added to each index before reading per-instance data from a vertex buffer.

## Remarks

A draw API submits work to the rendering pipeline.

Instancing may extend performance by reusing the same geometry to draw multiple objects in a scene. One example of instancing could be
to draw the same object with different positions and colors.

The vertex data for an instanced draw call normally comes from a vertex buffer that is bound to the pipeline.
However, you could also provide the vertex data from a shader that has instanced data identified with a system-value semantic (SV_InstanceID).

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)