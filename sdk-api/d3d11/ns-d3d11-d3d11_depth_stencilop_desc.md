# D3D11_DEPTH_STENCILOP_DESC structure

## Description

Stencil operations that can be performed based on the results of stencil test.

## Members

### `StencilFailOp`

Type: **[D3D11_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_stencil_op)**

The stencil operation to perform when stencil testing fails.

### `StencilDepthFailOp`

Type: **[D3D11_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_stencil_op)**

The stencil operation to perform when stencil testing passes and depth testing fails.

### `StencilPassOp`

Type: **[D3D11_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_stencil_op)**

The stencil operation to perform when stencil testing and depth testing both pass.

### `StencilFunc`

Type: **[D3D11_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_comparison_func)**

A function that compares stencil data against existing stencil data. The function options are listed in [D3D11_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_comparison_func).

## Remarks

All stencil operations are specified as a [D3D11_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_stencil_op). The stencil operation can be set differently based on the outcome of the stencil test (which is referred to as **StencilFunc** in the stencil test portion of depth-stencil testing.

This structure is a member of a [depth-stencil description](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_desc).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)