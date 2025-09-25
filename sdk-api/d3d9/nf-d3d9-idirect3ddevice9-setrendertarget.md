# IDirect3DDevice9::SetRenderTarget

## Description

Sets a new color buffer for the device.

## Parameters

### `RenderTargetIndex` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the render target. See Remarks.

### `pRenderTarget` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to a new color buffer. If **NULL**, the color buffer for the corresponding RenderTargetIndex is disabled. Devices always must be associated with a color buffer.
The new render-target surface must have at least D3DUSAGE_RENDERTARGET specified.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.
This method will return D3DERR_INVALIDCALL if either:

* pRenderTarget = **NULL** and RenderTargetIndex = 0
* pRenderTarget is != **NULL** and the render target is invalid.

## Remarks

The device can support multiple render targets. The number of render targets supported by a device is contained in the NumSimultaneousRTs member of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9). See [Multiple Render Targets (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/multiple-render-targets).

Setting a new render target will cause the viewport (see [Viewports and Clipping (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/viewports-and-clipping)) to be set to the full size of the new render target.

Some hardware tests the compatibility of the depth stencil buffer with the color buffer. If this is done, it is only done in a debug build.

Restrictions for using this method include the following:

* The multisample type must be the same for the render target and the depth stencil surface.
* The formats must be compatible for the render target and the depth stencil surface. See [IDirect3D9::CheckDepthStencilMatch](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdepthstencilmatch).
* The size of the depth stencil surface must be greater than or equal to the size of the render target.

These restrictions are validated only when using the debug runtime when any of the [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)Draw methods are called.

Cube textures differ from other surfaces in that they are collections of surfaces. To call **IDirect3DDevice9::SetRenderTarget** with a cube texture, you must select an individual face using [IDirect3DCubeTexture9::GetCubeMapSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-getcubemapsurface) and pass the resulting surface to **IDirect3DDevice9::SetRenderTarget**.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)