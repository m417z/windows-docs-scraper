# D3DXValidPatchMesh function

Validates a patch mesh, returning the number of degenerate vertices and patches.

## Parameters

*pMeshIn* \[in\]

Type: **[**LPD3DXPATCHMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh)**

Pointer to an [**ID3DXPatchMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh) interface, representing the patch mesh to be tested.

*pNumDegenerateVertices* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Returns the number of degenerate vertices in the patch mesh.

*pNumDegeneratePatches* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Returns the number of degenerate patches in the patch mesh.

*ppErrorsAndWarnings* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a pointer to a buffer containing a string of errors and warnings that explain the problems found in the patch mesh.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

This method validates the mesh by checking for invalid indices. Error information is available from the debugger output.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

