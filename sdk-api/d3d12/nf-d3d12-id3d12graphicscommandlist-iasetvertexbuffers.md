# ID3D12GraphicsCommandList::IASetVertexBuffers

## Description

Sets a CPU descriptor handle for the vertex buffers.

## Parameters

### `StartSlot` [in]

Type: **UINT**

Index into the device's zero-based array to begin setting vertex buffers.

### `NumViews` [in]

Type: **UINT**

The number of views in the *pViews* array.

### `pViews` [in, optional]

Type: **const [D3D12_VERTEX_BUFFER_VIEW](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_vertex_buffer_view)***

Specifies the vertex buffer views in an array of [D3D12_VERTEX_BUFFER_VIEW](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_vertex_buffer_view) structures.

## See also

[IASetIndexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-iasetindexbuffer)

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)