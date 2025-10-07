# D3DXCreateCubeTextureFromFileInMemoryEx function

Creates a cube texture from a file in memory. This is a more advanced function than [**D3DXCreateCubeTextureFromFileInMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatecubetexturefromfileinmemory).

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the cube texture.

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the file in memory from which to create the cube texture. See Remarks.

*SrcDataSize* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the file in memory, in bytes.

*Size* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width (or height) in pixels. If this value is zero or D3DX\_DEFAULT, the dimensions are taken from the file.

*MipLevels* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mip levels requested. If this value is zero or D3DX\_DEFAULT, a complete mipmap chain is created.

*Usage* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

0, D3DUSAGE\_RENDERTARGET, or D3DUSAGE\_DYNAMIC. Setting this flag to D3DUSAGE\_RENDERTARGET indicates that the surface is to be used as a render target. The resource can then be passed to the *pNewRenderTarget* parameter of the [**SetRenderTarget**](https://learn.microsoft.com/windows/desktop/api) method. If D3DUSAGE\_RENDERTARGET is specified, the application should check that the device supports this operation by calling [**CheckDeviceFormat**](https://learn.microsoft.com/windows/desktop/api). For more information about using dynamic textures, see [Using Dynamic Textures](https://learn.microsoft.com/windows/win32/direct3d9/performance-optimizations).

*Format* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the requested pixel format for the cube texture. The returned texture might have a different format from that specified by *Format*. Applications should check the format of the returned texture. If [D3DFMT\_UNKNOWN](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants), the format is taken from the file. If D3DFMT\_FROM\_FILE, the format is taken exactly as it is in the file, and the call will fail if this violates device capabilities.

*Pool* \[in\]

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, describing the memory class into which the cube texture should be placed.

*Filter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER.

*MipFilter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_BOX. In addition, use bits 27-31 to specify the number of mip levels to be skipped (from the top of the mipmap chain) when a .dds texture is loaded into memory; this allows you to skip up to 32 levels.

*ColorKey* \[in\]

Type: **[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor)**

[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) value to replace with transparent black, or 0 to disable the colorkey. This is always a 32-bit ARGB color, independent of the source image format. Alpha is significant, and should usually be set to FF for opaque color keys. Thus, for opaque black, the value would be equal to 0xFF000000.

*pSrcInfo* \[in, out\]

Type: **[**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info)\***

Pointer to a [**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info) structure to be filled with a description of the data in the source image file, or **NULL**.

*pPalette* \[out\]

Type: **[**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure, representing a 256-color palette to fill in, or **NULL**. See Remarks.

*ppCubeTexture* \[out\]

Type: **[**LPDIRECT3DCUBETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)\***

Address of a pointer to an [**IDirect3DCubeTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9) interface, representing the created cube texture object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DERR\_NOTAVAILABLE, D3DERR\_OUTOFVIDEOMEMORY, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

This function supports the following file formats: .bmp, .dds, .dib, .hdr, .jpg, .pfm, .png, .ppm, and .tga. See [**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat).

Cube textures differ from other surfaces in that they are collections of surfaces. To call [**SetRenderTarget**](https://learn.microsoft.com/windows/desktop/api) with a cube texture, you must select an individual face using [**GetCubeMapSurface**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dcubetexture9-getcubemapsurface) and pass the resulting surface to **SetRenderTarget** .

This method is designed to be used for loading image files stored as RT\_RCDATA, which is an application-defined resource (raw data). Otherwise this method will fail.

For details on [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry), see the Platform SDK. Note that as of DirectX 8.0, the peFlags member of the **PALETTEENTRY** structure does not function as documented in the Platform SDK. The peFlags member is now the alpha channel for 8-bit palettized formats.

**D3DXCreateCubeTextureFromFileInMemoryEx** uses the DirectDraw surface (DDS) file format. The DirectX Texture Editor (Dxtex.exe) enables you to generate a cube map from other file formats and save it in the DDS file format. You can get Dxtex.exe and learn about it from the DirectX SDK. For info about the DirectX SDK, see [Where is the DirectX SDK?](https://learn.microsoft.com/windows/win32/directx-sdk--august-2009-).

When skipping mipmap levels while loading a .dds file, use the D3DX\_SKIP\_DDS\_MIP\_LEVELS macro to generate the MipFilter value. This macro takes the number of levels to skip and the filter type and returns the filter value, which would then be passed into the MipFilter parameter.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

