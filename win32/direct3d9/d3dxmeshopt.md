# D3DXMESHOPT enumeration

Specifies the type of mesh optimization to be performed.

## Constants

**D3DXMESHOPT\_COMPACT**

Reorders faces to remove unused vertices and faces.

**D3DXMESHOPT\_ATTRSORT**

Reorders faces to optimize for fewer attribute bundle state changes and enhanced [**ID3DXBaseMesh::DrawSubset**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh--drawsubset) performance.

**D3DXMESHOPT\_VERTEXCACHE**

Reorders faces to increase the cache hit rate of vertex caches.

**D3DXMESHOPT\_STRIPREORDER**

Reorders faces to maximize length of adjacent triangles.

**D3DXMESHOPT\_IGNOREVERTS**

Optimize the faces only; do not optimize the vertices.

**D3DXMESHOPT\_DONOTSPLIT**

While attribute sorting, do not split vertices that are shared between attribute groups.

**D3DXMESHOPT\_DEVICEINDEPENDENT**

Affects the vertex cache size. Using this flag specifies a default vertex cache size that works well on legacy hardware.

## Remarks

The D3DXMESHOPT\_STRIPREORDER and D3DXMESHOPT\_VERTEXCACHE optimization flags are mutually exclusive.

The D3DXMESHOPT\_SHAREVB flag has been removed from this enumeration. Use D3DXMESH\_VB\_SHARE instead, in [**D3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmesh).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

