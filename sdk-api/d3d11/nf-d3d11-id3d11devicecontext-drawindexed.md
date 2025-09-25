# ID3D11DeviceContext::DrawIndexed

## Description

Draw indexed, non-instanced primitives.

## Parameters

### `IndexCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of indices to draw.

### `StartIndexLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The location of the first index read by the GPU from the index buffer.

### `BaseVertexLocation` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value added to each index before reading a vertex from the vertex buffer.

## Remarks

A draw API submits work to the rendering pipeline.

If the sum of both indices is negative, the result of the function call is undefined.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)