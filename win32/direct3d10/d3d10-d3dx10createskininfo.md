# D3DX10CreateSkinInfo function

Creates an empty skin mesh object using a declarator.

## Parameters

*ppSkinInfo* \[out\]

Type: **[**LPD3DX10SKININFO**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10skininfo)\***

Address of a pointer to an [**ID3DX10SkinInfo Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10skininfo), representing the created skin mesh object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be: E\_OUTOFMEMORY.

## Remarks

Use the [**ID3DX10SkinInfo::SetBoneInfluence**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10skininfo-setboneinfluence) to populate the empty skin mesh object returned by this method.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Mesh.h |
| Library<br> | D3DX10.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-mesh)

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions)

