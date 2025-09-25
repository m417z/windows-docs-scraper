# IDirect3DDevice9::SetDepthStencilSurface

## Description

Sets the depth stencil surface.

## Parameters

### `pNewZStencil` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface representing the depth stencil surface. Setting this to **NULL** disables the depth stencil operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.
If pZStencilSurface is other than **NULL**, the return value is D3DERR_INVALIDCALL when the stencil surface is invalid.

## Remarks

Restrictions for using this method include the following:

* The multisample type must be the same for the render target and the depth stencil surface.
* The formats must be compatible for the render target and the depth stencil surface. See [IDirect3D9::CheckDepthStencilMatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdepthstencilmatch).
* The size of the depth stencil surface must be greater than or equal to the size of the render target.

These restrictions are validated only when using the debug runtime when any of the [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)Draw methods are called.

Cube textures differ from other surfaces in that they are collections of surfaces. To call **IDirect3DDevice9::SetDepthStencilSurface** with a cube texture, you must select an individual face using [IDirect3DCubeTexture9::GetCubeMapSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-getcubemapsurface) and pass the resulting surface to **IDirect3DDevice9::SetDepthStencilSurface**.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetDepthStencilSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getdepthstencilsurface)