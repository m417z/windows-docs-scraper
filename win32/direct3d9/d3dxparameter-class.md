# D3DXPARAMETER\_CLASS enumeration

The type of object.

## Constants

**D3DXPC\_SCALAR**

Constant is a scalar.

**D3DXPC\_VECTOR**

Constant is a vector.

**D3DXPC\_MATRIX\_ROWS**

Constant is a row major matrix.

**D3DXPC\_MATRIX\_COLUMNS**

Constant is a column major matrix.

**D3DXPC\_OBJECT**

Constant is either a texture, shader, or a string.

**D3DXPC\_STRUCT**

Constant is a structure.

**D3DXPC\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

[**D3DXSHADER\_TYPEINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-typeinfo)

[**D3DXCONSTANT\_DESC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxconstant-desc)

