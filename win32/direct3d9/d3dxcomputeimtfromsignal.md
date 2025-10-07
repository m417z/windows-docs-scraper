# D3DXComputeIMTFromSignal function

Calculates per-triangle IMT's from a custom application-specified signal that varies over the surface of the mesh (generally at a higher frequency than vertex data). The signal is evaluated via a user-specified callback function.

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

A pointer to an input mesh (see [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)) which contains the object geometry for calculating the IMT.

*dwTextureIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based texture coordinate index that identifies which set of texture coordinates to use.

*uSignalDimension* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of components in each data point in the signal.

*fMaxUVDistance* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum distance between vertices; the algorithm continues subdividing until the distance between all vertices is less than or equal to fMaxUVDistance.

*dwOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Texture wrap options. This is a combination of one or more [**D3DXIMT FLAGS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximt-flags).

*pSignalCallback* \[in\]

Type: **[LPD3DXIMTSIGNALCALLBACK](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dximtsignalcallback)**

A pointer to a user-provided evaluator function, which will be used to compute the signal value at arbitrary U,V coordinates. The function follows the prototype of [LPD3DXIMTSIGNALCALLBACK](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dximtsignalcallback).

*pUserData* \[in\]

Type: **VOID\***

A pointer to a user-defined value which is passed to the signal callback function. Typically used by an application to pass a pointer to a data structure that provides context information for the callback function.

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

## Remarks

This function requires that the input mesh contain a signal-to-mesh texture mapping (ie. texture coordinates). It allows the user to define a signal arbitrarily over the surface of the mesh.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[UVAtlas Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-uvatlas)

[Using UVAtlas (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/using-uvatlas)

