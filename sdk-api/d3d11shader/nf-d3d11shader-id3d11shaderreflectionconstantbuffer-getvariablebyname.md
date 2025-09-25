# ID3D11ShaderReflectionConstantBuffer::GetVariableByName

## Description

Get a shader-reflection variable by name.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Variable name.

## Return value

Type: **[ID3D11ShaderReflectionVariable](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionvariable)***

Returns a sentinel object (end of list marker). To determine if GetVariableByName successfully completed, call [ID3D11ShaderReflectionVariable::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflectionvariable-getdesc) and check the returned **HRESULT**; any return value other than success means that GetVariableByName failed.

## Remarks

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D11ShaderReflectionConstantBuffer Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer)