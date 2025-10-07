# D3DXCreateTextureFromFileEx function

Creates a texture from a file. This is a more advanced function than [**D3DXCreateTextureFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatetexturefromfile).

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the texture.

*pSrcFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the filename. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*Width* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width in pixels. If this value is zero or D3DX\_DEFAULT, the dimensions are taken from the file and rounded up to a power of two. If the device supports non-power of 2 textures and [D3DX\_DEFAULT\_NONPOW2](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants) is specified, the size will not be rounded.

*Height* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height, in pixels. If this value is zero or D3DX\_DEFAULT, the dimensions are taken from the file and rounded up to a power of two. If the device supports non-power of 2 textures and [D3DX\_DEFAULT\_NONPOW2](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants) is sepcified, the size will not be rounded.

*MipLevels* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mip levels requested. If this value is zero or D3DX\_DEFAULT, a complete mipmap chain is created. If D3DX\_FROM\_FILE, the size will be taken exactly as it is in the file, and the call will fail if this violates device capabilities.

*Usage* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

0, [**D3DUSAGE\_RENDERTARGET**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage), or **D3DUSAGE\_DYNAMIC**. Setting this flag to **D3DUSAGE\_RENDERTARGET** indicates that the surface is to be used as a render target. The resource can then be passed to the *pNewRenderTarget* parameter of the [**SetRenderTarget**](https://learn.microsoft.com/windows/desktop/api) method. If either **D3DUSAGE\_RENDERTARGET** or **D3DUSAGE\_DYNAMIC** is specified, *Pool* must be set to D3DPOOL\_DEFAULT, and the application should check that the device supports this operation by calling [**CheckDeviceFormat**](https://learn.microsoft.com/windows/desktop/api). **D3DUSAGE\_DYNAMIC** indicates that the surface should be handled dynamically. See [Using Dynamic Textures](https://learn.microsoft.com/windows/win32/direct3d9/performance-optimizations).

*Format* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the requested pixel format for the texture. The returned texture might have a different format from that specified by *Format*. Applications should check the format of the returned texture. If D3DFMT\_UNKNOWN, the format is taken from the file. If D3DFMT\_FROM\_FILE, the format is taken exactly as it is in the file, and the call will fail if this violates device capabilities.

*Pool* \[in\]

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, describing the memory class into which the texture should be placed.

*Filter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) constants controlling how the image is filtered. Specifying [D3DX\_DEFAULT](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants) for this parameter is the equivalent of specifying D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER.

*MipFilter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) constants controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_BOX. In addition, use bits 27-31 to specify the number of mip levels to be skipped (from the top of the mipmap chain) when a .dds texture is loaded into memory; this allows you to skip up to 32 levels.

*ColorKey* \[in\]

Type: **[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor)**

[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) value to replace with transparent black, or 0 to disable the color key. This is always a 32-bit ARGB color, independent of the source image format. Alpha is significant and should usually be set to FF for opaque color keys. Thus, for opaque black, the value would be equal to 0xFF000000.

*pSrcInfo* \[in, out\]

Type: **[**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info)\***

Pointer to a [**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info) structure to be filled in with a description of the data in the source image file, or **NULL**.

*pPalette* \[out\]

Type: **[**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure, representing a 256-color palette to fill in, or **NULL**.

*ppTexture* \[out\]

Type: **[**LPDIRECT3DTEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)\***

Address of a pointer to an [**IDirect3DTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9) interface, representing the created texture object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DERR\_NOTAVAILABLE, D3DERR\_OUTOFVIDEOMEMORY, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateTextureFromFileExW. Otherwise, the function call resolves to D3DXCreateTextureFromFileExA because ANSI strings are being used.

Use [**D3DXCheckTextureRequirements**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxchecktexturerequirements) to determine if your device can support the texture given the current state.

This function supports the following file formats: .bmp, .dds, .dib, .hdr, .jpg, .pfm, .png, .ppm, and .tga. See [**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat).

Mipmapped textures automatically have each level filled with the loaded texture. When loading images into mipmapped textures, some devices are unable to go to a 1x1 image and this function will fail. If this happens, then the images need to be loaded manually.

For the best performance when using **D3DXCreateTextureFromFileEx**:

1. Doing image scaling and format conversion at load time can be slow. Store images in the format and resolution they will be used. If the target hardware requires power of 2 dimensions, then create and store images using power of 2 dimensions.
2. For mipmap image creation at load time, filter using [D3DX\_FILTER\_BOX](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter). A box filter is much faster than other filter types such as D3DX\_FILTER\_TRIANGLE.
3. Consider using DDS files. Since DDS files can be used to represent any Direct3D 9 texture format, they are very easy for D3DX to read. Also, they can store mipmaps, so any mipmap-generation algorithms can be used to author the images.

When skipping mipmap levels while loading a .dds file, use the D3DX\_SKIP\_DDS\_MIP\_LEVELS macro to generate the MipFilter value. This macro takes the number of levels to skip and the filter type and returns the filter value, which would then be passed into the MipFilter parameter.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[**D3DXCreateTextureFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatetexturefromfile)

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

