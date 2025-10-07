# D3DX11PreprocessShaderFromResource function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [**D3DPreprocess**](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dpreprocess) API.

Create a shader from a resource without compiling it.

## Parameters

*hModule* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the resource module containing the shader. HMODULE can be obtained with [GetModuleHandle Function](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

*pResourceName* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the resource in side hModule containing the shader. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the data type resolves to LPCSTR.

*pSrcFileName* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional. Effect file name, which is used for error messages only. Can be **NULL**.

*pDefines* \[in\]

Type: **const D3D11\_SHADER\_MACRO\***

A NULL-terminated array of shader macros; set this to **NULL** to specify no macros.

*pInclude* \[in\]

Type: **[**LPD3D10INCLUDE**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173775(v=vs.85))**

A pointer to an include interface; set this to **NULL** to specify there is no include file.

*pPump* \[in\]

Type: **[**ID3DX11ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)\***

A pointer to a thread pump interface (see [**ID3DX11ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)). Use **NULL** to specify that this function should not return until it is completed.

*ppShaderText* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)\*\***

A pointer to memory that contains the uncompiled shader.

*ppErrorMsgs* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)\*\***

The address of a pointer to memory that contains effect-creation errors, if any occurred.

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX11async.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

