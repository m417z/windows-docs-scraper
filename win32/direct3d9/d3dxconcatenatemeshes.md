# D3DXConcatenateMeshes function

Concatenates a group of meshes into one common mesh. This method can optionally apply a matrix transformation to each input mesh and its texture coordinates.

## Parameters

*ppMeshes* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Array of input mesh pointers (see [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)). The number of elements in the array is NumMeshes.

*NumMeshes* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of input meshes to concatenate.

*Options* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Mesh creation options; this is a combination of one or more [**D3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmesh) flags. The mesh creation options are equivalent to the options parameter required by [**D3DXCreateMesh**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatemesh).

*pGeomXForms* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Optional array of geometry transforms. The number of elements in the array is NumMeshes; each element is a transformation matrix (see [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)). May be **NULL**.

*pTextureXForms* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Optional array of texture transforms. The number of elements in the array is NumMeshes; each element is a transformation matrix (see [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)). This parameter may be **NULL**.

*pDecl* \[in\]

Type: **const [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Optional pointer to a vertex declaration (see [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)). This parameter may be **NULL**.

*pD3DDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to a [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) device that is used to create the new mesh.

*ppMeshOut* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Address of a pointer to the mesh created (see [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of these: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

If no [vertex declaration](https://learn.microsoft.com/windows/win32/direct3d9/vertex-declaration) is given as part of the Options mesh creation parameter, the method will generate a union of all of the vertex declarations of the submeshes, promoting channels and types if necessary. The method will create an attribute table from attribute tables of the input meshes. To ensure creation of an attribute table, call [**Optimize**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh--optimize) with Flags set to D3DXMESHOPT\_COMPACT and D3DXMESHOPT\_ATTRSORT (see [**D3DXMESHOPT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmeshopt)).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

