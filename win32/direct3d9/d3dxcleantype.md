# D3DXCLEANTYPE enumeration

Defines operations to perform on vertices in preparation for mesh cleaning.

## Constants

**D3DXCLEAN\_BACKFACING**

Merge triangles that share the same vertex indices but have face normals pointing in opposite directions (back-facing triangles). Unless the triangles are not split by adding a replicated vertex, mesh adjacency data from the two triangles may conflict.

**D3DXCLEAN\_BOWTIES**

If a vertex is the apex of two triangle fans (a bowtie) and mesh operations will affect one of the fans, then split the shared vertex into two new vertices. Bowties can cause problems for operations such as mesh simplification that remove vertices, because removing one vertex affects two distinct sets of triangles.

**D3DXCLEAN\_SKINNING**

Use this flag to prevent infinite loops during skinning setup mesh operations.

**D3DXCLEAN\_OPTIMIZATION**

Use this flag to prevent infinite loops during mesh optimization operations.

**D3DXCLEAN\_SIMPLIFICATION**

Use this flag to prevent infinite loops during mesh simplification operations.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

