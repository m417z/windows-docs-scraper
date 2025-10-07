# D3DX10\_MESHOPT enumeration

Specifies the type of mesh optimization to be performed.

## Constants

**D3DX10\_MESHOPT\_COMPACT**

Reorders faces to remove unused vertices and faces.

**D3DX10\_MESHOPT\_ATTR\_SORT**

Reorders faces to optimize for fewer attribute bundle state changes and enhanced DrawSubset performance.

**D3DX10\_MESHOPT\_VERTEX\_CACHE**

Reorders faces to increase the cache hit rate of vertex caches.

**D3DX10\_MESHOPT\_STRIP\_REORDER**

Reorders faces to maximize length of adjacent triangles.

**D3DX10\_MESHOPT\_IGNORE\_VERTS**

Optimize the faces only; do not optimize the vertices.

**D3DX10\_MESHOPT\_DO\_NOT\_SPLIT**

While attribute sorting, do not split vertices that are shared between attribute groups.

**D3DX10\_MESHOPT\_DEVICE\_INDEPENDENT**

Affects the vertex cache size. Using this flag specifies a default vertex cache size that works well on legacy hardware.

## Remarks

The D3DXMESHOPT\_STRIPREORDER and D3DXMESHOPT\_VERTEXCACHE optimization flags are mutually exclusive.

The D3DXMESHOPT\_SHAREVB flag has been removed from this enumeration. Use D3DXMESH\_VB\_SHARE instead, in D3DXMESH.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-enums)

