# ID3D10Device::DrawIndexed

## Description

Draw indexed, non-instanced primitives.

## Parameters

### `IndexCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of indices to draw.

### `StartIndexLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first index to use when accessing the vertex buffer; begin at *StartIndexLocation* to index vertices from the vertex buffer.

### `BaseVertexLocation` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from the start of the vertex buffer to the first vertex.

## Remarks

A [draw API](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) submits work to the rendering pipeline.

If the sum of both indices is negative, the result of the function call is undefined.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)