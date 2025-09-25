# IDirect3DDevice9::CreateOffscreenPlainSurface

## Description

Create an off-screen surface.

## Parameters

### `Width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the surface.

### `Height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Height of the surface.

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Format of the surface. See [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat).

### `Pool` [in]

Type: **[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)**

Surface pool type. See [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool).

### `ppSurface` [out, retval]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Pointer to the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface created.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Reserved. Set this parameter to **NULL**. This parameter can be used in Direct3D 9 for Windows Vista to [share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be the following:
D3DERR_INVALIDCALL.

## Remarks

D3DPOOL_SCRATCH will return a surface that has identical characteristics to a surface created by the DirectX 8.x method CreateImageSurface.

D3DPOOL_DEFAULT is the appropriate pool for use with the [IDirect3DDevice9::StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect) and [IDirect3DDevice9::ColorFill](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-colorfill).

D3DPOOL_MANAGED is not allowed when creating an offscreen plain surface. For more information about memory pools, see [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool).

Off-screen plain surfaces are always lockable, regardless of their pool types.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)