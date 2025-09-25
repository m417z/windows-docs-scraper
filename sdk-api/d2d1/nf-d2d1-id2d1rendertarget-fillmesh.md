# ID2D1RenderTarget::FillMesh

## Description

Paints the interior of the specified mesh.

## Parameters

### `mesh` [in]

Type: **[ID2D1Mesh](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1mesh)***

The mesh to paint.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)***

The brush used to paint the mesh.

## Remarks

The current antialias mode of the render target must be [D2D1_ANTIALIAS_MODE_ALIASED](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_antialias_mode) when **FillMesh** is called. To change the render target's antialias mode, use the [SetAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-setantialiasmode) method.

**FillMesh** does not expect a particular winding order for the triangles in the [ID2D1Mesh](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1mesh); both clockwise and counter-clockwise will work.

This method doesn't return an error code if it fails. To determine whether a drawing operation (such as **FillMesh**) failed, check the result returned by the [ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [ID2D1RenderTarget::Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) methods.

## See also

[D2D1_ANTIALIAS_MODE_ALIASED](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_antialias_mode)

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[SetAntialiasMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-setantialiasmode)