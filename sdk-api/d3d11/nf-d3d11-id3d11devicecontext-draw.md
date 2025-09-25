# ID3D11DeviceContext::Draw

## Description

Draw non-indexed, non-instanced primitives.

## Parameters

### `VertexCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of vertices to draw.

### `StartVertexLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first vertex, which is usually an offset in a vertex buffer.

## Remarks

**Draw** submits work to the rendering pipeline.

The vertex data for a draw call normally comes from a vertex buffer that is bound to the pipeline.

Even without any vertex buffer bound to the pipeline, you can generate your own vertex data in your vertex shader by using the [SV_VertexID](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) system-value semantic to determine the current vertex that the runtime is processing.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)