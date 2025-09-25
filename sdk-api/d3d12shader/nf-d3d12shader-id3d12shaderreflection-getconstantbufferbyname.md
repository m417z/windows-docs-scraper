# ID3D12ShaderReflection::GetConstantBufferByName

## Description

Gets a constant buffer by name.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The constant-buffer name.

## Return value

Type: **[ID3D12ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectionconstantbuffer)***

A pointer to a constant buffer (see [ID3D12ShaderReflectionConstantBuffer Interface](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflectionconstantbuffer)).

## Remarks

A constant buffer supplies either scalar constants or texture constants to a shader.
A shader can use one or more constant buffers.
For best performance, separate constants into buffers based on the frequency they are updated.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D12ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflection)