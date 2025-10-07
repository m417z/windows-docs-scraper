# D3DXCreateCubeTexture function

Creates an empty cube texture, adjusting the calling parameters as needed.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the texture.

*Size* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width and height of the cube texture, in pixels. For example, if the cube texture is an 8-pixel by 8-pixel cube, the value for this parameter should be 8.

*MipLevels* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mip levels requested. If this value is zero or D3DX\_DEFAULT, a complete mipmap chain is created.

*Usage* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

0, D3DUSAGE\_RENDERTARGET, or D3DUSAGE\_DYNAMIC. Setting this flag to D3DUSAGE\_RENDERTARGET indicates that the surface is to be used as a render target. The resource can then be passed to the *pNewRenderTarget* parameter of the [**SetRenderTarget**](https://learn.microsoft.com/windows/desktop/api) method. If D3DUSAGE\_RENDERTARGET is specified, the application should check that the device supports this operation by calling [**CheckDeviceFormat**](https://learn.microsoft.com/windows/desktop/api). For more information about using dynamic textures, see [Using Dynamic Textures](https://learn.microsoft.com/windows/win32/direct3d9/performance-optimizations).

*Format* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the requested pixel format for the cube texture. The returned cube texture might have a different format from that specified by *Format*. Applications should check the format of the returned cube texture.

*Pool* \[in\]

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, describing the memory class into which the cube texture should be placed.

*ppCubeTexture* \[out\]

Type: **[**LPDIRECT3DCUBETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)\***

Address of a pointer to an [**IDirect3DCubeTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9) interface, representing the created cube texture object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DERR\_NOTAVAILABLE, D3DERR\_OUTOFVIDEOMEMORY, E\_OUTOFMEMORY.

## Remarks

Cube textures differ from other surfaces in that they are collections of surfaces.

Internally, D3DXCreateCubeTexture uses [**D3DXCheckCubeTextureRequirements**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcheckcubetexturerequirements) to adjust the calling parameters. Therefore, calls to D3DXCreateCubeTexture will often succeed where calls to [**CreateCubeTexture**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createcubetexture) would fail.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

