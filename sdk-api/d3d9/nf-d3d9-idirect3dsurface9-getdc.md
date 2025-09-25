# IDirect3DSurface9::GetDC

## Description

Retrieves a device context.

## Parameters

### `phdc` [out]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the device context for the surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if the argument is invalid.

## Remarks

The following restrictions apply.

* **IDirect3DSurface9::GetDC** is valid on the following formats only: D3DFMT_R5G6B5, D3DFMT_X1R5G5B5, D3DFMT_R8G8B8, and D3DFMT_X8R8G8B8. Formats that contain Alpha are not supported because the GDI implementations don't have a well-defined behavior on the alpha channel. For more information about formats, see [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat).
* Only one device context per surface can be returned at a time.
* **IDirect3DSurface9::GetDC** will fail if the surface is already locked. If the surface is a member of a mipmap or cubemap, **IDirect3DSurface9::GetDC** fails if any other mipmap or cubemap member is locked.
* **IDirect3DSurface9::GetDC** fails on render targets unless they were created lockable (or, in the case of back buffers, with the D3DPRESENTFLAG_LOCKABLE_BACKBUFFER flag).
* For surfaces not created with [IDirect3DDevice9::CreateOffscreenPlainSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createoffscreenplainsurface), **IDirect3DSurface9::GetDC** will fail on default pool (D3DPOOL_DEFAULT) surfaces unless they are dynamic (D3DUSAGE_DYNAMIC) or are lockable render targets.
* **IDirect3DSurface9::GetDC** will fail on D3DPOOL_SCRATCH surfaces.

When a device context is outstanding on a surface, the application may not call these methods:

|  |  |
| --- | --- |
| IDirect3DCubeTexture9 | [IDirect3DCubeTexture9::LockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-lockrect) |
| IDirect3DDevice9 | [IDirect3DDevice9::ColorFill](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-colorfill) |
|  | [IDirect3DDevice9::StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect) |
|  | [IDirect3DDevice9::UpdateSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatesurface) |
|  | [IDirect3DDevice9::UpdateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-updatetexture) |
| IDirect3DSurface9 | [IDirect3DSurface9::LockRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-lockrect) |
| IDirect3DSwapChain9 | [IDirect3DSwapChain9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dswapchain9-present) * |
| IDirect3DTexture9 | [IDirect3DTexture9::LockRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dtexture9-lockrect) |

* (on a swap chain that contains the surface)

**IDirect3DSurface9::GetDC** causes an implicit lock; do not retain the device context for later use. Call [IDirect3DSurface9::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-releasedc) to release it.

It is valid to call **IDirect3DSurface9::GetDC**/[IDirect3DSurface9::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-releasedc) on levels of a mipmap or cubemap, however, these calls will be slow to all miplevels except the topmost level, and GDI operations to these miplevels will not be accelerated.

The hdc provides access to Win32 and GDI functionality.

## See also

[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)

[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)

[D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage)

[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)

[IDirect3DSurface9::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-releasedc)