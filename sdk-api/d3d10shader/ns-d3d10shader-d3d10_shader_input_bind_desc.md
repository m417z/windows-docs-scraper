# D3D10_SHADER_INPUT_BIND_DESC structure

## Description

Describes how a shader resource is bound to a shader input.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the shader resource.

### `Type`

Type: **[D3D10_SHADER_INPUT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_type)**

Identifies the type of data in the resource. See [D3D10_SHADER_INPUT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_type).

### `BindPoint`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Starting bind point.

### `BindCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of contiguous bind points for arrays.

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader input-parameter options. See [D3D10_SHADER_INPUT_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_flags).

### `ReturnType`

Type: **[D3D10_RESOURCE_RETURN_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_resource_return_type)**

If the input is a texture, the return type. See [D3D10_RESOURCE_RETURN_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_resource_return_type).

### `Dimension`

Type: **[D3D10_SRV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_buffer_srv)**

Identifies the amount of data in the resource. See [D3D10_SRV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_buffer_srv).

### `NumSamples`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of samples for a multisampled texture; otherwise 0.

## Remarks

Get a shader-input-signature description by calling [ID3D10ShaderReflection::GetResourceBindingDesc](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-id3d10shaderreflection-getresourcebindingdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)