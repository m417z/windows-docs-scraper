# IDirect3DDevice9::CreateCubeTexture

## Description

Creates a cube texture resource.

## Parameters

### `EdgeLength` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the edges of all the top-level faces of the cube texture. The pixel dimensions of subsequent levels of each face will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0 (zero), 1 will be taken instead.

### `Levels` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of levels in each face of the cube texture. If this is zero, Direct3D will generate all cube texture sublevels down to 1x1 pixels for each face for hardware that supports mipmapped cube textures. Call [IDirect3DBaseTexture9::GetLevelCount](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-getlevelcount) to see the number of levels generated.

### `Usage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Usage can be 0, which indicates no usage value. However, if usage is desired, use a combination of one or more [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) constants. It is good practice to match the usage parameter in CreateCubeTexture with the behavior flags in [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice). For more information, see Remarks.

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, describing the format of all levels in all faces of the cube texture.

### `Pool` [in]

Type: **[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)**

Member of the [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) enumerated type, describing the memory class into which the cube texture should be placed.

### `ppCubeTexture` [out, retval]

Type: **[IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)****

Address of a pointer to an [IDirect3DCubeTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9) interface, representing the created cube texture resource.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Reserved. Set this parameter to **NULL**. This parameter can be used in Direct3D 9 for Windows Vista to [share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

A mipmap (texture) is a collection of successively downsampled (mipmapped) surfaces. On the other hand, a cube texture (created by **IDirect3DDevice9::CreateCubeTexture**) is a collection of six textures (mipmaps), one for each face. All faces must be present in the cube texture. Also, a cube map surface must be the same pixel size in all three dimensions (x, y, and z).

An application can discover support for [Automatic Generation of Mipmaps (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/automatic-generation-of-mipmaps) in a particular format by calling [IDirect3D9::CheckDeviceFormat](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat) with D3DUSAGE_AUTOGENMIPMAP. If **IDirect3D9::CheckDeviceFormat** returns D3DOK_NOAUTOGEN, **IDirect3DDevice9::CreateCubeTexture** will succeed but it will return a one-level texture.

## See also

[D3DXCreateCubeTexture](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatecubetexture)

[D3DXCreateCubeTextureFromFile](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatecubetexturefromfile)

[D3DXCreateCubeTextureFromFileEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatecubetexturefromfileex)

[D3DXCreateCubeTextureFromFileInMemory](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatecubetexturefromfileinmemory)

[D3DXCreateCubeTextureFromFileInMemoryEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatecubetexturefromfileinmemoryex)

[D3DXCreateCubeTextureFromResource](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatecubetexturefromresource)

[D3DXCreateCubeTextureFromResourceEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatecubetexturefromresourceex)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)