# D3DX10SaveTextureToMemory function

Save a texture to memory.

## Parameters

*pSrcTexture* \[in\]

Type: **[**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource)\***

Pointer to the texture to be saved. See [**ID3D10Resource Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource).

*DestFormat* \[in\]

Type: **[**D3DX10\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-file-format)**

The format the texture will be saved as. See [**D3DX10\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-file-format).

*ppDestBuf* \[out\]

Type: **[**LPD3D10BLOB**](https://learn.microsoft.com/windows/desktop/api/D3DCommon/nn-d3dcommon-id3d10blob)\***

Address of a pointer to the memory containing the saved texture. See [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/desktop/api/D3DCommon/nn-d3dcommon-id3d10blob).

*Flags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Optional.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |
| Library<br> | D3DX10.lib |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

