# D3DXCreateSkinInfoFromBlendedMesh function

Creates a skin mesh from another mesh.

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXBASEMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh)**

Pointer to an [**ID3DXBaseMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh) object, the mesh from which to create the skin mesh.

*NumBones* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The length of the array attached to the BoneId. See [**D3DXBONECOMBINATION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxbonecombination).

*pBoneCombinationTable* \[in\]

Type: **const [**D3DXBONECOMBINATION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxbonecombination)\***

Pointer to an array of bone combinations. See [**D3DXBONECOMBINATION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxbonecombination).

*ppSkinInfo* \[out\]

Type: **[**LPD3DXSKININFO**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo)\***

Address of a pointer to an [**ID3DXSkinInfo**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo) interface representing the created skin mesh object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following: E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

