# D3DX10CreateAsyncMemoryLoader function

Create an asynchronous-memory loader.

## Parameters

*pData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the data.

*cbData* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the data.

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

