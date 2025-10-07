# D3DXComputeTangentFrameEx function

Performs tangent frame computations on a mesh. Tangent, binormal, and optionally normal vectors are generated. Singularities are handled as required by grouping edges and splitting vertices.

## Parameters

*pMesh* \[in\]

Type: **[**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Pointer to an input [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) mesh object.

*dwTextureInSemantic* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the texture coordinate input semantic. If D3DX\_DEFAULT, the function assumes that there are no texture coordinates, and the function will fail unless normal vector calculation is specified.

*dwTextureInIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If a mesh has multiple texture coordinates, specifies the texture coordinate to use for the tangent frame computations. If zero, the mesh has only a single texture coordinate.

*dwUPartialOutSemantic* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the output semantic for the type, typically D3DDECLUSAGE\_TANGENT, that describes where the partial derivative with respect to the U texture coordinate will be stored. If D3DX\_DEFAULT, then this partial derivative will not be stored.

*dwUPartialOutIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the semantic index at which to store the partial derivative with respect to the U texture coordinate.

*dwVPartialOutSemantic* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the [**D3DDECLUSAGE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddeclusage) type, typically D3DDECLUSAGE\_BINORMAL, that describes where the partial derivative with respect to the V texture coordinate will be stored. If D3DX\_DEFAULT, then this partial derivative will not be stored.

*dwVPartialOutIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the semantic index at which to store the partial derivative with respect to the V texture coordinate.

*dwNormalOutSemantic* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the output normal semantic, typically D3DDECLUSAGE\_NORMAL, that describes where the normal vector at each vertex will be stored. If D3DX\_DEFAULT, then this normal vector will not be stored.

*dwNormalOutIndex* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the semantic index at which to store the normal vector at each vertex.

*dwOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more [**D3DXTANGENT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtangent) flags that specify tangent frame computation options. If **NULL**, the following options will be specified:

| Description | [**D3DXTANGENT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtangent) Flag Value |
|----------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------|
| Weight the normal vector length by the angle, in radians, subtended by the two edges leaving the vertex. | & !( D3DXTANGENT\_WEIGHT\_BY\_AREA \| D3DXTANGENT\_WEIGHT\_EQUAL ) |
| Compute orthogonal Cartesian coordinates from texture coordinates (u, v). See Remarks. | & !( D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U \| D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V ) |
| Textures are not wrapped in either u or v directions | & !( D3DXTANGENT\_WRAP\_UV ) |
| Partial derivatives with respect to texture coordinates are normalized. | & !( D3DXTANGENT\_DONT\_NORMALIZE\_PARTIALS ) |
| Vertices are ordered in a counterclockwise direction around each triangle. | & !( D3DXTANGENT\_WIND\_CW ) |
| Use per-vertex normal vectors already present in the input mesh. | & !( D3DXTANGENT\_CALCULATE\_NORMALS ) |

If D3DXTANGENT\_GENERATE\_IN\_PLACE is not set, the input mesh is cloned. The original mesh must therefore have sufficient space to store the computed normal vector and partial derivative data.

*pdwAdjacency* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the mesh. The number of bytes in this array must be at least 3 \* [**GetNumFaces**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh--getnumfaces) \* sizeof(DWORD).

*fPartialEdgeThreshold* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the maximum cosine of the angle at which two partial derivatives are deemed to be incompatible with each other. If the dot product of the direction of the two partial derivatives in adjacent triangles is less than or equal to this threshold, then the vertices shared between these triangles will be split.

*fSingularPointThreshold* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the maximum magnitude of a partial derivative at which a vertex will be deemed singular. As multiple triangles are incident on a point that have nearby tangent frames, but altogether cancel each other out (such as at the top of a sphere), the magnitude of the partial derivative will decrease. If the magnitude is less than or equal to this threshold, then the vertex will be split for every triangle that contains it.

*fNormalEdgeThreshold* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Similar to fPartialEdgeThreshold, specifies the maximum cosine of the angle between two normals that is a threshold beyond which vertices shared between triangles will be split. If the dot product of the two normals is less than the threshold, the shared vertices will be split, forming a hard edge between neighboring triangles. If the dot product is more than the threshold, neighboring triangles will have their normals interpolated.

*ppMeshOut* \[out\]

Type: **[**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\*\***

Address of a pointer to an output [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) mesh object that receives the computed tangent, binormal, and normal vector data.

*ppVertexMapping* \[out\]

Type: **[**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\*\***

Address of a pointer to an output [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) buffer object that receives a mapping of new vertices computed by this method to the original vertices. The buffer is an array of DWORDs, with the array size defined as the number of vertices in ppMeshOut.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

A simplified version of this function is available as [**D3DXComputeTangentFrame**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcomputetangentframe).

The computed normal vector at each vertex is always normalized to have unit length.

The most robust solution for computing orthogonal Cartesian coordinates is to not set flags D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U and D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V, so that orthogonal coordinates are computed from both texture coordinates u and v. However, in this case, if either u or v is zero, then the function will compute orthogonal coordinates using D3DXTANGENT\_ORTHOGONALIZE\_FROM\_V or D3DXTANGENT\_ORTHOGONALIZE\_FROM\_U, respectively.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXComputeTangentFrame**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcomputetangentframe)

