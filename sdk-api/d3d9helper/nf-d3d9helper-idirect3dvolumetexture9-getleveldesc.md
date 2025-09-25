# IDirect3DVolumeTexture9::GetLevelDesc

## Description

Retrieves a level description of a volume texture resource.

## Parameters

### `Level` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifies a level of the volume texture resource. This method returns a volume description for the level specified by this parameter.

### `pDesc` [out]

Type: **[D3DVOLUME_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvolume-desc)***

Pointer to a [D3DVOLUME_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvolume-desc) structure, describing the returned volume texture level.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if one or more of the arguments are invalid.

## See also

[IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)