# D3DXSimplifyMesh function

Generates a simplified mesh using the provided weights that come as close as possible to the given MinValue.

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the source mesh.

*pAdjacency* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the mesh to be simplified.

*pVertexAttributeWeights* \[in\]

Type: **const [**D3DXATTRIBUTEWEIGHTS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxattributeweights)\***

Pointer to a [**D3DXATTRIBUTEWEIGHTS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxattributeweights) structure, containing the weight for each vertex component. If this parameter is set to **NULL**, a default structure is used. See Remarks.

*pVertexWeights* \[in\]

Type: **const [**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of vertex weights. If this parameter is set to **NULL**, all vertex weights are set to 1.0.

*MinValue* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices or faces, depending on the flag set in the *Options* parameter, by which to simplify the source mesh.

*Options* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies simplification options for the mesh. One of the flags in [**D3DXMESHSIMP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmeshsimp) can be set.

*ppMesh* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Address of a pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the returned simplification mesh.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

This function generates a mesh that has *MinValue* vertices or faces.

If the simplification process cannot reduce the mesh to *MinValue*, the call still succeeds because *MinValue* is a desired minimum, not an absolute minimum.

If *pVertexAttributeWeights* is set to **NULL**, the following values are assigned to the default [**D3DXATTRIBUTEWEIGHTS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxattributeweights) structure.

```
D3DXATTRIBUTEWEIGHTS AttributeWeights;

AttributeWeights.Position  = 1.0;
AttributeWeights.Boundary =  1.0;
AttributeWeights.Normal   =  1.0;
AttributeWeights.Diffuse  =  0.0;
AttributeWeights.Specular =  0.0;
AttributeWeights.Tex[8]   =  {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
```

This default structure is what most applications should use because it considers only geometric and normal adjustment. Only in special cases will the other member fields need to be modified.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

