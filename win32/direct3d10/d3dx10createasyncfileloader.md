# D3DX10CreateAsyncFileLoader function

Create an asynchronous-file loader.

## Parameters

*pFileName* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The name of the file to load. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the data type resolves to LPCSTR.

*ppDataLoader* \[out\]

Type: **[**ID3DX10DataLoader**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataloader)\*\***

Address of a pointer to the asynchronous-data loader (see [**ID3DX10DataLoader Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataloader)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX10Async.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

