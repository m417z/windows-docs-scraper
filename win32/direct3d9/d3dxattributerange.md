# D3DXATTRIBUTERANGE structure

Stores an attribute table entry.

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

## Remarks

An attribute table is used to identify areas of the mesh that need to be drawn with different textures, render states, materials, and so on. In addition, the application can use the attribute table to hide portions of a mesh by not drawing a given attribute identifier (AttribId) when drawing the frame.

The LPD3DXATTRIBUTERANGE type is defined as a pointer to the **D3DXATTRIBUTERANGE** structure.

```
typedef D3DXATTRIBUTERANGE* LPD3DXATTRIBUTERANGE;
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

