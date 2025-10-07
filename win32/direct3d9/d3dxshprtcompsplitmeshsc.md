# D3DXSHPRTCompSplitMeshSC function

Used with compressed results of the vertex version of the precomputed radiance transfer (PRT) simulator. After [**D3DXSHPRTCompSuperCluster**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshprtcompsupercluster) has been called, this function can be used to split the mesh into a group of faces/vertices per super cluster. Each super cluster contains all of the faces that contain any vertex classified in one of its clusters. All of the vertices connected to this set of faces are also included with the returned array ppVertStatus indicating whether or not the vertex belongs to the super cluster.

## Parameters

*pClusterIDs* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

*NumVertices* cluster IDs (extracted from a compressed buffer.)

*NumVertices* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices in original mesh.

*NumCs* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of clusters (input parameter to compression.)

*pSClusterIDs* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Array of size *NumCs* that will contain super cluster IDs.

*NumSCs* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of super clusters allocated in [**D3DXSHPRTCompSuperCluster**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshprtcompsupercluster).

*pInputIB* \[in\]

Type: **[**LPVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Raw index buffer for mesh. The format depends on *InputIBIs32Bit*.

*InputIBIs32Bit* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If **TRUE**, the index buffer is set to 32 bit; otherwise, 16 bit.

*NumFaces* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of faces in the original mesh (*pInputIB* is 3 times this length.)

*ppIBData* \[in, out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Raw index buffer that will contain the resulting split faces. Format determined by *InputIBIs32Bit*. Allocated by function.

*pIBDataLength* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Length of *ppIBData*, assigned in function.

*OutputIBIs32Bit* \[in, out\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If **TRUE**, allocates an unsigned integer array; otherwise, allocates an unsigned short array.

*ppFaceRemap* \[in, out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Mapping of each face in *ppIBData* to original faces. Length is \**pIBDataLength*/3.

*ppVertData* \[in, out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

New vertex data structure. Size of *pVertDataLength*.

*pVertDataLength* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Number of new vertices in split mesh. Assigned in function.

*pSCClusterList* \[in, out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Array of length *NumCs* which *pSCData* indexes into (*pClusterIDs*\* fields) for each supercluster, contains clusters sorted by supercluster.

*pSCData* \[in, out\]

Type: **[**D3DXSHPRTSPLITMESHCLUSTERDATA**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshprtsplitmeshclusterdata)\***

Structure per super cluster. Contains indices into *ppIBData*, *pSCClusterList*, and *ppVertData*.

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

