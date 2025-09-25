# ID3D10ShaderReflection::GetResourceBindingDesc

## Description

Get a description of the resources bound to a shader.

## Parameters

### `ResourceIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based resource index.

### `pDesc` [in]

Type: **[D3D10_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_shader_input_bind_desc)***

A pointer to an input-binding description. See [D3D10_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_shader_input_bind_desc).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

A shader consists of executable code (the compiled HLSL functions) and a set of resources that supply the shader with input data. This API gets a list of the resources that are bound as inputs to the shader.

## See also

[ID3D10ShaderReflection Interface](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nn-d3d10shader-id3d10shaderreflection)