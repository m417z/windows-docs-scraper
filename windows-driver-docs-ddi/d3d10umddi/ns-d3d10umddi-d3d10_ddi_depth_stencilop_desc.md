# D3D10_DDI_DEPTH_STENCILOP_DESC structure

## Description

The D3D10_DDI_DEPTH_STENCILOP_DESC structure describes a depth stencil operation.

## Members

### `StencilFailOp` [in]

A [D3D10_DDI_STENCIL_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_stencil_op)-typed value that indicates the operation to perform if the stencil test fails.

### `StencilDepthFailOp` [in]

A [D3D10_DDI_STENCIL_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_stencil_op)-typed value that indicates the operation to perform if the stencil test passes and the depth test fails.

### `StencilPassOp` [in]

A [D3D10_DDI_STENCIL_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_stencil_op)-typed value that indicates the operation to perform if both stencil and depth tests pass.

### `StencilFunc` [in]

A [D3D10_DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_comparison_func)-typed value that indicates the stencil-comparison function to perform.

## See also

[CalcPrivateDepthStencilStateSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilstatesize)

[CreateDepthStencilState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilstate)

[D3D10_DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_comparison_func)

[D3D10_DDI_STENCIL_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_stencil_op)