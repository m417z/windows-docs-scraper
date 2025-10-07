# D3DX11GetImageInfoFromMemory function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [DirectXTex](https://github.com/Microsoft/DirectXTex) library, **GetMetadataFromXXXMemory** (where XXX is WIC, DDS, or TGA; WIC doesn't support DDS and TGA; D3DX 9 supported TGA as a common art source format for games).

Get information about an image already loaded into memory.

## Parameters

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the image in memory.

*SrcDataSize* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the image in memory, in bytes.

*pPump* \[in\]

Type: **[**ID3DX11ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)\***

Optional thread pump that can be used to load the info asynchronously. Can be **NULL**. See [**ID3DX11ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump).

*pSrcInfo* \[in\]

Type: **[**D3DX11\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-info)\***

Information about the image in memory.

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

