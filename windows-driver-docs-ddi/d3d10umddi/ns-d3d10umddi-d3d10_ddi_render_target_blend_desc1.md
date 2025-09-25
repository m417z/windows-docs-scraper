# D3D10_DDI_RENDER_TARGET_BLEND_DESC1 structure

## Description

The D3D10_DDI_RENDER_TARGET_BLEND_DESC1 structure describes a blend state for a render target.

## Members

### `BlendEnable` [in]

A Boolean value that specifies whether blending is enabled for the associated render target. **TRUE** indicates blending is enabled; **FALSE** indicates blending is disabled.

### `SrcBlend` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the blend mode of the source for the enabled render target.

### `DestBlend` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the blend mode of the destination for the enabled render target.

### `BlendOp` [in]

A [**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)-typed value that indicates the blending operation for the enabled render target.

### `SrcBlendAlpha` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the transparency blend mode of the source for the enabled render target.

### `DestBlendAlpha` [in]

A [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)-typed value that indicates the transparency blend mode of the destination for the enabled render target.

### `BlendOpAlpha` [in]

A [**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)-typed value that indicates the transparency blending operation for the enabled render target.

### `RenderTargetWriteMask` [in]

An 8-bit bitwise value that indicates the write properties for the enabled render target. Each bit must be set to one of the following values from the D3D10_DDI_COLOR_WRITE_ENABLE enumeration.

|Value|Meaning|
|--- |--- |
|D3D10_DDI_COLOR_WRITE_ENABLE_RED (1) |Writes red|
|D3D10_DDI_COLOR_WRITE_ENABLE_GREEN (2) |Writes green|
|D3D10_DDI_COLOR_WRITE_ENABLE_BLUE (4) |Writes blue|
|D3D10_DDI_COLOR_WRITE_ENABLE_ALPHA (8) |Writes a transparency level|
|D3D10_DDI_COLOR_WRITE_ENABLE_ALL (bitwise OR of 1,2,4,8) |Writes red, green, blue, and a transparency level|

## Remarks

An array of D3D10_DDI_RENDER_TARGET_BLEND_DESC1 structures are specified in the **RenderTarget** member of the [**D3D10_1_DDI_BLEND_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1_ddi_blend_desc) structure to describe a blend state.

## See also

[**CalcPrivateBlendStateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateblendstatesize)

[**CreateBlendState(D3D10_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_createblendstate)

[**D3D10_1_DDI_BLEND_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1_ddi_blend_desc)

[**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)

[**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)