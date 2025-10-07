# D3DXCreatePRTBufferTex function

Creates a precomputed radiance transfer (PRT) buffer that can be compressed or filled by a simulator. This function should be used to create per-pixel buffers.

## Parameters

*Width* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the texture, in pixels.

*Height* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the texture, in pixels.

*NumCoeffs* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of coefficients per sample location. When using spherical harmonic (SH) PRT, the number of coefficients should be Order², where Order is the order of the SH evaluation. Order must be in the range of [D3DXSH\_MINORDER](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants) to D3DXSH\_MAXORDER, inclusive. The degree of the evaluation is Order - 1.

*NumChannels* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of color channels to set in the mesh. Set to 1 to specify gray materials (R = G = B), or 3 to enable color bleeding effects.

*ppBuffer* \[in, out\]

Type: **[**LPD3DXPRTBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer)\***

Address of a pointer to the created [**ID3DXPRTBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer) object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

When the buffer is created, all values are initialized to zero.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)

[**D3DXCreatePRTBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateprtbuffer)

