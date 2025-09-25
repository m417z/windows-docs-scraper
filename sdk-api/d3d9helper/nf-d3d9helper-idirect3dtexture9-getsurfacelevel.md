# IDirect3DTexture9::GetSurfaceLevel

## Description

Retrieves the specified texture surface level.

## Parameters

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies a level of the texture resource. This method returns a surface for the level specified by this parameter. The top-level surface is denoted by 0.

### `ppSurfaceLevel` [out, retval]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the returned surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one D3DERR_INVALIDCALL.

## Remarks

Calling this method will increase the internal reference count on the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DSurface9** interface results in a memory leak.

## See also

[IDirect3DTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)