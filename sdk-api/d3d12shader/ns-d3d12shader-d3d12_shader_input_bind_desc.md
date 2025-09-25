# D3D12_SHADER_INPUT_BIND_DESC structure

## Description

Describes how a shader resource is bound to a shader input.

## Members

### `Name`

Name of the shader resource.

### `Type`

A [D3D_SHADER_INPUT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_type)-typed value that identifies the type of data in the resource.

### `BindPoint`

Starting bind point.

### `BindCount`

Number of contiguous bind points for arrays.

### `uFlags`

A combination of [D3D_SHADER_INPUT_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_flags)-typed values for shader input-parameter options.

### `ReturnType`

If the input is a texture, the [D3D_RESOURCE_RETURN_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_resource_return_type)-typed value that identifies the return type.

### `Dimension`

A [D3D_SRV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_srv_dimension)-typed value that identifies the dimensions of the bound resource.

### `NumSamples`

The number of samples for a multisampled texture; when a texture isn't multisampled, the value is set to -1 (0xFFFFFFFF).
This is zero if the shader resource is not a recognized texture.
If the shader resource is a structured buffer, the field contains the stride of the type in bytes.

### `Space`

The register space.

### `uID`

The range ID in the bytecode.

## Remarks

Get a shader-input-signature description by calling [ID3D12ShaderReflection::GetResourceBindingDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflection-getresourcebindingdesc) or [ID3D12ShaderReflection::GetResourceBindingDescByName](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflection-getresourcebindingdescbyname).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)