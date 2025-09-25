# D3D10_SHADER_DEBUG_REGTYPE enumeration

## Description

Shader register types.

## Constants

### `D3D10_SHADER_DEBUG_REG_INPUT`

Input register.

### `D3D10_SHADER_DEBUG_REG_OUTPUT`

Output register.

### `D3D10_SHADER_DEBUG_REG_CBUFFER`

Constant buffer register.

### `D3D10_SHADER_DEBUG_REG_TBUFFER`

Texture buffer register.

### `D3D10_SHADER_DEBUG_REG_TEMP`

Temporary register.

### `D3D10_SHADER_DEBUG_REG_TEMPARRAY`

Array of temporary registers.

### `D3D10_SHADER_DEBUG_REG_TEXTURE`

Texture register.

### `D3D10_SHADER_DEBUG_REG_SAMPLER`

Sampler register.

### `D3D10_SHADER_DEBUG_REG_IMMEDIATECBUFFER`

Immediate constant buffer register.

### `D3D10_SHADER_DEBUG_REG_LITERAL`

Literal register.

### `D3D10_SHADER_DEBUG_REG_UNUSED`

Unused register.

### `D3D11_SHADER_DEBUG_REG_INTERFACE_POINTERS`

Interface register.

### `D3D11_SHADER_DEBUG_REG_UAV`

Unordered Access View (UAV) register.

### `D3D10_SHADER_DEBUG_REG_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The **D3D10_SHADER_DEBUG_REGTYPE** enumeration is used to specify register types
in [D3D10_SHADER_DEBUG_INPUT_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_outputreg_info) and [D3D10_SHADER_DEBUG_OUTPUTREG_INFO](https://learn.microsoft.com/windows/desktop/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_outputreg_info).

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-enums)