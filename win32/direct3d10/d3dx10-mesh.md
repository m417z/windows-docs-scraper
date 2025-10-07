# D3DX10\_MESH enumeration

Flags used to specify creation options for a mesh.

## Constants

**D3DX10\_MESH\_32\_BIT**

The mesh has 32-bit indices instead of 16-bit indices. See Remarks.

**D3DX10\_MESH\_GS\_ADJACENCY**

Signals that the mesh contains geometry shader adjacency data.

## Remarks

A 32-bit mesh (D3DXMESH\_32BIT) can theoretically support (2³²)-1 faces and vertices. However, allocating memory for a mesh that large on a 32-bit operating system is not practical.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-enums)

