# D3DXLoadMeshHierarchyFromX function

Loads the first frame hierarchy from a .x file.

## Parameters

*Filename* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the filename. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

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

*ppFrameHierarchy* \[out\]

Type: **[**LPD3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)\***

Returns a pointer to the loaded frame hierarchy. See [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe).

*ppAnimController* \[out\]

Type: **[**LPD3DXANIMATIONCONTROLLER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller)\***

Returns a pointer to the animation controller corresponding to animation in the .x file. This is created with default tracks and events. See [**ID3DXAnimationController**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXLoadMeshHierarchyFromXW. Otherwise, the function call resolves to D3DXLoadMeshHierarchyFromXA.

All the meshes in the file will be collapsed into one output mesh. If the file contains a frame hierarchy, all the transformations will be applied to the mesh.

**D3DXLoadMeshHierarchyFromX** loads the animation data and frame hierarchy from a .x file. It scans the .x file and builds a frame hierarchy and animation controller according to the [**ID3DXAllocateHierarchy**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy)-derived object passed to it through pAlloc. Loading the data requires several steps as follows:

1. Derive [**ID3DXAllocateHierarchy**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy), implementing each method. This controls how frames and meshes are allocated and freed.
2. Derive [**ID3DXLoadUserData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxloaduserdata), implementing each method. If your .x file has no embedded user-defined data, or if you do not need it, you can skip this part.
3. Create an object of your [**ID3DXAllocateHierarchy**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy) class, and optionally of your LoadUserData class. You do not need to call any methods of these objects yourself.
4. Call **D3DXLoadMeshHierarchyFromX**, passing in your [**ID3DXAllocateHierarchy**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy) object and your [**ID3DXLoadUserData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxloaduserdata) object (or **NULL**) to create the frame hierarchy and animation controller. All the animation sets and frames are automatically registered to the animation controller.

During the load, [**CreateFrame**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy--createframe) and [**LoadFrameChildData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxloaduserdata--loadframechilddata) are called back on each frame to control loading and allocation of the frame. The application defines these methods to control how frames are stored. [**CreateMeshContainer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy--createmeshcontainer) and [**LoadMeshChildData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxloaduserdata--loadmeshchilddata) are called back on each mesh object to control loading and allocation of mesh objects. [**LoadTopLevelData**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxloaduserdata--loadtopleveldata) is called back for each top level object that doesn't get loaded by the other methods.

To free this data, call ID3DXAnimationController::Release to free the animation sets, and [**D3DXFRAMEDestroy**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframedestroy), passing in the root node of the frame hierarchy and an object of your derived [**ID3DXAllocateHierarchy**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy) class. [**DestroyFrame**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy--destroyframe) and [**DestroyMeshContainer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy--destroymeshcontainer) will each be called for every frame and mesh object in the frame hierarchy. Your implementation of **DestroyFrame** should release everything allocated by [**CreateFrame**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy--createframe), and likewise for the mesh container methods.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |
| Library<br> | D3dx9.lib |

## See also

[Animation Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-animation)

