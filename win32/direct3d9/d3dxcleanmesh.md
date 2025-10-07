# D3DXCleanMesh function

Cleans a mesh, preparing it for simplification.

## Parameters

*CleanType* \[in\]

Type: **[**D3DXCLEANTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcleantype)**

Vertex operations to perform in preparation for mesh cleaning. See [**D3DXCLEANTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcleantype).

*pMeshIn* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the mesh to be cleaned.

*pAdjacencyIn* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the mesh to be cleaned.

*ppMeshOut* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Address of a pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the returned cleaned mesh. The same mesh is returned that was passed in if no cleaning was necessary.

*pAdjacencyOut* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the output mesh.

*ppErrorsAndWarnings* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing a string of errors and warnings, which explain the problems found in the mesh.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

This function cleans a mesh using the cleaning method and options specified in the CleanType parameter. See the [**D3DXCLEANTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcleantype) enumeration for a description of the available options.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

