# MAX\_FVF\_DECL\_SIZE enumeration

This constant is the maximum number of vertex declarators for a mesh.

## Constants

**MAX\_FVF\_DECL\_SIZE**

The maximum number of elements in the vertex declaration. The additional (+1) is for [**D3DDECL\_END**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddecl-end).

## Remarks

MAXD3DDECLLENGTH is defined as a maximum of 64 (see d3d9types.h). This does not include the "end" marker vertex element.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

[**ID3DXBaseMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh)

[**GetDeclaration**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvertexdeclaration9-getdeclaration)

[**D3DXDeclaratorFromFVF**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxdeclaratorfromfvf)

[**ID3DXSkinInfo**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo)

