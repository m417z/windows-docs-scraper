# ID3D11DeviceContext::DrawIndexedInstanced

## Description

Draw indexed, instanced primitives.

## Parameters

### `IndexCountPerInstance` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Number of indices read from the index buffer for each instance.

### `InstanceCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Number of instances to draw.

### `StartIndexLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The location of the first index read by the GPU from the index buffer.

### `BaseVertexLocation` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A value added to each index before reading a vertex from the vertex buffer.

### `StartInstanceLocation` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A value added to each index before reading per-instance data from a vertex buffer.

## Remarks

A draw API submits work to the rendering pipeline.

Instancing may extend performance by reusing the same geometry to draw multiple objects in a scene. One example of instancing could be to draw the same object with different positions and colors. Instancing requires multiple vertex buffers: at least one for per-vertex data and a second buffer for per-instance data.

The second buffer is needed only if the input layout that you use has elements that use [D3D11_INPUT_PER_INSTANCE_DATA](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_input_classification) as the input element classification buffer for per-instance data.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)