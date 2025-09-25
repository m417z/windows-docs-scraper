# ID2D1CommandSink::FillMesh

## Description

Indicates a mesh to be filled by the command sink.

## Parameters

### `mesh` [in]

Type: **[ID2D1Mesh](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1mesh)***

The mesh object to be filled.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush with which to fill the mesh.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::FillMesh](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-fillmesh)