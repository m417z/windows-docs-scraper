# D3D12DDI_DEPTH_STENCILOP_DESC structure

## Description

The D3D12DDI_DEPTH_STENCILOP_DESC structure describes stencil operations that can be performed based on the results of stencil test.

## Members

### `StencilFailOp`

A [D3D12DDI_STENCIL_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_stencil_op)-typed value that indicates the operation to perform if the stencil test fails.

### `StencilDepthFailOp`

A [D3D12DDI_STENCIL_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_stencil_op)-typed value that indicates the operation to perform if the stencil test passes and the depth test fails.

### `StencilPassOp`

A [D3D12DDI_STENCIL_OP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_stencil_op)-typed value that indicates the operation to perform if both stencil and depth tests pass.

### `StencilFunc`

A [D3D12DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_comparison_func)-typed value that indicates the stencil-comparison function to perform.

## Remarks

## See also