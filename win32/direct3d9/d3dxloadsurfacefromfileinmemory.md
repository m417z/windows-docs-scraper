# D3DXLoadSurfaceFromFileInMemory function

Loads a surface from a file in memory.

## Parameters

*pDestSurface* \[in\]

Type: **[**LPDIRECT3DSURFACE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)**

Pointer to an [**IDirect3DSurface9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. Specifies the destination surface, which receives the image.

*pDestPalette* \[in\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure, the destination palette of 256 colors or **NULL**.

*pDestRect* \[in\]

Type: **const [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)\***

Pointer to a [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure. Specifies the destination rectangle. Set this parameter to **NULL** to specify the entire surface.

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the file in memory from which to load the surface.

*SrcData* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the file in memory, in bytes.

*pSrcRect* \[in\]

Type: **const [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)\***

Pointer to a [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure. Specifies the source rectangle. Set this parameter to **NULL** to specify the entire image.

*Filter* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A combination of one or more [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter) controlling how the image is filtered. Specifying D3DX\_DEFAULT for this parameter is the equivalent of specifying D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER.

*ColorKey* \[in\]

Type: **[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor)**

[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) value to replace with transparent black, or 0 to disable the colorkey. This is always a 32-bit ARGB color, independent of the source image format. Alpha is significant and should usually be set to FF for opaque color keys. Thus, for opaque black, the value would be equal to 0xFF000000.

*pSrcInfo* \[in, out\]

Type: **[**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info)\***

Pointer to a [**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info) structure to be filled with a description of the data in the source image file or **NULL**.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA.

## Remarks

This function handles conversion to and from compressed texture formats and supports the following file formats: .bmp, .dds, .dib, .hdr, .jpg, .pfm, .png, .ppm, and .tga. See [**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat).

Writing to a non-level-zero surface will not cause the dirty rectangle to be updated. If **D3DXLoadSurfaceFromFileInMemory** is called and the surface was not already dirty (this is unlikely under normal usage scenarios), the application needs to explicitly call [**AddDirtyRect**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dtexture9-adddirtyrect) on the surface.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

