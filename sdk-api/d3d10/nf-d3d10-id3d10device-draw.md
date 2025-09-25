# ID3D10Device::Draw

## Description

Draw non-indexed, non-instanced primitives.

## Parameters

### `VertexCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of vertices to draw.

### `StartVertexLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first vertex, which is usually an offset in a vertex buffer; it could also be used as the first vertex id generated for a shader parameter marked with the **SV_TargetId** [system-value semantic](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics).

## Remarks

A [draw API](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) submits work to the rendering pipeline.

The vertex data for a draw call normally comes from a vertex buffer that is bound to the pipeline. However, you could also provide the vertex data from a shader that has vertex data marked with the **SV_VertexId** [system-value semantic](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)