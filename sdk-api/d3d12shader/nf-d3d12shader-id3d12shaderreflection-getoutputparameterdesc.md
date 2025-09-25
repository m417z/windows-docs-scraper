# ID3D12ShaderReflection::GetOutputParameterDesc

## Description

Gets an output-parameter description for a shader.

## Parameters

### `ParameterIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based parameter index.

### `pDesc` [out]

Type: **[D3D12_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12shader/ns-d3d12shader-d3d12_signature_parameter_desc)***

A shader-output-parameter description, as a pointer to a [D3D12_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12shader/ns-d3d12shader-d3d12_signature_parameter_desc) structure.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

An output-parameter description is also called a shader signature. The shader signature contains information about the output parameters such as the order or parameters, their data type, and a parameter semantic.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflection)