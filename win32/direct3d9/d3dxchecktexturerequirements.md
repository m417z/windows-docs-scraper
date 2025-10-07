# D3DXCheckTextureRequirements function

Checks texture-creation parameters.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the texture.

*pWidth* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the requested width in pixels, or **NULL**. Returns the corrected size.

*pHeight* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the requested height in pixels, or **NULL**. Returns the corrected size.

*pNumMipLevels* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to number of requested mipmap levels, or **NULL**. Returns the corrected number of mipmap levels.

*Usage* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

0 or [**D3DUSAGE\_RENDERTARGET**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage). Setting this flag to D3DUSAGE\_RENDERTARGET indicates that the surface is to be used as a render target. The resource can then be passed to the pNewRenderTarget parameter of the [**SetRenderTarget**](https://learn.microsoft.com/windows/desktop/api) method. If **D3DUSAGE\_RENDERTARGET** is specified, the application should check that the device supports this operation by calling [**CheckDeviceFormat**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat).

*pFormat* \[in, out\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)\***

Pointer to a member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type. Specifies the desired pixel format, or **NULL**. Returns the corrected format.

*Pool* \[in\]

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, describing the memory class into which the texture should be placed.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DERR\_NOTAVAILABLE.

## Remarks

If parameters to this function are invalid, this function returns corrected parameters.

This function uses the following heuristics when comparing the requested requirements against available formats:

- Do not choose a format that has fewer channels.
- Avoid [FOURCC](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) And 24-bit formats unless explicitly requested.
- Try not to add new channels.
- Try not to change the number of bits per channel.
- Try to avoid converting between types of formats. For instance, avoid converting an ARGB format to a depth format.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

