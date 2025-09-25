# ID3D12ShaderReflectionType::IsEqual

## Description

Indicates whether two [ID3D12ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype) pointers have the same underlying type.

## Parameters

### `pType` [in]

Type: **[ID3D12ShaderReflectionType](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype)***

A pointer to a [ID3D12ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if the pointers have the same underlying type; otherwise returns S_FALSE.

## Remarks

IsEqual indicates whether the sources of the [ID3D12ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype) pointers have the same underlying type.
For example, if two **ID3D12ShaderReflectionType Interface** pointers were retrieved from variables, IsEqual can be used to see if
the variables have the same type.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflectionType](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype)