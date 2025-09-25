# D3D11_SHADER_BUFFER_DESC structure

## Description

Describes a shader constant-buffer.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the buffer.

### `Type`

Type: **[D3D_CBUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_cbuffer_type)**

A [D3D_CBUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_cbuffer_type)-typed value that indicates the intended use of the constant data.

### `Variables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of unique variables.

### `Size`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Buffer size (in bytes).

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D_SHADER_CBUFFER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_cbuffer_flags)-typed values that are combined by using a bitwise OR operation. The resulting value specifies properties for the shader constant-buffer.

## Remarks

Constants are supplied to shaders in a shader-constant buffer. Get the description of a shader-constant-buffer by calling [ID3D11ShaderReflectionConstantBuffer::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflectionconstantbuffer-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)