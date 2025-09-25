# IDirect3DCubeTexture9::GetLevelDesc

## Description

Retrieves a description of one face of the specified cube texture level.

## Parameters

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a level of a mipmapped cube texture.

### `pDesc` [out]

Type: **[D3DSURFACE_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsurface-desc)***

Pointer to a [D3DSURFACE_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsurface-desc) structure, describing one face of the specified cube texture level.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be: D3DERR_INVALIDCALL.

## Remarks

The [D3DSURFACE_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsurface-desc) structure contains Width and Height members, which describe the size of one face in the cube. To get the size of the entire cube, multiply six (the number of cube faces) by the product of Width and Height.

## See also

[IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)

[IDirect3DCubeTexture9::AddDirtyRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-adddirtyrect)

[IDirect3DCubeTexture9::LockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-lockrect)

[IDirect3DCubeTexture9::UnlockRect](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcubetexture9-unlockrect)