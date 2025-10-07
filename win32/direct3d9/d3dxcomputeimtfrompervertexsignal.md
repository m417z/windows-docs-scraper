# D3DXComputeIMTFromPerVertexSignal function

Calculate per-triangle IMT's from per-vertex data. This function allows you to calculate the IMT based off of any value in a mesh (color, normal, etc).

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

A pointer to an input mesh (see [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)) which contains the object geometry for calculating the IMT.

*pfVertexSignal* \[in\]

Type: **const [**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to an array of per-vertex data from which IMT will be computed. The array size is uSignalStride \* v, where v is the number of vertices in the mesh.

*uSignalDimension* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of floats per vertex.

*uSignalStride* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of bytes per vertex in the array. This must be a multiple of sizeof(float)

*dwOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Texture wrap options. This is a combination of one or more [**D3DXIMT FLAGS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximt-flags).

*pStatusCallback*

Type: **[LPD3DXUVATLASCB](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxuvatlascb)**

A pointer to a callback function to monitor IMT computation progress.

*pUserContext*

Type: **[**LPVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a user-defined variable which is passed to the status callback function. Typically used by an application to pass a pointer to a data structure that provides context information for the callback function.

*ppIMTData* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

A pointer to the buffer (see [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)) containing the returned IMT array. This array can be provided as input to the D3DX [UVAtlas Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-uvatlas) to prioritize texture-space allocation in the texture parameterization.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK; otherwise, the value is D3DERR\_INVALIDCALL.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[UVAtlas Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-uvatlas)

[Using UVAtlas (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/using-uvatlas)

