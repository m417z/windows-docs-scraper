# IDirect3DBaseTexture9::GetLOD

## Description

Returns a value clamped to the maximum level-of-detail set for a managed texture (this method is not supported for an unmanaged texture).

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A DWORD value, clamped to the maximum level-of-detail value (one less than the total number of levels). Calling **GetLOD** on an unmanaged texture is not supported and will result in a [D3DERR](https://learn.microsoft.com/windows/desktop/direct3d9/d3derr) error code being returned.

## See also

[IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)