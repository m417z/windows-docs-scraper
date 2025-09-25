# ID3D11ShaderReflection::GetConstantBufferByIndex

## Description

Get a constant buffer by index.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index.

## Return value

Type: **[ID3D11ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer)***

A pointer to a constant buffer (see [ID3D11ShaderReflectionConstantBuffer Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer)).

## Remarks

A constant buffer supplies either scalar constants or texture constants to a shader. A shader can use one or more constant buffers. For best performance, separate constants into buffers based on the frequency they are updated.

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

## See also

[ID3D11ShaderReflection Interface](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection)