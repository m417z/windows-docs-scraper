# D3D11_1_DDI_BLEND_DESC structure

## Description

 Describes a blend state. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Members

### `AlphaToCoverageEnable` [in]

A Boolean value that specifies whether transparency coverage is enabled. **TRUE** indicates transparency coverage is enabled; **FALSE** indicates transparency coverage is disabled. This member is relevant for multiple-sample antialiasing only.

### `IndependentBlendEnable` [in]

A Boolean value that specifies only whether the [CalcPrivateBlendStateSize(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivateblendstatesize) function replicated the first entry in the array that the **RenderTarget** member specifies to the other entries of that array. **TRUE** indicates the first entry was not replicated; **FALSE** indicates that the first entry in the array in the **RenderTarget** member is replicated to the other entries of the array.

### `RenderTarget` [in]

An array of [D3D11_1_DDI_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1_ddi_render_target_blend_desc) structures that indicate the blend state for each associated render target.

## See also

[CalcPrivateBlendStateSize(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivateblendstatesize)

[CreateBlendState(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createblendstate)

[D3D11_1_DDI_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1_ddi_render_target_blend_desc)