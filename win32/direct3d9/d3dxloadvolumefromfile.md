# D3DXLoadVolumeFromFile function

Loads a volume from a file.

## Parameters

*pDestVolume* \[in\]

Type: **[**LPDIRECT3DVOLUME9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolume9)**

Pointer to an [**IDirect3DVolume9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolume9) interface. Specifies the destination volume.

*pDestPalette* \[in\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure, the destination palette of 256 colors or **NULL**.

*pDestBox* \[in\]

Type: **const [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox)\***

Pointer to a [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox) structure. Specifies the destination box. Set this parameter to **NULL** to specify the entire volume.

*pSrcFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the filename. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*pSrcBox* \[in\]

Type: **const [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox)\***

Pointer to a [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox) structure. Specifies the source box. Set this parameter to **NULL** to specify the entire volume.

*Filter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter), controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER.

*ColorKey* \[in\]

Type: **[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor)**

[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) value to replace with transparent black, or 0 to disable the colorkey. This is always a 32-bit ARGB color, independent of the source image format. Alpha is significant and should usually be set to FF for opaque color keys. Thus, for opaque black, the value would be equal to 0xFF000000.

*pSrcInfo* \[in\]

Type: **[**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info)\***

Pointer to a [**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info) structure to be filled with a description of the data in the source image file, or **NULL**.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXLoadVolumeFromFileW. Otherwise, the function call resolves to D3DXLoadVolumeFromFileA because ANSI strings are being used.

This function handles conversion to and from compressed texture formats and supports the following file formats: .bmp, .dds, .dib, .hdr, .jpg, .pfm, .png, .ppm, and .tga. See [**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat).

Writing to a non-level-zero surface of the volume texture will not cause the dirty rectangle to be updated. If **D3DXLoadVolumeFromFile** is called and the texture was not already dirty (this is unlikely under normal usage scenarios), the application needs to explicitly call [**IDirect3DVolumeTexture9::AddDirtyBox**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvolumetexture9-adddirtybox) on the volume texture.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[**D3DXLoadVolumeFromFileInMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadvolumefromfileinmemory)

[**D3DXLoadVolumeFromMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadvolumefrommemory)

[**D3DXLoadVolumeFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadvolumefromresource)

[**D3DXLoadVolumeFromVolume**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxloadvolumefromvolume)

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

