# D3DX10CreateAsyncResourceLoader function

Create an asynchronous-resource loader.

## Parameters

*hSrcModule* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Handle to the resource module. Use [GetModuleHandle Function](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) to get the handle.

*pSrcResource* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the resource in hSrcModule. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the data type resolves to LPCSTR.

*ppDataLoader* \[out\]

Type: **[**ID3DX10DataLoader**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataloader)\*\***

The address of a pointer to the asynchronous-data processor (see [**ID3DX10DataProcessor Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX10Async.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

