# D3DXCreateMesh function

Creates a mesh object using a declarator.

## Parameters

*NumFaces* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of faces for the mesh. The valid range for this number is greater than 0, and one less than the maximum DWORD (typically 65534), because the last index is reserved.

*NumVertices* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices for the mesh. This parameter must be greater than 0.

*Options* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more flags from the [**D3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmesh) enumeration, specifying options for the mesh.

*pDeclaration* \[in\]

Type: **const [**LPD3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) elements, describing the vertex format for the returned mesh. This parameter must map directly to a flexible vertex format (FVF).

*pD3DDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device object to be associated with the mesh.

*ppMesh* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Address of a pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the created mesh object.

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

[**D3DXDeclaratorFromFVF**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxdeclaratorfromfvf)

