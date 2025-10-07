# D3DX11GetImageInfoFromFile function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [DirectXTex](https://github.com/Microsoft/DirectXTex) library, **GetMetadataFromXXXFile** (where XXX is WIC, DDS, or TGA; WIC doesn't support DDS and TGA; D3DX 9 supported TGA as a common art source format for games).

Retrieves information about a given image file.

## Parameters

*pSrcFile* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

File name of image to retrieve information about. If UNICODE or \_UNICODE are defined, this parameter type is LPCWSTR, otherwise, the type is LPCSTR.

*pPump* \[in\]

Type: **[**ID3DX11ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)\***

Optional thread pump that can be used to load the info asynchronously. Can be **NULL**. See [**ID3DX11ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump).

*pSrcInfo* \[in\]

Type: **[**D3DX11\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-info)\***

Pointer to a [**D3DX11\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-info) to be filled with the description of the data in the source file.

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following: D3DERR\_INVALIDCALL

## Remarks

This function supports both Unicode and ANSI strings.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

