# IDirect3DTexture9::GetLevelDesc

## Description

Retrieves a level description of a texture resource.

## Parameters

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies a level of the texture resource. This method returns a surface description for the level specified by this parameter.

### `pDesc` [out]

Type: **[D3DSURFACE_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsurface-desc)***

Pointer to a [D3DSURFACE_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsurface-desc) structure, describing the returned level.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if one of the arguments is invalid.

## See also

[IDirect3DTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)