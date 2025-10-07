# D3DXCreatePRTCompBuffer function

Creates a compressed precomputed radiance transfer (PRT) buffer from an uncompressed [**ID3DXPRTBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer) object. This function should be used with per-vertex or volume buffers.

## Parameters

*Quality* \[in\]

Type: **[**D3DXSHCOMPRESSQUALITYTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshcompressqualitytype)**

Quality of spherical harmonic (SH) compression. See [**D3DXSHCOMPRESSQUALITYTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshcompressqualitytype).

*NumClusters* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of clusters to use for compression.

*NumPCA* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of principal component analysis (PCA) basis vectors to use in each cluster.

*pCB* \[in\]

Type: **[LPD3DXSHPRTSIMCB](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxshprtsimcb)**

Optional pointer to the [LPD3DXSHPRTSIMCB](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxshprtsimcb) callback function that is used to compute the percentage of PRT compression computations completed. The callback function must be implemented to return S\_OK to keep running the compression routine. Any other value will halt compression. May be **NULL**.

*lpUserContext* \[in\]

Type: **[**LPVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Optional pointer to a user-defined value passed to the [LPD3DXSHPRTSIMCB](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxshprtsimcb) callback function. Typically used by an application to pass a pointer to a data structure that provides context information for the callback function. May be **NULL**.

*pBuffer* \[in\]

Type: **[**LPD3DXPRTBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer)**

Address of a pointer to the uncompressed [**ID3DXPRTBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtbuffer) object that will be compressed.

*ppBuffer* \[in, out\]

Type: **[**LPD3DXPRTCOMPBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtcompbuffer)\***

Address of a pointer to the output [**ID3DXPRTCompBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtcompbuffer) object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)

[**D3DXCreatePRTBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateprtbuffer)

[**D3DXCreatePRTBufferTex**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateprtbuffertex)

