# D3D10_SHADER_DEBUG_SCOPEVAR_INFO structure

## Description

Describes a shader scope variable.

## Members

### `TokenId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into variable token.

### `VarType`

Type: **[D3D10_SHADER_DEBUG_VARTYPE](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ne-d3d10_1shader-d3d10_shader_debug_vartype)**

Indicates whether this is a variable or function.

### `Class`

Type: **[D3D10_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)**

Indicates the variable class.

### `Rows`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of row for matrices.

### `Columns`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of columns for vectors or matrices.

### `StructMemberScope`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Gives a scope to look up struct members. This member will be -1 if **D3D10_SHADER_DEBUG_SCOPEVAR_INFO** does not refer to a struct.

### `uArrayIndices`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of array indices. For example a three dimensional array would have a value of 3 for **uArrayIndices**.

### `ArrayElements`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to an array of UINT values **uArrayIndices** long. The array contains the maximum value for each index. For example an array a[3][2][1] would have the values {3,2,1} at the offset pointed to by **ArrayElements**.

### `ArrayStrides`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to an array of UINT values **uArrayIndices** long. The array contains the stride for each array index. For example an array a[3][2][1] would have the values {2,1,1} at the offset pointed to by **ArrayStrides**.

### `uVariables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of variables.

### `uFirstVariable`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first variable, later variables are offsets from this one.

## Remarks

The **D3D10_SHADER_DEBUG_SCOPEVAR_INFO** structure is used with the [D3D10_SHADER_DEBUG_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_info) structure.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)