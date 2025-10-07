# D3DVERTEXELEMENT9 structure

Defines the vertex data layout. Each vertex can contain one or more data types, and each data type is described by a vertex element.

## Members

**Stream**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Stream number.

**Offset**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset from the beginning of the vertex data to the data associated with the particular data type.

**Type**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The data type, specified as a [**D3DDECLTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddecltype). One of several predefined types that define the data size. Some methods have an implied type.

**Method**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The method specifies the tessellator processing, which determines how the tessellator interprets (or operates on) the vertex data. For more information, see [**D3DDECLMETHOD**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddeclmethod).

**Usage**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Defines what the data will be used for; that is, the interoperability between vertex data layouts and vertex shaders. Each usage acts to bind a vertex declaration to a vertex shader. In some cases, they have a special interpretation. For example, an element that specifies D3DDECLUSAGE\_NORMAL or D3DDECLUSAGE\_POSITION is used by the N-patch tessellator to set up tessellation. See [**D3DDECLUSAGE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddeclusage) for a list of the available semantics. D3DDECLUSAGE\_TEXCOORD can be used for user-defined fields (which don't have an existing usage defined).

**UsageIndex**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Modifies the usage data to allow the user to specify multiple usage types.

## Remarks

Vertex data is defined using an array of **D3DVERTEXELEMENT9** structures. Use [**D3DDECL\_END**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddecl-end) to declare the last element in the declaration.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-declaration)

