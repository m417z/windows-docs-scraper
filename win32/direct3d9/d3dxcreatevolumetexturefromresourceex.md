# D3DXCreateVolumeTextureFromResourceEx function

Creates a volume texture from a resource specified by a string. This is a more advanced function than [**D3DXCreateVolumeTextureFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromresource).

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the texture.

*hSrcModule* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Handle to the module where the resource is located, or **NULL** for module associated with the image the operating system used to create the current process.

*pSrcResource* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the resource name. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*Width* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width in pixels. If this value is zero or D3DX\_DEFAULT, the dimensions are taken from the file. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9).

*Height* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height, in pixels. If this value is zero or D3DX\_DEFAULT, the dimensions are taken from the file. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9).

*Depth* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Depth, in pixels. If this value is zero or D3DX\_DEFAULT, the dimensions are taken from the file. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9).

*MipLevels* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mip levels requested. If this value is zero or D3DX\_DEFAULT, a complete mipmap chain is created.

*Usage* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

0, D3DUSAGE\_RENDERTARGET, or D3DUSAGE\_DYNAMIC. Setting this flag to D3DUSAGE\_RENDERTARGET indicates that the surface is to be used as a render target. The resource can then be passed to the *pNewRenderTarget* parameter of the [**SetRenderTarget**](https://learn.microsoft.com/windows/desktop/api) method. If either D3DUSAGE\_RENDERTARGET or D3DUSAGE\_DYNAMIC is specified, *Pool* must be set to D3DPOOL\_DEFAULT, and the application should check that the device supports this operation by calling [**CheckDeviceFormat**](https://learn.microsoft.com/windows/desktop/api). D3DUSAGE\_DYNAMIC indicates that the surface should be handled dynamically. For more information about using dynamic textures, see [Using Dynamic Textures](https://learn.microsoft.com/windows/win32/direct3d9/performance-optimizations).

*Format* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the requested pixel format for the texture. The returned texture might have a different format from that specified by *Format*. Applications should check the format of the returned texture. If [D3DFMT\_UNKNOWN](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants), the format is taken from the file. If D3DFMT\_FROM\_FILE, the format is taken exactly as it is in the file, and the call will fail if this violates device capabilities.

*Pool* \[in\]

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, describing the memory class into which the texture should be placed.

*Filter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER.

*MipFilter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_BOX.

*ColorKey* \[in\]

Type: **[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor)**

[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) value to replace with transparent black, or 0 to disable the colorkey. This is always a 32-bit ARGB color, independent of the source image format. Alpha is significant and should usually be set to FF for opaque color keys. Thus, for opaque black, the value would be equal to 0xFF000000.

*pSrcInfo* \[in, out\]

Type: **[**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info)\***

Pointer to a [**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info) structure to be filled in with a description of the data in the source image file, or **NULL**.

*pPalette* \[out\]

Type: **[**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure, representing a 256-color palette to fill in, or **NULL**.

*ppVolumeTexture* \[out\]

Type: **[**LPDIRECT3DVOLUMETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)\***

Address of a pointer to an [**IDirect3DVolumeTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9) interface, representing the created texture object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_NOTAVAILABLE, D3DERR\_OUTOFVIDEOMEMORY, D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateVolumeTextureFromResourceExW. Otherwise, the function call resolves to D3DXCreateVolumeTextureFromResourceExA because ANSI strings are being used.

The resource being loaded must be an application-defined resource (RT\_RCDATA).

This function supports the following file formats: .bmp, .dds, .dib, .hdr, .jpg, .pfm, .png, .ppm, and .tga. See [**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat).

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[**D3DXCreateVolumeTextureFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfile)

[**D3DXCreateVolumeTextureFromFileEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfileex)

[**D3DXCreateVolumeTextureFromFileInMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfileinmemory)

[**D3DXCreateVolumeTextureFromFileInMemoryEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfileinmemoryex)

[**D3DXCreateVolumeTextureFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromresource)

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

