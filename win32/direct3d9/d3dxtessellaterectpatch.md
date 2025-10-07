# D3DXTessellateRectPatch function

Tessellates a rectangular higher-order surface patch into a triangle mesh.

## Parameters

*pVB* \[in\]

Type: **[**LPDIRECT3DVERTEXBUFFER9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)**

Vertex buffer containing the patch data.

*pNumSegs* \[in\]

Type: **const [**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of four floating-point values that identify the number of segments into which each edge of the rectangle patch should be divided when tessellated. See [**D3DRECTPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3drectpatch-info).

*pInDecl* \[in\]

Type: **const [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Vertex declaration structure that defines the vertex data. See [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9).

*pRectPatchInfo* \[in\]

Type: **const [**D3DRECTPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3drectpatch-info)\***

Describes a rectangular patch. See [**D3DRECTPATCH\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3drectpatch-info).

*pMesh* \[in, out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to the created mesh. See [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

Use [**D3DXRectPatchSize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxrectpatchsize) to get the number of output vertices and indices that the tessellation function needs.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXTessellateTriPatch**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtessellatetripatch)

