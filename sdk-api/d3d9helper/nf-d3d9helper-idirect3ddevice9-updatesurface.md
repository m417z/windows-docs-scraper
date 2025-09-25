# IDirect3DDevice9::UpdateSurface

## Description

Copies rectangular subsets of pixels from one surface to another.

## Parameters

### `pSourceSurface` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the source surface. This parameter must point to a different surface than pDestinationSurface.

### `pSourceRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a rectangle on the source surface. Specifying **NULL** for this parameter causes the entire surface to be copied.

### `pDestinationSurface` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the destination surface.

### `pDestPoint` [in]

Type: **const [POINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the upper left corner of the destination rectangle. Specifying **NULL** for this parameter causes the entire surface to be copied.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL.

## Remarks

This method is similar to CopyRects in DirectX 8.

This function has the following restrictions.

* The source surface must have been created with D3DPOOL_SYSTEMMEM.
* The destination surface must have been created with D3DPOOL_DEFAULT.
* Neither surface can be locked or holding an outstanding device context.
* Neither surface can be created with multisampling. The only valid flag for both surfaces is D3DMULTISAMPLE_NONE.
* The surface format cannot be a depth stencil format.
* The source and dest rects must fit within the surface.
* No stretching or shrinking is allowed (the rects must be the same size).
* The source format must match the dest format.

The following table shows the supported combinations.

|  |  | Dest formats |  |  |  |
| --- | --- | --- | --- | --- | --- |
|  |  | Texture | RT texture | RT | Off-screen plain |
| Src formats | Texture | Yes | Yes | Yes* | Yes |
|  | RT texture | No | No | No | No |
|  | RT | No | No | No | No |
|  | Off-screen plain | Yes | Yes | Yes | Yes |

* If the driver does not support the requested copy, it will be emulated using lock and copy.

If the application needs to copy data from a D3DPOOL_DEFAULT render target to a D3DPOOL_SYSTEMMEM surface, it can use [GetRenderTargetData](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getrendertargetdata).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)