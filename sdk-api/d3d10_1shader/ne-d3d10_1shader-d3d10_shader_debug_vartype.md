# D3D10_SHADER_DEBUG_VARTYPE enumeration

## Description

Distinguishes variables from functions in a scope.

## Constants

### `D3D10_SHADER_DEBUG_VAR_VARIABLE`

Element is a variable.

### `D3D10_SHADER_DEBUG_VAR_FUNCTION`

Element is a function.

### `D3D10_SHADER_DEBUG_VAR_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)