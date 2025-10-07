# D3DXWELDEPSILONSFLAGS enumeration

Options for welding together vertices.

## Constants

**D3DXWELDEPSILONS\_WELDALL**

Weld together all vertices that are at the same location. Using this flag avoids an epsilon comparison between vertex components.

**D3DXWELDEPSILONS\_WELDPARTIALMATCHES**

If a given vertex component is within epsilon, modify partially matched vertices so that both components are identical. If all components are equal, remove one of the vertices.

**D3DXWELDEPSILONS\_DONOTREMOVEVERTICES**

Instructs the weld to allow only modifications to vertices and not removal. This flag is valid only if D3DXWELDEPSILONS\_WELDPARTIALMATCHES is set. It is useful to modify vertices to be equal, but not to allow vertices to be removed.

**D3DXWELDEPSILONS\_DONOTSPLIT**

Instructs the weld not to split vertices that are in separate attribute groups. When the [**ID3DXMesh::Optimize**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh--optimize) method is called with the D3DXMESHOPT\_ATTRSORT flag, then the D3DXMESHOPT\_DONOTSPLIT flag will also be set. Setting this flag can slow down software vertex processing.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

[**D3DXWeldVertices**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxweldvertices)

