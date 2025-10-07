# D3DX10SaveTextureToFile function

Save a texture to a file.

## Parameters

*pSrcTexture* \[in\]

Type: **[**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource)\***

Pointer to the texture to be saved. See [**ID3D10Resource Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource).

*DestFormat* \[in\]

Type: **[**D3DX10\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-file-format)**

The format the texture will be saved as (see [**D3DX10\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-file-format)). D3DX10\_IFF\_DDS is the preferred format since it is the only option that supports all the formats in [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format).

*pDestFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the destination output file where the texture will be saved. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the data type resolves to LPCSTR.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues); use the return value to see if the *DestFormat* is supported.

## Remarks

**D3DX10SaveTextureToFile** writes out the extra [**DDS\_HEADER\_DXT10**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-header-dxt10) structure for the input texture only if necessary (for example, because the input texture is in standard RGB (sRGB) format). If **D3DX10SaveTextureToFile** writes out the **DDS\_HEADER\_DXT10** structure, it sets the **dwFourCC** member of the [**DDS\_PIXELFORMAT**](https://learn.microsoft.com/windows/win32/direct3ddds/dds-pixelformat) structure for the texture to **DX10** to indicate the prescense of the **DDS\_HEADER\_DXT10** extended header.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |
| Library<br> | D3DX10.lib |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

