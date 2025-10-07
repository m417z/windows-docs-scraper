# D3DX10\_IMAGE\_INFO structure

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

**ArraySize**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the texture array. *ArraySize* will be 1 for a single image.

**MipLevels**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mipmap levels in original image.

**MiscFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Miscellaneous resource properties (see [**D3D10\_RESOURCE\_MISC\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_resource_misc_flag)).

**Format**

Type: **[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A value from the [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumerated type that most closely describes the data in the original image.

**ResourceDimension**

Type: **[**D3D10\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_resource_dimension)**

Represents the type of the texture stored in the file. See [**D3D10\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/D3D10/ne-d3d10-d3d10_resource_dimension).

**ImageFileFormat**

Type: **[**D3DX10\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-file-format)**

Represents the format of the image file. See [**D3DX10\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-file-format).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

