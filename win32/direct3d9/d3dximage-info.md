# D3DXIMAGE\_INFO structure

Returns a description of the original contents of an image file.

## Members

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of original image in pixels.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of original image in pixels.

**Depth**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Depth of original image in pixels.

**MipLevels**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mip levels in original image.

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

A value from the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type that most closely describes the data in the original image.

**ResourceType**

Type: **[**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype)**

Represents the type of the texture stored in the file. It is either D3DRTYPE\_TEXTURE, D3DRTYPE\_VOLUMETEXTURE, or D3DRTYPE\_CubeTexture.

**ImageFileFormat**

Type: **[**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat)**

Represents the format of the image file.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

