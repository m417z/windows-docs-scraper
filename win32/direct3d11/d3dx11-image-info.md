# D3DX11\_IMAGE\_INFO structure

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

Optionally provide information to texture loader APIs to control how textures get loaded. A value of D3DX11\_DEFAULT for any of these parameters will cause D3DX to automatically use the value from the source file.

## Members

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The target width of the texture. If the actual width of the texture is larger or smaller than this value then the texture will be scaled up or down to fit this target width.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The target height of the texture. If the actual height of the texture is larger or smaller than this value then the texture will be scaled up or down to fit this target height.

**Depth**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The depth of the texture. This only applies to volume textures.

**ArraySize**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements in the array.

**MipLevels**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels in the texture. See the remarks in [**D3D11\_TEX1D\_SRV**](https://learn.microsoft.com/windows/desktop/api/D3D11/ns-d3d11-d3d11_tex1d_srv). Using 0 or D3DX11\_DEFAULT will cause a full mipmap chain to be created.

**MiscFlags**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Miscellaneous resource properties specified with a [**D3D11\_RESOURCE\_MISC\_FLAG**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_resource_misc_flag) flag.

**Format**

Type: **[**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration specifying the format the texture will be in after it is loaded.

**ResourceDimension**

Type: **[**D3D11\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_resource_dimension)**

A [**D3D11\_RESOURCE\_DIMENSION**](https://learn.microsoft.com/windows/desktop/api/D3D11/ne-d3d11-d3d11_resource_dimension) value, which identifies the type of resource.

**ImageFileFormat**

Type: **[**D3DX11\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-file-format)**

A [**D3DX11\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-file-format) value, which identifies the image format.

## Remarks

This structure is used by methods such as: [**D3DX11GetImageInfoFromFile**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11getimageinfofromfile), [**D3DX11GetImageInfoFromMemory**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11getimageinfofrommemory), or [**D3DX11GetImageInfoFromResource**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11getimageinfofromresource).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-structures)

