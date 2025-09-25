# D3D12_SHADER_BUFFER_DESC structure

## Description

Describes a shader constant-buffer.

## Members

### `Name`

The name of the buffer.

### `Type`

A [D3D_CBUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_cbuffer_type)-typed value that indicates the intended use of the constant data.

### `Variables`

The number of unique variables.

### `Size`

The size of the buffer, in bytes.

### `uFlags`

A combination of [D3D_SHADER_CBUFFER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_cbuffer_flags)-typed values that are combined by using a bitwise OR operation. The resulting value specifies properties for the shader constant-buffer.

## Remarks

Constants are supplied to shaders in a shader-constant buffer. Get the description of a shader-constant-buffer by calling [ID3D12ShaderReflectionConstantBuffer::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflectionconstantbuffer-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)