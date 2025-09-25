# D3D10_DDI_BLEND_DESC structure

## Description

The **D3D10_DDI_BLEND_DESC** structure describes a blend state.

## Members

### `AlphaToCoverageEnable` [in]

A Boolean value that specifies whether transparency coverage is enabled. **TRUE** indicates transparency coverage is enabled; **FALSE** indicates transparency coverage is disabled. This member is relevant for multiple-sample antialiasing only.

### `BlendEnable` [in]

An array of Boolean values that specify whether blending is enabled for each associated render target. **TRUE** indicates blending is enabled; **FALSE** indicates blending is disabled.

### `SrcBlend` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the blend mode of the source for all enabled render targets.

### `DestBlend` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the blend mode of the destination for all enabled render targets.

### `BlendOp` [in]

A [**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)-typed value that indicates the blending operation for all enabled render targets.

### `SrcBlendAlpha` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the transparency blend mode of the source for all enabled render targets.

### `DestBlendAlpha` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the transparency blend mode of the destination for all enabled render targets.

### `BlendOpAlpha` [in]

A [**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)-typed value that indicates the transparency blending operation for all enabled render targets.

### `RenderTargetWriteMask` [in]

An array of 8-bit bitwise values that indicate the write properties for each associated render target. Each bit of each element must be set to one of the following values from the D3D10_DDI_COLOR_WRITE_ENABLE enumeration.

|Value|Meaning|
|--- |--- |
|D3D10_DDI_COLOR_WRITE_ENABLE_RED (1) |Writes red|
|D3D10_DDI_COLOR_WRITE_ENABLE_GREEN (2) |Writes green|
|D3D10_DDI_COLOR_WRITE_ENABLE_BLUE (4) |Writes blue|
|D3D10_DDI_COLOR_WRITE_ENABLE_ALPHA (8) |Writes a transparency level|
|D3D10_DDI_COLOR_WRITE_ENABLE_ALL (bitwise OR of 1,2,4,8)|Writes red, green, blue, and a transparency level|

## See also

[**CalcPrivateBlendStateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateblendstatesize)

[**CreateBlendState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createblendstate)

[**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)

[**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)