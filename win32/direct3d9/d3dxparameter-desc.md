# D3DXPARAMETER\_DESC structure

Describes a parameter used for an effect object.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the parameter.

**Semantic**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Semantic meaning, also called the usage.

**Class**

Type: **[**D3DXPARAMETER\_CLASS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-class)**

Parameter class. Set this to one of the values in [**D3DXPARAMETER\_CLASS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-class).

**Type**

Type: **[**D3DXPARAMETER\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-type)**

Parameter type. Set this to one of the values in [**D3DXPARAMETER\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-type).

**Rows**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of rows in the array.

**Columns**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of columns in the array.

**Elements**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of elements in the array.

**Annotations**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of annotations.

**StructMembers**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of structure members.

**Flags**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Parameter attributes. See [Effect Constants](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-constants).

**Bytes**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the parameter, in bytes.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9effect.h |

## See also

[Effect Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-structures)

