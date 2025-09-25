# D3D11_DDI_SHADER_MIN_PRECISION_SUPPORT_DATA structure

## Description

Describes precision support options for shaders in the user-mode display driver.

## Members

### `PixelShaderMinPrecision`

A combination of values of type [D3D11_DDI_SHADER_MIN_PRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_shader_min_precision) that are combined by using a bitwise **OR** operation. The resulting value specifies minimum precision levels that the driver supports for the pixel shader. A value of zero indicates that the driver supports only the default precision for the shader model, and not a lower precision.

### `AllOtherStagesMinPrecision`

A combination of values of type [D3D11_DDI_SHADER_MIN_PRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_ddi_shader_min_precision) that are combined by using a bitwise **OR** operation. The resulting value specifies minimum precision levels that the driver supports for all other stages in the video processing pipeline that are not pixel shaders. A value of zero indicates that the driver supports only the default precision for the shader model, and not a lower precision.