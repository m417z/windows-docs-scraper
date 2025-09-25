# D3D10_SHADER_BUFFER_DESC structure

## Description

Describes a shader constant-buffer.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the buffer.

### `Type`

Type: **[D3D10_CBUFFER_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb204899(v=vs.85))**

The intended use of the constant data. See [D3D10_CBUFFER_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb204899(v=vs.85)).

### `Variables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of unique variables.

### `Size`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Buffer size (in bytes).

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader buffer properties. See [D3D10_SHADER_CBUFFER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_cbuffer_flags).

## Remarks

Constants are supplied to shaders in a shader-constant buffer. Get the description of a shader-constant-buffer by calling [ID3D10ShaderReflectionConstantBuffer::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-id3d10shaderreflectionconstantbuffer-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)