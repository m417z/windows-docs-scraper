# D3DXLoadMeshHierarchyFromXInMemory function

Loads the first frame hierarchy from a .x file.

## Parameters

*pMemory* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a buffer that contains the mesh hierarchy.

*SizeOfMemory* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the pMemory buffer, in bytes.

*MeshOptions* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more flags from the [**D3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmesh) enumeration that specify creation options for the mesh.

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device object associated with the mesh.

*pAlloc* \[in\]

Type: **[**LPD3DXALLOCATEHIERARCHY**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy)**

Pointer to an [**ID3DXAllocateHierarchy**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy) interface.

*pUserDataLoader* \[in\]

Type: **[**LPD3DXLOADUSERDATA**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxloaduserdata)**

Application provided interface that allows loading of user data. See [**ID3DXLoadUserData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxloaduserdata).

*ppFrameHeirarchy* \[out\]

Type: **[**LPD3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)\***

Returns a pointer to the loaded frame hierarchy. See [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe).

*ppAnimController* \[out\]

Type: **[**LPD3DXANIMATIONCONTROLLER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller)\***

Returns a pointer to the animation controller corresponding to animation in the .x file. This is created with default tracks and events. See [**ID3DXAnimationController**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

All the meshes in the file will be collapsed into one output mesh. If the file contains a frame hierarchy, all the transformations will be applied to the mesh.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |
| Library<br> | D3dx9.lib |

## See also

[Animation Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-animation)

