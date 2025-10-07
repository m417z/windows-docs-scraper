# D3DXSaveTextureToFileInMemory function

Saves a texture to an image file.

## Parameters

*ppDestBuf* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Address of a pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) that will store the image.

*DestFormat* \[in\]

Type: **[**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat)**

[**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat) specifying the file format to use when saving. This function supports saving to all **D3DXIMAGE\_FILEFORMAT** formats except Portable Pixmap (.ppm) and Targa/Truevision Graphics Adapter (.tga).

*pSrcTexture* \[in\]

Type: **[**LPDIRECT3DBASETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)**

Pointer to [**IDirect3DBaseTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9) interface containing the image to be saved.

*pSrcPalette* \[in\]

Type: **const [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry)\***

Pointer to a [**PALETTEENTRY**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-paletteentry) structure containing a palette of 256 colors. This parameter can be **NULL**.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following: D3DERR\_INVALIDCALL.

## Remarks

This function handles conversion to and from compressed texture formats.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

[**D3DXSaveSurfaceToFileInMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsavesurfacetofileinmemory)

[**D3DXSaveVolumeToFileInMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsavevolumetofileinmemory)

