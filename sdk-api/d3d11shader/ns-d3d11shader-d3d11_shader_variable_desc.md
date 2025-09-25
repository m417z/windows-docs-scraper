# D3D11_SHADER_VARIABLE_DESC structure

## Description

Describes a shader variable.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The variable name.

### `StartOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from the start of the parent structure to the beginning of the variable.

### `Size`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the variable (in bytes).

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D_SHADER_VARIABLE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_flags)-typed values that are combined by using a bitwise OR operation. The resulting value identifies shader-variable properties.

### `DefaultValue`

Type: **[LPVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The default value for initializing the variable.

### `StartTexture`

Type: **UINT**

Offset from the start of the variable to the beginning of the texture.

### `TextureSize`

Type: **UINT**

The size of the texture, in bytes.

### `StartSampler`

Type: **UINT**

Offset from the start of the variable to the beginning of the sampler.

### `SamplerSize`

Type: **UINT**

The size of the sampler, in bytes.

## Remarks

Get a shader-variable description using reflection by calling [ID3D11ShaderReflectionVariable::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflectionvariable-getdesc).

As of the June 2010 update, **DefaultValue** emits default values for reflection.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)