# IDirect3DCubeTexture9::UnlockRect

## Description

Unlocks a rectangle on a cube texture resource.

## Parameters

### `FaceType` [in]

Type: **[D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces)**

Member of the [D3DCUBEMAP_FACES](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcubemap-faces) enumerated type, identifying a cube map face.

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a level of a mipmapped cube texture.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## See also

[IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)

[IDirect3DCubeTexture9::AddDirtyRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-adddirtyrect)

[IDirect3DCubeTexture9::LockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-lockrect)