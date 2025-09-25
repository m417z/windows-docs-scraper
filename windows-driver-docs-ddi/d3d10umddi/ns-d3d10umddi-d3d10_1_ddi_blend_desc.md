# D3D10_1_DDI_BLEND_DESC structure

## Description

The D3D10_1_DDI_BLEND_DESC structure describes a blend state.

## Members

### `AlphaToCoverageEnable` [in]

A Boolean value that specifies whether transparency coverage is enabled. **TRUE** indicates transparency coverage is enabled; **FALSE** indicates transparency coverage is disabled. This member is relevant for multiple-sample antialiasing only.

### `IndependentBlendEnable` [in]

A Boolean value that specifies only whether the [CalcPrivateBlendStateSize(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_calcprivateblendstatesize) function replicated the first entry in the array that the **RenderTarget** member specifies to the other entries of that array. **TRUE** indicates the first entry was not replicated; **FALSE** indicates that the first entry in the array in the **RenderTarget** member is replicated to the other entries of the array.

### `RenderTarget` [in]

An array of [D3D10_DDI_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_render_target_blend_desc1) structures that indicate the blend state for each associated render target.

## See also

[CalcPrivateBlendStateSize(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_calcprivateblendstatesize)

[CreateBlendState(D3D10_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_createblendstate)

[D3D10_DDI_BLEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)

[D3D10_DDI_BLEND_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)

[D3D10_DDI_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_render_target_blend_desc1)