# D3DX10GetImageInfoFromResource function

Retrieves information about a given image in a resource.

## Parameters

*hSrcModule* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Module where the resource is loaded. Set this parameter to **NULL** to specify the module associated with the image that the operating system used to create the current process.

*pSrcResource* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the filename. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the data type resolves to LPCSTR. See Remarks.

*pPump* \[in\]

Type: **[**ID3DX10ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)\***

Optional thread pump that can be used to load the info asynchronously. Can be **NULL**. See [**ID3DX10ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump).

*pSrcInfo* \[in\]

Type: **[**D3DX10\_IMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-info)\***

Pointer to a D3DX10\_IMAGE\_INFO structure to be filled with the description of the data in the source file.

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following: D3DERR\_INVALIDCALL

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DX10GetImageInfoFromResourceW. Otherwise, the function call resolves to D3DX10GetImageInfoFromResourceA because ANSI strings are being used.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |
| Library<br> | D3DX10.lib |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

