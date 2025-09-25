# D3DDDICAPS_SHADER_MIN_PRECISION_SUPPORT structure

## Description

Describes precision support options for shaders in the user-mode display driver.

## Members

### `VertexShaderMinPrecision`

A combination of values of type [D3DDDICAPS_SHADER_MIN_PRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddicaps_shader_min_precision) that are combined by using a bitwise OR operation. The resulting value specifies minimum precision levels that the driver supports for the vertex shader. A value of zero indicates that the driver supports only the default precision for the shader model, and not a lower precision.

### `PixelShaderMinPrecision`

A combination of values of type [D3DDDICAPS_SHADER_MIN_PRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddicaps_shader_min_precision) that are combined by using a bitwise OR operation. The resulting value specifies minimum precision levels that the driver supports for the pixel shader. A value of zero indicates that the driver supports only the default precision for the shader model, and not a lower precision.

## See also

[D3DDDICAPS_SHADER_MIN_PRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddicaps_shader_min_precision)