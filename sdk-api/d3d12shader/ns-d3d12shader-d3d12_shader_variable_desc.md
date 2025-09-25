# D3D12_SHADER_VARIABLE_DESC structure

## Description

Describes a shader variable.

## Members

### `Name`

The variable name.

### `StartOffset`

Offset from the start of the parent structure to the beginning of the variable.

### `Size`

Size of the variable (in bytes).

### `uFlags`

A combination of [D3D_SHADER_VARIABLE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_flags)-typed values that are combined by using a bitwise-OR operation.
The resulting value identifies shader-variable properties.

### `DefaultValue`

The default value for initializing the variable.
Emits default values for reflection.

### `StartTexture`

Offset from the start of the variable to the beginning of the texture.

### `TextureSize`

The size of the texture, in bytes.

### `StartSampler`

Offset from the start of the variable to the beginning of the sampler.

### `SamplerSize`

The size of the sampler, in bytes.

## Remarks

Get a shader-variable description using reflection by calling [ID3D12ShaderReflectionVariable::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflectionvariable-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)