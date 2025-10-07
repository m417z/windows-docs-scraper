# D3DXLoadPRTBufferFromFile function

Loads into memory a precomputed radiance transfer (PRT) buffer that was saved to disk.

## Parameters

*pFileName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the file from which to load the buffer data.

*ppBuffer* \[in, out\]

Type: **[**LPD3DXPRTBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer)\***

Address of a pointer to the output [**ID3DXPRTBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer) object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXLoadPRTBufferFromFileW. Otherwise, the function call resolves to D3DXLoadPRTBufferFromFileA.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)

