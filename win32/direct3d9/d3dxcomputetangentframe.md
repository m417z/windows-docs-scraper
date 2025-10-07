# D3DXComputeTangentFrame function

Compute tangent, binormal, and normal vectors for a mesh.

## Parameters

*pMesh* \[in\]

Type: **[**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Pointer to an input [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) mesh object.

*dwOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more [**D3DXTANGENT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtangent) flags.

Use **NULL** to specify the following options:

- Weight the normal vector length by the angle, in radians, subtended by the two edges leaving the vertex.
- Compute orthogonal Cartesian coordinates from the UV texture coordinates.
- Textures are not wrapped in either U or V directions
- Partial derivatives with respect to texture coordinates are normalized.
- Vertices are ordered in a counterclockwise direction around each triangle.
- Use per-vertex normal vectors already present in the input mesh.
- The results will be stored in the original input mesh. The function will fail if new vertices need to be created.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

This function simply calls [**D3DXComputeTangentFrameEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcomputetangentframeex) with the following input parameters:

```
D3DXComputeTangentFrameEx(pMesh, D3DDECLUSAGE_TEXCOORD, 0,
      D3DDECLUSAGE_BINORMAL, 0, D3DDECLUSAGE_TANGENT, 0,
      D3DDECLUSAGE_NORMAL, 0,
      dwOptions | D3DXTANGENT_GENERATE_IN_PLACE,
      NULL, 0.01f, 0.25f, 0.01f, NULL, NULL);
```

Singularities are handled as required by grouping edges and splitting vertices. If any vertices need to be split, the function will fail. The computed normal vector at each vertex is always normalized to have unit length.

The most robust solution for computing orthogonal Cartesian coordinates is to not set flags D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U and D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V, so that orthogonal coordinates are computed from both UV texture coordinates. However, in this case, if either U or V is zero, then the function will compute orthogonal coordinates using D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V or D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U respectively.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXComputeTangentFrameEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcomputetangentframeex)

[**D3DXTANGENT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtangent)

