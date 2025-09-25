# IDirect3DBaseTexture9::GenerateMipSubLevels

## Description

Generate mipmap sublevels.

## Remarks

An application can generate mipmap sublevels at any time by calling **GenerateMipSubLevels**. To have mipmap sublevels generated automatically at texture creation time (see [Automatic Generation of Mipmaps (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/automatic-generation-of-mipmaps)), specify D3DUSAGE_AUTOGENMIPMAP during [CreateTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createtexture), [CreateCubeTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createcubetexture), and [CreateVolumeTexture](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createvolumetexture). For more information about usage constants, see [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage).

## See also

[GetAutoGenFilterType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-getautogenfiltertype)

[IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)

[SetAutoGenFilterType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-setautogenfiltertype)