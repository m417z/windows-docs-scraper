# D3DXSHADER\_TYPEINFO structure

A helper structure containing member type information.

## Members

**Class**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Shader object type. See [**D3DXPARAMETER\_CLASS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-class).

**Type**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Data type. See [**D3DXPARAMETER\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-type).

**Rows**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of matrix rows (matrices).

**Columns**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of columns (vectors and matrices).

**Elements**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Array dimension.

**StructMembers**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of structure members.

**StructMemberInfo**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Array of structure member information, D3DXSHADER\_STRUCTMEMBERINFO\[*StructMembers*\]. See [**D3DXSHADER\_STRUCTMEMBERINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-structmemberinfo).

## Remarks

The type information is part of [**D3DXSHADER\_STRUCTMEMBERINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-structmemberinfo).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**D3DXSHADER\_CONSTANTINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-constantinfo)

