# ID3D12ShaderReflection::GetPatchConstantParameterDesc

## Description

Gets a patch-constant parameter description for a shader.

## Parameters

### `ParameterIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based parameter index.

### `pDesc` [out]

Type: **[D3D12_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12shader/ns-d3d12shader-d3d12_signature_parameter_desc)***

A pointer to a shader-input-signature description. See [D3D12_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12shader/ns-d3d12shader-d3d12_signature_parameter_desc).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflection)