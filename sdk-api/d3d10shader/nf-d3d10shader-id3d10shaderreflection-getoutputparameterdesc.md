# ID3D10ShaderReflection::GetOutputParameterDesc

## Description

Get an output-parameter description for a shader.

## Parameters

### `ParameterIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based parameter index.

### `pDesc` [in]

Type: **[D3D10_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_signature_parameter_desc)***

A pointer to a shader-output-parameter description. See [D3D10_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d10shader/ns-d3d10shader-d3d10_signature_parameter_desc).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An output-parameter description is also called a shader signature. The shader signature contains information about the output parameters such as the order or parameters, their data type, and a parameter semantic.

## See also

[ID3D10ShaderReflection Interface](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nn-d3d10shader-id3d10shaderreflection)