# D3D11_SHADER_INPUT_BIND_DESC structure

## Description

Describes how a shader resource is bound to a shader input.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the shader resource.

### `Type`

Type: **[D3D_SHADER_INPUT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_type)**

A [D3D_SHADER_INPUT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_type)-typed value that identifies the type of data in the resource.

### `BindPoint`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Starting bind point.

### `BindCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of contiguous bind points for arrays.

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D_SHADER_INPUT_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_input_flags)-typed values for shader input-parameter options.

### `ReturnType`

Type: **[D3D_RESOURCE_RETURN_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_resource_return_type)**

If the input is a texture, the [D3D_RESOURCE_RETURN_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_resource_return_type)-typed value that identifies the return type.

### `Dimension`

Type: **[D3D_SRV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_srv_dimension)**

A [D3D_SRV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_srv_dimension)-typed value that identifies the dimensions of the bound resource.

### `NumSamples`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of samples for a multisampled texture; when a texture isn't multisampled, the value is set to -1 (0xFFFFFFFF).

## Remarks

Get a shader-input-signature description by calling [ID3D11ShaderReflection::GetResourceBindingDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflection-getresourcebindingdesc) or [ID3D11ShaderReflection::GetResourceBindingDescByName](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflection-getresourcebindingdescbyname).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)