# IDirect3DCubeTexture9::GetCubeMapSurface

## Description

Retrieves a cube texture map surface.

## Parameters

### `FaceType` [in]

Type: **[D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces)**

Member of the [D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces) enumerated type, identifying a cube map face.

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a level of a mipmapped cube texture.

### `ppCubeMapSurface` [out]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the returned cube texture map surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## Remarks

Calling this method will increase the internal reference count on the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using this **IDirect3DSurface9** interface results in a memory leak.

## See also

[IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)