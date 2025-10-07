# D3DX10CreateTextureFromResource function

Create a texture from another resource.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

A pointer to the device (see [**ID3D10Device Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)) that will use the resource.

*hSrcModule* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to the source resource. HMODULE can be obtained with [GetModuleHandle Function](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

*pSrcResource* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string that contains the name of the source resource. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the data type resolves to LPCSTR.

*pLoadInfo* \[in\]

Type: **[**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)\***

Optional. Identifies the characteristics of a texture (see [**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)) when the data processor is created; set this to **NULL** to read the characteristics of a texture when the texture is loaded.

*pPump* \[in\]

Type: **[**ID3DX10ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)\***

A pointer to a thread pump interface (see [**ID3DX10ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)). If **NULL** is specified, this function will behave synchronously and will not return until it is finished.

*ppTexture* \[out\]

Type: **[**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource)\*\***

The address of a pointer to the texture resource (see [**ID3D10Resource Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource)).

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

For a list of supported image formats see [**D3DX10\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-file-format).

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |
| Library<br> | D3DX10.lib |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

