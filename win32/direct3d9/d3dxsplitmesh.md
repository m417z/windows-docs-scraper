# D3DXSplitMesh function

Splits a mesh into meshes smaller than the specified size.

## Parameters

*pMeshIn* \[in\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)**

Pointer to an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface, representing the source mesh.

*pAdjacencyIn* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of three DWORDs per face that specify the three neighbors for each face in the mesh to be simplified.

*MaxSize* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum number of vertices in the resulting mesh.

*Options* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Option flags for the new meshes.

*pMeshesOut* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Number of meshes returned.

*ppMeshArrayOut* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Buffer containing an array of [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interfaces for the new meshes. For a source mesh split into n meshes, *ppMeshArrayOut* is an array of n **ID3DXMesh** pointers.

*ppAdjacencyArrayOut* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Buffer containing an array of adjacency arrays (DWORDs) for the new meshes. See [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer). This parameter is optional.

*ppFaceRemapArrayOut* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Buffer containing an array of face remap arrays (DWORDs) for the new meshes. See [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer). This parameter is optional.

*ppVertRemapArrayOut* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Buffer containing an array of vertex remap arrays for the new meshes. See [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer). This parameter is optional.

## Return value

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

A common use of this function is to split a mesh with 32-bit indices (more than 65535 vertices) into more than one mesh, each of which has 16-bit indices.

The adjacency, vertex remap and face remap arrays are arrays are DWORDs where each array contains n DWORD pointers, followed by the DWORD data referenced by the pointers. For example, to obtain the face remap information for face 3 in mesh 2, the following code could be used, assuming the face remap data was returned in a variable named *ppFaceRemapArrayOut*.

```

const DWORD **face_remaps =
    static_cast<DWORD **>(ppFaceRemapArrayOut->GetBufferPointer());
const DWORD remap = face_remaps[2][3];
```

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

