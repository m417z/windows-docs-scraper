# ID3D11ShaderReflectionType::IsEqual

## Description

Indicates whether two [ID3D11ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectiontype) pointers have the same underlying type.

## Parameters

### `pType` [in]

Type: **[ID3D11ShaderReflectionType](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectiontype)***

A pointer to a [ID3D11ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectiontype).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if the pointers have the same underlying type; otherwise returns S_FALSE.

## Remarks

IsEqual indicates whether the sources of the [ID3D11ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectiontype) pointers have the same underlying type.
For example, if two **ID3D11ShaderReflectionType Interface** pointers were retrieved from variables, IsEqual can be used to see if
the variables have the same type.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D11ShaderReflectionType Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectiontype)