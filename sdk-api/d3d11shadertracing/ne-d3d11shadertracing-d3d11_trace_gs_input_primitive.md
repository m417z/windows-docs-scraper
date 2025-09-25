# D3D11_TRACE_GS_INPUT_PRIMITIVE enumeration

## Description

Identifies the type of geometry shader input primitive.

## Constants

### `D3D11_TRACE_GS_INPUT_PRIMITIVE_UNDEFINED:0`

Identifies the geometry shader input primitive as undefined.

### `D3D11_TRACE_GS_INPUT_PRIMITIVE_POINT:1`

Identifies the geometry shader input primitive as a point.

### `D3D11_TRACE_GS_INPUT_PRIMITIVE_LINE:2`

Identifies the geometry shader input primitive as a line.

### `D3D11_TRACE_GS_INPUT_PRIMITIVE_TRIANGLE:3`

Identifies the geometry shader input primitive as a triangle.

### `D3D11_TRACE_GS_INPUT_PRIMITIVE_LINE_ADJ:6`

Identifies the geometry shader input primitive as an adjacent line.

### `D3D11_TRACE_GS_INPUT_PRIMITIVE_TRIANGLE_ADJ:7`

Identifies the geometry shader input primitive as an adjacent triangle.

## Remarks

**D3D11_TRACE_GS_INPUT_PRIMITIVE** identifies the type of geometry shader input primitive in a [D3D11_TRACE_STATS](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_stats) structure.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-enums)