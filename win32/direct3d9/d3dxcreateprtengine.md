# D3DXCreatePRTEngine function

Creates an [**ID3DXPRTEngine**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtengine) object that can efficiently generate precomputed radiance transfer (PRT) simulations of a 3D scene.

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an input [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) mesh object that models the 3D scene. This mesh must have an attribute table in which vertices are in a unique attribute.

*pAdjacency* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Optional pointer to an array of three DWORDs per face to be filled with adjacent face indices. The number of bytes in this array must be at least ((3 \* [**GetNumFaces**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh--getnumfaces)) \* sizeof(DWORD)). May be **NULL**.

*ExtractUVs* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If **TRUE**, textures will be used to store albedos or PRT vectors.

*pBlockerMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an optional [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) mesh object that blocks the 3D scene. May be **NULL**.

*ppEngine* \[in, out\]

Type: **[**LPD3DXPRTENGINE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtengine)**

Pointer to an output [**ID3DXPRTEngine**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxprtengine) object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

Use [**D3DXConcatenateMeshes**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxconcatenatemeshes) to combine multiple meshes into a single mesh interface.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)

