# D3DX10\_ATTRIBUTE\_RANGE structure

Stores an attribute table entry.

## Members

**AttribId**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Attribute table identifier.

**FaceStart**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Starting face.

**FaceCount**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Face count.

**VertexStart**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Starting vertex.

**VertexCount**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Vertex count.

## Remarks

An attribute table is used to identify areas of the mesh that need to be drawn with different textures, render states, materials, and so on. In addition, the application can use the attribute table to hide portions of a mesh by not drawing a given attribute identifier (AttribId) when drawing the frame.

The LPD3DX\_ATTRIBUTE\_RANGE type is defined as a pointer to the D3DX\_ATTRIBUTE\_RANGE structure.

```
typedef D3DX_ATTRIBUTE_RANGE* LPD3DX_ATTRIBUTE_RANGE;
```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

