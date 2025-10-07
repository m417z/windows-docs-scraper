# D3DXCreateTexture function

Creates an empty texture, adjusting the calling parameters as needed.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the texture.

*Width* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width in pixels. If this value is 0, a value of 1 is used. See Remarks.

*Height* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height in pixels. If this value is 0, a value of 1 is used. See Remarks.

*MipLevels* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mip levels requested. If this value is zero or D3DX\_DEFAULT, a complete mipmap chain is created.

*Usage* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

0, [**D3DUSAGE\_RENDERTARGET**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage), or **D3DUSAGE\_DYNAMIC**. Setting this flag to **D3DUSAGE\_RENDERTARGET** indicates that the surface is to be used as a render target by calling the [**SetRenderTarget**](https://learn.microsoft.com/windows/desktop/api) method. If either **D3DUSAGE\_RENDERTARGET** or **D3DUSAGE\_DYNAMIC** is specified, the application should check that the device supports this operation by calling [**CheckDeviceFormat**](https://learn.microsoft.com/windows/desktop/api). For more information about using dynamic textures, see [Using Dynamic Textures](https://learn.microsoft.com/windows/win32/direct3d9/performance-optimizations).

*Format* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the requested pixel format for the texture. The returned texture may be of a different format from that specified, if the device does not support the requested format. Applications should check the format of the returned texture to see if it matches the format requested.

*Pool* \[in\]

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, describing the memory class into which the texture should be placed.

*ppTexture* \[out\]

Type: **[**LPDIRECT3DTEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)\***

Address of a pointer to an [**IDirect3DTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9) interface, representing the created texture object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DERR\_NOTAVAILABLE, D3DERR\_OUTOFVIDEOMEMORY, E\_OUTOFMEMORY.

## Remarks

Internally, D3DXCreateTexture uses [**D3DXCheckTextureRequirements**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxchecktexturerequirements) to adjust the calling parameters. Therefore, calls to D3DXCreateTexture will often succeed where calls to [**CreateTexture**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createtexture) would fail.

If both Height and Width are set to [D3DX\_DEFAULT](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants), a value of 256 is used for both parameters. If either Height or Width is set to D3DX\_DEFAULT And the other parameter is set to a numeric value, the texture will be square with both the height and width equal to the numeric value.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

