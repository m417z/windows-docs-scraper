# D3D_TESSELLATOR_OUTPUT_PRIMITIVE enumeration

## Description

Output primitive types.

## Constants

### `D3D_TESSELLATOR_OUTPUT_UNDEFINED:0`

### `D3D_TESSELLATOR_OUTPUT_POINT:1`

### `D3D_TESSELLATOR_OUTPUT_LINE:2`

### `D3D_TESSELLATOR_OUTPUT_TRIANGLE_CW:3`

### `D3D_TESSELLATOR_OUTPUT_TRIANGLE_CCW:4`

### `D3D11_TESSELLATOR_OUTPUT_UNDEFINED`

The output primitive type is undefined.

### `D3D11_TESSELLATOR_OUTPUT_POINT`

The output primitive type is a point.

### `D3D11_TESSELLATOR_OUTPUT_LINE`

The output primitive type is a line.

### `D3D11_TESSELLATOR_OUTPUT_TRIANGLE_CW`

The output primitive type is a clockwise triangle.

### `D3D11_TESSELLATOR_OUTPUT_TRIANGLE_CCW`

The output primitive type is a counter clockwise triangle.

## Remarks

The output primitive type determines how the tessellator output data is organized; this enumeration is used by [D3D11_SHADER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_desc).

The **D3D11_TESSELLATOR_OUTPUT_PRIMITIVE** enumeration is type defined in the D3D11Shader.h header file as a [D3D_TESSELLATOR_OUTPUT_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_output_primitive) enumeration, which is fully defined in the D3DCommon.h header file.

```

typedef D3D_TESSELLATOR_OUTPUT_PRIMITIVE D3D11_TESSELLATOR_OUTPUT_PRIMITIVE;
```

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-enums)