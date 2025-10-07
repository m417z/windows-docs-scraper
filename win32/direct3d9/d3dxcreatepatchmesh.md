# D3DXCreatePatchMesh function

Creates a mesh from a control-patch mesh.

## Parameters

*pInfo* \[in\]

Type: **const [**D3DXPATCHINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxpatchinfo)\***

Patch information structure. For more information, see [**D3DXPATCHINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxpatchinfo).

*dwNumPatches* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of patches.

*dwNumVertices* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of control vertices in the patch.

*dwOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Unused. Reserved for later use.

*pDecl* \[in\]

Type: **const [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) elements, describing the vertex format for the returned mesh.

*pD3DDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer the device that creates the patch mesh. See [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9).

*pPatchMesh* \[out\]

Type: **[**LPD3DXPATCHMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh)\***

Pointer to the [**ID3DXPatchMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh) object that is created.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

This method takes an input patch mesh and converts it to a tessellated mesh. Patch meshes use 16-bit index buffers. Therefore, indices to [**LockIndexBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxpatchmesh--lockindexbuffer) are 16 bits.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**D3DXPATCHINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxpatchinfo)

