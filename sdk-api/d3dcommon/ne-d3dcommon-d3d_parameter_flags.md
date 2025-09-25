# D3D_PARAMETER_FLAGS enumeration

## Description

Indicates semantic flags for function parameters.

## Constants

### `D3D_PF_NONE:0`

The parameter has no semantic flags.

### `D3D_PF_IN:0x1`

Indicates an input parameter.

### `D3D_PF_OUT:0x2`

Indicates an output parameter.

### `D3D_PF_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## See also

[D3D11_PARAMETER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_parameter_desc)

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-enums)