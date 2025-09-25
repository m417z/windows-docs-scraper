# IDirect3DDevice9::CreateTexture

## Description

Creates a texture resource.

## Parameters

### `Width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the top-level of the texture, in pixels. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's
pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0, 1 will be taken instead.

### `Height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Height of the top-level of the texture, in pixels. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's
pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0, 1 will be taken instead.

### `Levels` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of levels in the texture. If this is zero, Direct3D will generate all texture sublevels down to 1 by 1 pixels for hardware that supports
mipmapped textures. Call [IDirect3DBaseTexture9::GetLevelCount](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-getlevelcount) to see the number of levels generated.

### `Usage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Usage can be 0, which indicates no usage value. However, if usage is desired, use a combination of one or more [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) constants. It is
good practice to match the usage parameter with the behavior flags in [IDirect3D9::CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice).

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, describing the format of all levels in the texture.

### `Pool` [in]

Type: **[D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool)**

Member of the [D3DPOOL](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpool) enumerated type, describing the memory class into which the texture should be placed.

### `ppTexture` [out, retval]

Type: **[IDirect3DTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)****

Pointer to an [IDirect3DTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dtexture9) interface, representing the created texture resource.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Reserved. Set this parameter to **NULL**. This parameter can be used in Direct3D 9 for Windows Vista to
[share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL,
D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

An application can discover support for [Automatic Generation of Mipmaps (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/automatic-generation-of-mipmaps) in a particular format by calling
[IDirect3D9::CheckDeviceFormat](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat) with D3DUSAGE_AUTOGENMIPMAP. If **IDirect3D9::CheckDeviceFormat** returns D3DOK_NOAUTOGEN,
**IDirect3DDevice9::CreateTexture** will succeed but it will return a one-level texture.

In Windows Vista CreateTexture can create a texture from a system memory pointer allowing the application more flexibility over the use, allocation and deletion of
the system memory. For example, an application could pass a GDI system memory bitmap pointer and get a Direct3D texture interface around it. Using a system memory
pointer with CreateTexture has the following restrictions.

* The pitch of the texture must be equal to the width multiplied by the number of bytes per pixel.
* Only textures with a single mipmap level are supported. The *Levels* argument must be 1.
* The *Pool* argument must be D3DPOOL_SYSTEMMEM.
* The *pSharedHandle* argument must be a valid pointer to a buffer that can hold the system memory point; **pSharedHandle* must
  be a valid pointer to system memory with a size in bytes of texture width * texture height * bytes per pixel of the texture format.

## See also

[D3DXCreateTexture](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatetexture)

[D3DXCreateTextureFromFile](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatetexturefromfile)

[D3DXCreateTextureFromFileEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatetexturefromfileex)

[D3DXCreateTextureFromFileInMemory](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatetexturefromfileinmemory)

[D3DXCreateTextureFromFileInMemoryEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatetexturefromfileinmemoryex)

[D3DXCreateTextureFromResource](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatetexturefromresource)

[D3DXCreateTextureFromResourceEx](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxcreatetexturefromresourceex)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)