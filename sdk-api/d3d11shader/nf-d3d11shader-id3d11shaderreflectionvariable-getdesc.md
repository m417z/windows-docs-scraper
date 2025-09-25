# ID3D11ShaderReflectionVariable::GetDesc

## Description

Get a shader-variable description.

## Parameters

### `pDesc` [out]

Type: **[D3D11_SHADER_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_variable_desc)***

A pointer to a shader-variable description (see [D3D11_SHADER_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_variable_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This method can be used to determine if the [ID3D11ShaderReflectionVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionvariable) is valid, the method returns **E_FAIL** when the variable is not valid.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D11ShaderReflectionVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionvariable)