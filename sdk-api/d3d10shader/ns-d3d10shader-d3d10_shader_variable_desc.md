# D3D10_SHADER_VARIABLE_DESC structure

## Description

Describes a shader variable.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The variable name.

### `StartOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from the start of the parent structure, to the beginning of the variable.

### `Size`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the variable (in bytes).

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags, which identify shader-variable properties (see [D3D10_SHADER_VARIABLE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_flags)).

### `DefaultValue`

Type: **[LPVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The default value for initializing the variable.

## Remarks

Get a shader-variable description using reflection, by calling [ID3D10ShaderReflectionVariable::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-id3d10shaderreflectionvariable-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)