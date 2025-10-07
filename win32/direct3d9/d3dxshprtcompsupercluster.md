# D3DXSHPRTCompSuperCluster function

Used with compressed results of the vertex version of the precomputed radiance transfer (PRT) simulator. Generates "superclusters," which are groups of clusters that can be drawn in the same draw call. A greedy algorithm that minimizes overdraw is used to group the clusters.

## Parameters

*pClusterIDs* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a NumVerts cluster IDs (extracted from a compressed buffer.)

*pScene* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to a mesh that represents composite scene passed to the simulator. See [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh).

*MaxNumClusters* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum number of clusters allocated per super cluster.

*NumClusters* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of clusters computed in the simulator.

*pSClusterIDs* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of length *NumClusters*. Contains the index of the super cluster to which the corresponding cluster was assigned.

*pNumSCs* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Number of super clusters allocated.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Precomputed Radiance Transfer Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-prt)

