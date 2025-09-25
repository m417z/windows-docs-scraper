# D3D10_SHADER_DEBUG_VAR_INFO structure

## Description

Represents information about a shader source variable.

## Members

### `TokenId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into token list for declaring identifier.

### `Type`

Type: **[D3D10_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)**

The variable type. **Type** is only required for arrays.

### `Register`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Register the variable is stored in.

### `Component`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The original variable that declared this variable.

### `ScopeVar`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset into the scope variable array defined in [D3D10_SHADER_DEBUG_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_info).

### `ScopeVarOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This variable's offset in its **ScopeVar**.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)