# D3DXEFFECTDEFAULTTYPE enumeration

Effect data types. The data is contained in the pValue member of [**D3DXEFFECTDEFAULT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectdefault).

## Constants

**D3DXEDT\_STRING**

The data type is a NULL-terminated ASCII text string.

**D3DXEDT\_FLOATS**

The data type is an array of type float. The number of float types in the array is specified by NumBytes in [**D3DXEFFECTDEFAULT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectdefault).

**D3DXEDT\_DWORD**

The data type is a DWORD.

**D3DXEDT\_FORCEDWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

