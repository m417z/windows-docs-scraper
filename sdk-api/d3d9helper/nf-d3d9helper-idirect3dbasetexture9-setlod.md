# IDirect3DBaseTexture9::SetLOD

## Description

Sets the most detailed level-of-detail for a managed texture.

## Parameters

### `LODNew` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Most detailed level-of-detail value to set for the mipmap chain.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A DWORD value, clamped to the maximum level-of-detail value (one less than the total number of levels). Subsequent calls to this method will return the clamped value, not the level-of-detail value that was previously set.

## Remarks

This method applies to the following interfaces, which inherit from [IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9).

* [IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)
* [IDirect3DTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)
* [IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)
* [IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9)

**SetLOD** is used for level-of-detail control of managed textures. This method returns 0 on nonmanaged textures.

**SetLOD** communicates to the Direct3D texture manager the most detailed mipmap in the chain that should be loaded into local video memory. For example, in a five-level mipmap chain, setting LODNew to 2 indicates that the texture manager should load only mipmap levels 2 through 4 into local video memory at any given time.

More specifically, if the texture was created with the dimensions of 256x256, setting the most detailed level to 0 indicates that 256 x 256 is the largest mipmap available, setting the most detailed level to 1 indicates that 128 x 128 is the largest mipmap available, and so on, up to the most detailed mip level (the smallest texture size) for the chain.

## See also

[IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)