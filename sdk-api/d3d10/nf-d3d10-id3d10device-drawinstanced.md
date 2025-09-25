# ID3D10Device::DrawInstanced

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

Index of the first instance.

## Remarks

A [draw API](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) submits work to the rendering pipeline.

Instancing may extend performance by reusing the same geometry to draw multiple objects in a scene. One example of instancing could be to draw the same object with different positions and colors. For an example of instancing, see the [Instancing10 Sample](https://msdn.microsoft.com/library/Ee416415(v=VS.85).aspx).

The vertex data for an instanced draw call normally comes from a vertex buffer that is bound to the pipeline. However, you could also provide the vertex data from a shader that has instanced data identified with a [system-value semantic](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) (SV_InstanceID).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)