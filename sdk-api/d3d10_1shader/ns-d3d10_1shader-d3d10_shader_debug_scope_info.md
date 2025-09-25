# D3D10_SHADER_DEBUG_SCOPE_INFO structure

## Description

Contains scope data that maps variable names to debug variables.

## Members

### `ScopeType`

Type: **[D3D10_SHADER_DEBUG_SCOPETYPE](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ne-d3d10_1shader-d3d10_shader_debug_scopetype)**

Specifies the scope type.

### `Name`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to the name of scope in the strings list.

### `uNameLen`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the string pointed to by **Name**.

### `uVariables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of variables.

### `VariableData`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset an array of UINT values with **uVariables** members containing the scope variable list.

## Remarks

The **D3D10_SHADER_DEBUG_SCOPE_INFO** structure is used with the [D3D10_SHADER_DEBUG_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_info) structure.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)