# D3DXSaveVolumeToFile function

Saves a volume to a file on disk.

## Parameters

*pDestFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the file name of the destination image. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*DestFormat* \[in\]

Type: **[**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat)**

[**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat) specifying the file format to use when saving. This function supports saving to all **D3DXIMAGE\_FILEFORMAT** formats except Portable Pixmap (.ppm) and Targa/Truevision Graphics Adapter (.tga).

*pSrcVolume* \[in\]

Type: **[**LPDIRECT3DVOLUME9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolume9)**

Pointer to [**IDirect3DVolume9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolume9) interface containing the image to be saved.

*pSrcPalette* \[in\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure containing a palette of 256 colors. This parameter can be **NULL**.

*pSrcBox* \[in\]

Type: **const [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox)\***

Pointer to a [**D3DBOX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbox) structure. Specifies the source box. Set this parameter to **NULL** to specify the entire volume.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following: D3DERR\_INVALIDCALL

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXSaveVolumeToFileW. Otherwise, the function call resolves to >D3DXSaveVolumeToFileA because ANSI strings are being used.

This function handles conversion to and from compressed texture formats.

If the volume is nondynamic (because of a usage parameter set to 0 at the creation) and located in video memory (the memory pool set to D3DPOOL\_DEFAULT), [**D3DXSaveTextureToFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsavetexturetofile) will fail because D3DX cannot lock nondynamic volumes located in video memory.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

[**D3DXSaveSurfaceToFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsavesurfacetofile)

[**D3DXSaveTextureToFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsavetexturetofile)

[**D3DXSaveVolumeToFileInMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsavevolumetofileinmemory)

