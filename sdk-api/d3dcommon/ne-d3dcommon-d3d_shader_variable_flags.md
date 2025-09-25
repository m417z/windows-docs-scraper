# D3D_SHADER_VARIABLE_FLAGS enumeration

## Description

Values that identify information about a shader variable.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_SVF_USERPACKED:1`

Indicates that the registers assigned to this shader variable were explicitly declared in shader code (instead of automatically assigned by the compiler).

### `D3D_SVF_USED:2`

Indicates that this variable is used by this shader. This value confirms that a particular shader variable (which can be common to many different shaders) is indeed used by a particular shader.

### `D3D_SVF_INTERFACE_POINTER:4`

Indicates that this variable is an interface.

### `D3D_SVF_INTERFACE_PARAMETER:8`

Indicates that this variable is a parameter of an interface.

### `D3D10_SVF_USERPACKED`

Indicates that the registers assigned to this shader variable were explicitly declared in shader code (instead of automatically assigned by the compiler).

### `D3D10_SVF_USED`

Indicates that this variable is used by this shader. This value confirms that a particular shader variable (which can be common to many different shaders) is indeed used by a particular shader.

### `D3D11_SVF_INTERFACE_POINTER`

Indicates that this variable is an interface.

### `D3D11_SVF_INTERFACE_PARAMETER`

Indicates that this variable is a parameter of an interface.

### `D3D_SVF_FORCE_DWORD:0x7fffffff`

This value is not used by a programmer; it exists to force the enumeration to compile to 32 bits.

## Remarks

A call to the [ID3D11ShaderReflectionVariable::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflectionvariable-getdesc) method returns **D3D_SHADER_VARIABLE_FLAGS** values in the **uFlags** member of a [D3D11_SHADER_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_variable_desc) structure.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)