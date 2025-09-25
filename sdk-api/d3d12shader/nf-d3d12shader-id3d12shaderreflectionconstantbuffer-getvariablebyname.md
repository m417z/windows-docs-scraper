# ID3D12ShaderReflectionConstantBuffer::GetVariableByName

## Description

Gets a shader-reflection variable by name.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Variable name.

## Return value

Type: **[ID3D12ShaderReflectionVariable](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectionvariable)***

Returns a sentinel object (end of list marker). To determine if GetVariableByName successfully completed, call [ID3D12ShaderReflectionVariable::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflectionvariable-getdesc) and check the returned **HRESULT**; any return value other than success means that GetVariableByName failed.

## Remarks

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectionconstantbuffer)