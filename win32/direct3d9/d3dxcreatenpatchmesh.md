# D3DXCreateNPatchMesh function

Creates an N-patch mesh from a triangle mesh.

## Parameters

*pMeshSysMem* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Address of a pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface that represents the triangle mesh object.

*pPatchMesh* \[in, out\]

Type: **[**LPD3DXPATCHMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh)\***

Address of a pointer to an [**ID3DXPatchMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh) interface that represents the created patch mesh object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

