# D3D11_SHADER_TRACE_DESC structure

## Description

Describes a shader-trace object.

## Members

### `Type`

A [D3D11_SHADER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ne-d3d11shadertracing-d3d11_shader_type)-typed value that identifies the type of shader that the shader-trace object describes. This member also determines which shader-trace type to use in the following union.

### `Flags`

A combination of the following flags that are combined by using a bitwise **OR** operation. The resulting value specifies how [ID3D11ShaderTraceFactory::CreateShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertracefactory-createshadertrace) creates the shader-trace object.

| Flag | Description |
| --- | --- |
| D3D11_SHADER_TRACE_FLAG_RECORD_REGISTER_WRITES (0x1) | The shader trace object records register-writes. |
| D3D11_SHADER_TRACE_FLAG_RECORD_REGISTER_READS (0x2) | The shader trace object records register-reads. |

### `VertexShaderTraceDesc`

A [D3D11_VERTEX_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_vertex_shader_trace_desc) structure that describes an instance of a vertex shader to trace.

### `HullShaderTraceDesc`

A [D3D11_HULL_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_hull_shader_trace_desc) structure that describes an instance of a hull shader to trace.

### `DomainShaderTraceDesc`

A [D3D11_DOMAIN_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_domain_shader_trace_desc) structure that describes an instance of a domain shader to trace.

### `GeometryShaderTraceDesc`

A [D3D11_GEOMETRY_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_geometry_shader_trace_desc) structure that describes an instance of a geometry shader to trace.

### `PixelShaderTraceDesc`

A [D3D11_PIXEL_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_pixel_shader_trace_desc) structure that describes an instance of a pixel shader to trace.

### `ComputeShaderTraceDesc`

A [D3D11_COMPUTE_SHADER_TRACE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_compute_shader_trace_desc) structure that describes an instance of a compute shader to trace.

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTraceFactory::CreateShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertracefactory-createshadertrace)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)