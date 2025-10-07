# D3DXOptimizeFaces function

Generates an optimized face remapping for a triangle list.

## Parameters

*pIndices* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to triangle list indices to use for ordering vertices.

*NumFaces* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of faces in the triangle list. For 16-bit meshes, this is limited to 2^16 - 1 (65535) or fewer faces.

*NumVertices* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices referenced by the triangle list.

*Indices32Bit* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Flag indicating index type: **TRUE** if indices are 32-bit (more than 65535 indices), **FALSE** if indices are 16-bit (65535 or fewer indices).

*pFaceRemap* \[in, out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the original mesh face that was split to generate the current face.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

This function's optimization procedure is functionally equivalent to calling [**ID3DXMesh::Optimize**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh--optimize) with the D3DXMESHOPT\_DEVICEINDEPENDENT flag, but this function makes more efficient use of vertex caches.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

