# ID3D10Device::DrawIndexedInstanced

## Description

Draw indexed, instanced primitives.

## Parameters

### `IndexCountPerInstance` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the index buffer used in each instance.

### `InstanceCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of instances to draw.

### `StartIndexLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first index.

### `BaseVertexLocation` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first vertex. The index is signed, which allows a negative index. If the negative index plus the index value from the index buffer are less than 0, the result is undefined.

### `StartInstanceLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first instance.

## Remarks

A [draw API](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) submits work to the rendering pipeline.

Instancing may extend performance by reusing the same geometry to draw multiple objects in a scene. One example of instancing could be to draw the same object with different positions and colors. Indexing requires multiple vertex buffers: at least one for per-vertex data and a second buffer for per-instance data. For an example of instancing, see the [Instancing10 Sample](https://msdn.microsoft.com/library/Ee416415(v=VS.85).aspx).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)