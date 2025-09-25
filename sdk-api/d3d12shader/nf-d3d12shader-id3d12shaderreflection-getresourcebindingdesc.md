# ID3D12ShaderReflection::GetResourceBindingDesc

## Description

Gets a description of how a resource is bound to a shader.

## Parameters

### `ResourceIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based resource index.

### `pDesc` [out]

Type: **[D3D12_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12shader/ns-d3d12shader-d3d12_shader_input_bind_desc)***

A pointer to an input-binding description. See [D3D12_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12shader/ns-d3d12shader-d3d12_shader_input_bind_desc).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

A shader consists of executable code (the compiled HLSL functions) and a set of resources that supply the shader with input data. **GetResourceBindingDesc** gets information about how one resource in the set is bound as an input to the shader. The *ResourceIndex* parameter specifies the index for the resource.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflection)