# ID2D1RenderTarget::CreateMesh

## Description

Create a mesh that uses triangles to describe a shape.

## Parameters

### `mesh` [out]

Type: **[ID2D1Mesh](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1mesh)****

When this method returns, contains a pointer to a pointer to the new mesh.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

To populate a mesh, use its [Open](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1mesh-open) method to obtain an [ID2D1TessellationSink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1tessellationsink). To draw the mesh, use the render target's [FillMesh](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-fillmesh) method.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)