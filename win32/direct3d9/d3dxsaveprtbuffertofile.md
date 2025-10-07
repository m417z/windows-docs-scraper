# D3DXSavePRTBufferToFile function

Saves a precomputed radiance transfer (PRT) buffer to disk.

## Parameters

*pFileName* \[in\]

Type: **[LPCSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the file to which the buffer is to be saved.

*pBuffer* \[in\]

Type: **[LPD3DXPRTBUFFER](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer)**

Address of a pointer to the input [**ID3DXPRTBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is **D3D\_OK**. If the method fails, the return value can be **D3DERR\_INVALIDCALL**.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, then the function call resolves to [D3DXSavePRTBufferToFileW](). Otherwise, the function call resolves to **D3DXSavePRTBufferToFileA**.

The PRT file format is a binary file in the form of a header and then a data block.

```cpp
struct PRTHeader
{
    UINT NumSamples;
    UINT NumCoeffs;
    UINT NumChannels;
    UINT TexWidth;
    UINT TexHeight;
    UINT bIsTex;
};
```

For the case of *bIsTex* being non-zero, *NumSamples* should equal `TexWidth * TexHeight`.

The data block that follows the header is `NumSamples * NumCoeffs * NumChannels * sizeof(float)` bytes.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)