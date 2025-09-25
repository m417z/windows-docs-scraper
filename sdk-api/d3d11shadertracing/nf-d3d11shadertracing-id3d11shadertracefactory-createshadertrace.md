# ID3D11ShaderTraceFactory::CreateShaderTrace

## Description

Creates a shader-trace interface for a shader-trace information object.

## Parameters

### `pShader` [in]

A pointer to the interface of the shader to create the shader-trace interface for. For example, *pShader* can be an instance of [ID3D11VertexShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11vertexshader), [ID3D11PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11pixelshader), and so on.

### `pTraceDesc` [in]

A pointer to a [D3D11_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_shader_trace_desc) structure that describes the shader-trace object to create. This parameter cannot be **NULL**.

### `ppShaderTrace` [out]

A pointer to a variable that receives a pointer to the [ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace) interface for the shader-trace object that **CreateShaderTrace** creates.

## Return value

**CreateShaderTrace** returns:

* **S_OK** if the method created the shader-trace information object.
* **E_FAIL** if the reference device, which supports tracing, is not being used.
* **E_OUTOFMEMORY** if memory is unavailable to complete the operation.
* **E_INVALIDARG** if any parameter is NULL or invalid.
* Possibly other error codes that are described in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTraceFactory](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertracefactory)