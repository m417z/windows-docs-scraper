# D3DX10CreateMesh function

Creates a mesh object using a declarator.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

Pointer to an [**ID3D10Device Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device), the device object to be associated with the mesh.

*pDeclaration* \[in\]

Type: **const [**D3D10\_INPUT\_ELEMENT\_DESC**](https://learn.microsoft.com/windows/desktop/api/D3D10/ns-d3d10-d3d10_input_element_desc)\***

Array of [**D3D10\_INPUT\_ELEMENT\_DESC**](https://learn.microsoft.com/windows/desktop/api/D3D10/ns-d3d10-d3d10_input_element_desc) elements, describing the vertex format for the returned mesh. This parameter must map directly to a flexible vertex format (FVF).

*DeclCount* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of elements in pDeclaration.

*pPositionSemantic* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Semantic that identifies which part of the vertex declaration contains position information.

*VertexCount* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices for the mesh. This parameter must be greater than 0.

*FaceCount* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of faces for the mesh. The valid range for this number is greater than 0, and one less than the maximum DWORD (typically 65534), because the last index is reserved.

*Options* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more flags from the [**D3DX10\_MESH**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-mesh), specifying options for the mesh.

*ppMesh* \[out\]

Type: **[**ID3DX10Mesh**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10mesh)\*\***

Address of a pointer to an [**ID3DX10Mesh Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10mesh), representing the created mesh object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Mesh.h |
| Library<br> | D3DX10.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-mesh)

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions)

