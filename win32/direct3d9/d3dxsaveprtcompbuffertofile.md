# D3DXSavePRTCompBufferToFile function

Saves a compressed precomputed radiance transfer (PRT) buffer to disk.

## Parameters

*pFileName* \[in\]

Type: **[LPCSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the file to which the compressed buffer is to be saved.

*pBuffer* \[in\]

Type: **[LPD3DXPRTCOMPBUFFER](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtcompbuffer)**

Address of a pointer to the input [**ID3DXPRTCompBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtcompbuffer) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, then the return value is **D3D\_OK**. If the method fails, then the return value can be **D3DERR\_INVALIDCALL**.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, then the function call resolves to [D3DXSavePRTCompBufferToFileW](). Otherwise, the function call resolves to **D3DXSavePRTCompBufferToFileA**.

The PCA file format is a binary file in the form of a header and then two or three data blocks.

```cpp
struct PRTCompressHeader
{
    UINT NumSamples;
    UINT NumCoeffs;
    UINT NumChannels;
    UINT TexWidth;
    UINT TexHeight;
    UINT bIsTex;
    UINT NumClusters;
    UINT NumPCA;
};
```

For the case of *bIsTex* being non-zero, *NumSamples* should equal `TexWidth * TexHeight`.

The basis data block that follows the header is `NumCoeffs * NumChannels * (NumPCA + 1) * NumClusters * sizeof(float)` bytes.

Following that is the PCA weights data block, which is `NumPCA * NumSamples * sizeof(float)` bytes.

If *NumClusters* is greater than 1, then the file ends with the cluster IDs data block of `NumSamples * sizeof(UINT)` bytes.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)