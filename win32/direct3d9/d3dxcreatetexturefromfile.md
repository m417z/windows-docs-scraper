# D3DXCreateTextureFromFile function

Creates a texture from a file.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the texture.

*pSrcFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the filename. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*ppTexture* \[out\]

Type: **[**LPDIRECT3DTEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)\***

Address of a pointer to an [**IDirect3DTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9) interface, representing the created texture object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_NOTAVAILABLE, D3DERR\_OUTOFVIDEOMEMORY, D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateTextureFromFileW. Otherwise, the function call resolves to D3DXCreateTextureFromFileA because ANSI strings are being used.

This function supports the following file formats: .bmp, .dds, .dib, .hdr, .jpg, .pfm, .png, .ppm, and .tga. See [**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat).

The function is equivalent to D3DXCreateTextureFromFileEx(pDevice, pSrcFile, D3DX\_DEFAULT, D3DX\_DEFAULT, D3DX\_DEFAULT, 0, D3DFMT\_UNKNOWN, D3DPOOL\_MANAGED, D3DX\_DEFAULT, D3DX\_DEFAULT, 0, **NULL**, **NULL**, ppTexture).

Mipmapped textures automatically have each level filled with the loaded texture.

When loading images into mipmapped textures, some devices are unable to go to a 1x1 image and this function will fail. If this happens, the images need to be loaded manually.

Note that a resource created with this function will be placed in the memory class denoted by D3DPOOL\_MANAGED.

Filtering is automatically applied to a texture created using this method. The filtering is equivalent to D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER in [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter).

For the best performance when using **D3DXCreateTextureFromFile**:

1. Doing image scaling and format conversion at load time can be slow. Store images in the format and resolution they will be used. If the target hardware requires power of two dimensions, create and store images using power of two dimensions.
2. Consider using DirectDraw surface (DDS) files. Because DDS files can be used to represent any Direct3D 9 texture format, they are very easy for D3DX to read. Also, they can store mipmaps, so any mipmap-generation algorithms can be used to author the images.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[**D3DXCreateTextureFromFileEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatetexturefromfileex)

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

