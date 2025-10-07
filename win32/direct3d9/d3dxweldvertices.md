# D3DXWeldVertices function

Welds together replicated vertices that have equal attributes. This method uses specified epsilon values for equality comparisons.

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) object, the mesh from which to weld vertices.

*Flags* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more flags from [**D3DXWELDEPSILONSFLAGS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxweldepsilonsflags).

*pEpsilons* \[in\]

Type: **const [**D3DXWeldEpsilons**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxweldepsilons)\***

Pointer to a [**D3DXWeldEpsilons**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxweldepsilons) structure, specifying the epsilon values to be used for this method. Use **NULL** to initialize all structure members to a default value of 1.0e-6f.

*pAdjacencyIn* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the source mesh. If the edge has no adjacent faces, the value is 0xffffffff. If this parameter is set to **NULL**, [**ID3DXBaseMesh::GenerateAdjacency**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh--generateadjacency) will be called to create logical adjacency information.

*pAdjacencyOut* \[in, out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the optimized mesh. If the edge has no adjacent faces, the value is 0xffffffff.

*pFaceRemap* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

An array of DWORDs, one per face, that identifies the original mesh face that corresponds to each face in the welded mesh.

*ppVertexRemap* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Address of a pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) interface, which contains a DWORD for each vertex that specifies how the new vertices map to the old vertices. This remap is useful if you need to alter external data based on the new vertex mapping.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

This function uses supplied adjacency information to determine the points that are replicated. Vertices are merged based on an epsilon comparison. Vertices with equal position must already have been calculated and represented by point-representative data.

This function combines logically-welded vertices that have similar components, such as normals or texture coordinates within pEpsilons.

The following example code calls this function with welding enabled. Vertices are compared using epsilon values for normal vector and vertex position. A pointer is returned to a face remapping array (*pFaceRemap*).

```
TCHAR            strMediaPath[512];       // X-file path
LPD3DXBUFFER     pAdjacencyBuffer = NULL; // adjacency data buffer
LPD3DXBUFFER     pD3DXMtrlBuffer  = NULL; // material buffer
LPD3DXMESH       pMesh            = NULL; // mesh object
DWORD            m_dwNumMaterials;        // number of materials
D3DXWELDEPSILONS Epsilons;                // structure with epsilon values
DWORD            *pFaceRemap[65536];      // face remapping array
DWORD            i;                       // internal variable

    // Load the mesh from the specified file
    hr = D3DXLoadMeshFromX ( strMediaPath,
                         D3DXMESH_MANAGED,
                         m_pd3dDevice,
                         &pAdjacencyBuffer,
                         &pD3DXMtrlBuffer,
                         NULL,
                         &m_dwNumMaterials,
                         &pMesh ) )

    if( FAILED( hr ) )
      goto End;              // Go to error handling

    // Set epsilon values
    Epsilons.Normal = 0.001;
    Epsilons.Position = 0.1;

    // Weld the vertices
    for( i=0; i < 65536; i++ )
    {
        pFaceRemap[i] = 0;
    }

    hr = D3DXWeldVertices ( pMesh,
                            D3DXWELDEPSILONS_WELDPARTIALMATCHES,
                            &Epsilons,
                            (DWORD*)pAdjacencyBuffer->GetBufferPointer(),
                            (DWORD*)pAdjacencyBuffer->GetBufferPointer(),
                            (DWORD*)pFaceRemap,
                            NULL )

    if( FAILED( hr ) )
      goto End;              // Go to error handling
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

