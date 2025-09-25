# ID3D12ShaderReflectionType::IsOfType

## Description

Indicates whether a variable is of the specified type.

## Parameters

### `pType` [in]

Type: **[ID3D12ShaderReflectionType](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype)***

A pointer to a [ID3D12ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if object being queried is equal to or inherits from the type in the *pType* parameter; otherwise returns S_FALSE.

## Remarks

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflectionType](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectiontype)