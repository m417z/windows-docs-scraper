# D3DX10\_SKINNING\_CHANNEL structure

The member of the vertex decl to do the software skinning on. This is used with the [**ID3DX10SkinInfo::DoSoftwareSkinning**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10skininfo-dosoftwareskinning) API.

## Members

**SrcOffset**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset from the beginning of each source vertex.

**DestOffset**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset from the beginning of each destination vertex.

**IsNormal**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Determines which array of matrices to use in the [**ID3DX10SkinInfo::DoSoftwareSkinning**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10skininfo-dosoftwareskinning) API. If this is true, the *pInverseTransposeBoneMatrices* will be used, otherwise *pBoneMatrices* will be used.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

