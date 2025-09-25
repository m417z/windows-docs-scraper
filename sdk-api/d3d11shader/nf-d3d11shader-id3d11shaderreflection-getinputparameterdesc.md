# ID3D11ShaderReflection::GetInputParameterDesc

## Description

Get an input-parameter description for a shader.

## Parameters

### `ParameterIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based parameter index.

### `pDesc` [out]

Type: **[D3D11_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_signature_parameter_desc)***

A pointer to a shader-input-signature description. See [D3D11_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_signature_parameter_desc).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

An input-parameter description is also called a shader signature. The shader signature contains information about the input parameters such as the order or parameters, their data type, and a parameter semantic.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D11ShaderReflection Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection)