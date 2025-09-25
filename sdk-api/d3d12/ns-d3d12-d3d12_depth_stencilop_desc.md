# D3D12_DEPTH_STENCILOP_DESC structure

## Description

Describes stencil operations that can be performed based on the results of stencil test.

## Members

### `StencilFailOp`

A [D3D12_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op)-typed value that identifies the stencil operation to perform when stencil testing fails.

### `StencilDepthFailOp`

A [D3D12_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op)-typed value that identifies the stencil operation to perform when stencil testing passes and depth testing fails.

### `StencilPassOp`

A [D3D12_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op)-typed value that identifies the stencil operation to perform when stencil testing and depth testing both pass.

### `StencilFunc`

A [D3D12_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func)-typed value that identifies the function that compares stencil data against existing stencil data.

## Remarks

All stencil operations are specified as a [D3D12_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op)-typed value. Each stencil operation can be set differently based on the outcome of the stencil test, which is referred to as **StencilFunc**, in the stencil test portion of depth-stencil testing.

Members of [D3D12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc) have this structure for their data type.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)