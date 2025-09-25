# IDirect3DDevice9::GetRenderTargetData

## Description

Copies the render-target data from device memory to system memory.

## Parameters

### `pRenderTarget` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) object, representing a render target.

### `pDestSurface` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) object, representing a destination surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_DRIVERINTERNALERROR, D3DERR_DEVICELOST, D3DERR_INVALIDCALL.

## Remarks

The destination surface must be either an off-screen plain surface or a level of a texture (mipmap or cube texture) created with D3DPOOL_SYSTEMMEM.

The source surface must be a regular render target or a level of a render-target texture (mipmap or cube texture) created with POOL_DEFAULT.

This method will fail if:

* The render target is multisampled.
* The source render target is a different size than the destination surface.
* The source render target and destination surface formats do not match.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)