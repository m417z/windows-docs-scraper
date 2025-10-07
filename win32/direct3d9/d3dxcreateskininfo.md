# D3DXCreateSkinInfo function

Creates an empty skin mesh object using a declarator.

## Parameters

*NumVertices* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices for the skin mesh.

*pDeclaration* \[in\]

Type: **const [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9)\***

Array of [**D3DVERTEXELEMENT9**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexelement9) elements, describing the vertex format for the returned mesh.

*NumBones* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of bones for the skin mesh.

*ppSkinInfo* \[out\]

Type: **[**LPD3DXSKININFO**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo)\***

Address of a pointer to an [**ID3DXSkinInfo**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo) interface, representing the created skin mesh object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be: E\_OUTOFMEMORY.

## Remarks

Use [**SetBoneInfluence**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo--setboneinfluence) to populate the empty skin mesh object returned by this method.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

[**SetBoneInfluence**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo--setboneinfluence)

