# D3D10_SHADER_DEBUG_SCOPETYPE enumeration

## Description

Scope types.

## Constants

### `D3D10_SHADER_DEBUG_SCOPE_GLOBAL`

Global scope.

### `D3D10_SHADER_DEBUG_SCOPE_BLOCK`

Block scope.

### `D3D10_SHADER_DEBUG_SCOPE_FORLOOP`

For loop scope.

### `D3D10_SHADER_DEBUG_SCOPE_STRUCT`

Structure scope.

### `D3D10_SHADER_DEBUG_SCOPE_FUNC_PARAMS`

Function parameter scope.

### `D3D10_SHADER_DEBUG_SCOPE_STATEBLOCK`

State block scope.

### `D3D10_SHADER_DEBUG_SCOPE_NAMESPACE`

Name space scope.

### `D3D10_SHADER_DEBUG_SCOPE_ANNOTATION`

Annotation scope.

### `D3D10_SHADER_DEBUG_SCOPE_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The **D3D10_SHADER_DEBUG_SCOPETYPE** enumeration is used to specify scope type in the [D3D10_SHADER_DEBUG_SCOPE_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_scope_info) structure.

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-enums)