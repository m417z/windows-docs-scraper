# ID3D10ShaderReflection::GetConstantBufferByIndex

## Description

Get a constant buffer by index.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index.

## Return value

Type: **[ID3D10ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nn-d3d10shader-id3d10shaderreflectionconstantbuffer)***

A pointer to a constant buffer (see [ID3D10ShaderReflectionConstantBuffer Interface](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nn-d3d10shader-id3d10shaderreflectionconstantbuffer)).

## Remarks

A constant buffer supplies either scalar constants or texture constants to a shader. A shader can use one or more constant buffers. For best performance, separate constants into buffers based on the frequency they are updated.

## See also

[ID3D10ShaderReflection Interface](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nn-d3d10shader-id3d10shaderreflection)