# ID3D12ShaderReflectionVariable::GetDesc

## Description

Gets a shader-variable description.

## Parameters

### `pDesc` [out]

Type: **[D3D12_SHADER_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12shader/ns-d3d12shader-d3d12_shader_variable_desc)***

A pointer to a shader-variable description (see [D3D12_SHADER_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12shader/ns-d3d12shader-d3d12_shader_variable_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This method can be used to determine if the [ID3D12ShaderReflectionVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectionvariable) is valid, the method returns **E_FAIL** when the variable is not valid.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflectionVariable](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectionvariable)