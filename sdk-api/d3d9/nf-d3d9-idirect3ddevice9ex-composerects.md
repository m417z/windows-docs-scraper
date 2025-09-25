# IDirect3DDevice9Ex::ComposeRects

## Description

Copy a text string to one surface using an alphabet of glyphs on another surface. Composition is done by the GPU using bitwise operations.

## Parameters

### `pSrc` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

A pointer to a source surface (prepared by [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)) that supplies the alphabet glyphs. This surface must be created with the [D3DUSAGE_TEXTAPI](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) flag.

### `pDst` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

A pointer to the destination surface (prepared by [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)) that receives the glyph data. The surface must be part of a texture.

### `pSrcRectDescs` [in]

Type: **[IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)***

A pointer to a vertex buffer (see [IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)) containing rectangles (see [D3DCOMPOSERECTDESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcomposerectdesc)) that enclose the desired glyphs in the source surface.

### `NumRects` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of rectangles or glyphs that are used in the operation. The number applies to both the source and destination surfaces. The range is 0 to [D3DCOMPOSERECTS_MAXNUMRECTS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcomposerects-maxnumrects).

### `pDstRectDescs` [in]

Type: **[IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)***

A pointer to a vertex buffer (see [IDirect3DVertexBuffer9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)) containing rectangles (see [D3DCOMPOSERECTDESTINATION](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcomposerectdestination)) that describe the destination to which the indicated glyph from the source surface will be copied.

### `Operation` [in]

Type: **[D3DCOMPOSERECTSOP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcomposerectsop)**

Specifies how to combine the source and destination surfaces. See [D3DCOMPOSERECTSOP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcomposerectsop).

### `Xoffset` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value added to the *x* coordinates of all destination rectangles. This value can be negative, which may cause the glyph to be rejected or clipped if the result is beyond the bounds of the surface.

### `Yoffset` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value added to the *y* coordinates of all destination rectangles. This value can be negative, which may cause the glyph to be rejected or clipped if the result is beyond the bounds of the surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

## Remarks

Glyphs from a one-bit source surface are put together into another one-bit texture surface with this method. The destination surface can then be used as the source for a normal texturing operation that will filter and scale the strings of text onto some other non-monochrome surface.

This method has several constraints (which are similar to [StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect)):

* Surfaces cannot be locked.
* The source and destination surfaces cannot be the same surface.
* The source and destination surfaces must be created with the [D3DFMT_A1](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) format.
* The source surface and both vertex buffers must be created with the [D3DPOOL_DEFAULT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) flag.
* The destination surface must be created with either the [D3DPOOL_DEFAULT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) or [D3DPOOL_SYSTEMMEM](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) flags.
* The source rectangles must be within the source surface.

The method is not recorded in state blocks.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)