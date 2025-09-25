# D2D1_ANTIALIAS_MODE enumeration

## Description

Specifies how the edges of nontext primitives are rendered.

## Constants

### `D2D1_ANTIALIAS_MODE_PER_PRIMITIVE:0`

Edges are antialiased using the Direct2D per-primitive method of high-quality antialiasing.

### `D2D1_ANTIALIAS_MODE_ALIASED:1`

Objects are aliased in most cases. Objects are antialiased only when they are drawn to a render target created by the [CreateDxgiSurfaceRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-createdxgisurfacerendertarget(idxgisurface_constd2d1_render_target_properties__id2d1rendertarget)) method and Direct3D multisampling has been enabled on the backing DirectX Graphics Infrastructure (DXGI) surface.

### `D2D1_ANTIALIAS_MODE_FORCE_DWORD:0xffffffff`