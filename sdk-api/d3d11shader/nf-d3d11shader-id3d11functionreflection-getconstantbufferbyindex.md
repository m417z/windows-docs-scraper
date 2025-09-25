# ID3D11FunctionReflection::GetConstantBufferByIndex

## Description

Gets a constant buffer by index for a function.

## Parameters

### `BufferIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index.

## Return value

Type: **[ID3D11ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer)***

A pointer to a [ID3D11ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer) interface that represents the constant buffer.

## Remarks

A constant buffer supplies either scalar constants or texture constants to a shader. A shader can use one or more constant buffers. For best performance, separate constants into buffers based on the frequency they are updated.

## See also

[ID3D11FunctionReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionreflection)