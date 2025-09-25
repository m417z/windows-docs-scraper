# IDirect3DBaseTexture9::GetLevelCount

## Description

Returns the number of texture levels in a multilevel texture.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) value that indicates the number of texture levels in a multilevel texture.

## Remarks

**Warning** If you create a texture with [D3DUSAGE_AUTOGENMIPMAP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) to make that texture automatically generate sublevels, **GetLevelCount** always returns 1 for the number of levels.

This method applies to the following interfaces, which inherit from [IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9).

* [IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)
* [IDirect3DTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)
* [IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)

## See also

[IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)