# ID3D11FunctionReflection::GetConstantBufferByName

## Description

Gets a constant buffer by name for a function.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The constant-buffer name.

## Return value

Type: **[ID3D11ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer)***

A pointer to a [ID3D11ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer) interface that represents the constant buffer.

## Remarks

A constant buffer supplies either scalar constants or texture constants to a shader. A shader can use one or more constant buffers. For best performance, separate constants into buffers based on the frequency they are updated.

## See also

[ID3D11FunctionReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionreflection)