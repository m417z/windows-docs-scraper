# D3DXCONSTANT\_DESC structure

A description of a constant in a constant table.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the constant.

**RegisterSet**

Type: **[**D3DXREGISTER\_SET**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxregister-set)**

Constant data type. See [**D3DXREGISTER\_SET**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxregister-set).

**RegisterIndex**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the constant in the table.

**RegisterCount**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of registers that contain data.

**Class**

Type: **[**D3DXPARAMETER\_CLASS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-class)**

Parameter class. See [**D3DXPARAMETER\_CLASS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-class).

**Type**

Type: **[**D3DXPARAMETER\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-type)**

Parameter type. See [**D3DXPARAMETER\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxparameter-type).

**Rows**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of rows.

**Columns**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of columns.

**Elements**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of elements in the array.

**StructMembers**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of structure member sub-parameters.

**Bytes**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Data size in number of bytes.

**DefaultValue**

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the default value.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**D3DXCONSTANTTABLE\_DESC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxconstanttable-desc)

