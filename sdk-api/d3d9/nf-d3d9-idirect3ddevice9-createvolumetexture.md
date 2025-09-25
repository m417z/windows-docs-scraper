# IDirect3DDevice9::CreateVolumeTexture

## Description

Creates a volume texture resource.

## Parameters

### `Width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the top-level of the volume texture, in pixels. This value must be a power of two if the D3DPTEXTURECAPS_VOLUMEMAP_POW2 member of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) is set. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by two results in 0 (zero), 1 will be taken instead. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in **D3DCAPS9**.

### `Height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Height of the top-level of the volume texture, in pixels. This value must be a power of two if the D3DPTEXTURECAPS_VOLUMEMAP_POW2 member of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) is set. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0 (zero), 1 will be taken instead. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in **D3DCAPS9**.

### `Depth` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Depth of the top-level of the volume texture, in pixels. This value must be a power of two if the D3DPTEXTURECAPS_VOLUMEMAP_POW2 member of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) is set. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0 (zero), 1 will be taken instead. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in **D3DCAPS9**.

### `Levels` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of levels in the texture. If this is zero, Direct3D will generate all texture sublevels down to 1x1 pixels for hardware that supports mipmapped volume textures. Call [IDirect3DBaseTexture9::GetLevelCount](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-getlevelcount) to see the number of levels generated.

### `Usage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Usage can be 0, which indicates no usage value. If usage is desired, use D3DUSAGE_DYNAMIC or D3DUSAGE_SOFTWAREPROCESSING. For more information, see [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage).

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, describing the format of all levels in the volume texture.

### `Pool` [in]

Type: **[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)**

Member of the [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) enumerated type, describing the memory class into which the volume texture should be placed.

### `ppVolumeTexture` [out, retval]

Type: **[IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)****

Address of a pointer to an [IDirect3DVolumeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9) interface, representing the created volume texture resource.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Reserved. Set this parameter to **NULL**. This parameter can be used in Direct3D 9 for Windows Vista to [share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## See also

[D3DXCreateVolumeTexture](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatevolumetexture)

[D3DXCreateVolumeTextureFromFile](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatevolumetexturefromfile)

[D3DXCreateVolumeTextureFromFileEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatevolumetexturefromfileex)

[D3DXCreateVolumeTextureFromFileInMemory](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatevolumetexturefromfileinmemory)

[D3DXCreateVolumeTextureFromFileInMemoryEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatevolumetexturefromfileinmemoryex)

[D3DXCreateVolumeTextureFromResource](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatevolumetexturefromresource)

[D3DXCreateVolumeTextureFromResourceEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatevolumetexturefromresourceex)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)