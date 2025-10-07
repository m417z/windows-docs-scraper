# D3DXBONECOMBINATION structure

Describes a subset of the mesh that has the same attribute and bone combination.

## Members

**AttribId**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Attribute table identifier.

**FaceStart**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Starting face.

**FaceCount**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Face count.

**VertexStart**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Starting vertex.

**VertexCount**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Vertex count.

**BoneId**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an array of values that identify each of the bones that can be drawn in a single drawing call. Note that the array can be of variable length to accommodate variable length bone combinations of [**ConvertToIndexedBlendedMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo--converttoindexedblendedmesh).

The size of the array varies based on the type of mesh generated. A non-indexed mesh array size is equal to the number of weights per vertex (pMaxVertexInfl in [**ConvertToBlendedMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo--converttoblendedmesh)). An indexed mesh array size is equal to the number of bone matrix palette entries (paletteSize in [**ConvertToIndexedBlendedMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxskininfo--converttoindexedblendedmesh)).

## Remarks

The subset of the mesh described by **D3DXBONECOMBINATION** can be rendered in a single drawing call.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

