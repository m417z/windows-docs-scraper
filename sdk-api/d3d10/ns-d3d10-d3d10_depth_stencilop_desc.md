# D3D10_DEPTH_STENCILOP_DESC structure

## Description

Describes the stencil operations that can be performed based on the results of [stencil test](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

## Members

### `StencilFailOp`

Type: **[D3D10_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_stencil_op)**

A member of the [D3D10_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_stencil_op) enumerated type that describes the stencil operation to perform when stencil testing fails. The default value is **D3D10_STENCIL_OP_KEEP**.

### `StencilDepthFailOp`

Type: **[D3D10_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_stencil_op)**

A member of the [D3D10_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_stencil_op) enumerated type that describes the stencil operation to perform when stencil testing passes and depth testing fails. The default value is **D3D10_STENCIL_OP_KEEP**.

### `StencilPassOp`

Type: **[D3D10_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_stencil_op)**

A member of the [D3D10_STENCIL_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_stencil_op) enumerated type that describes the stencil operation to perform when stencil testing and depth testing both pass. The default value is **D3D10_STENCIL_OP_KEEP**.

### `StencilFunc`

Type: **[D3D10_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_comparison_func)**

A member of the [D3D10_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_comparison_func) enumerated type that describes how stencil data is compared against existing stencil data. The default value is **D3D10_COMPARISON_ALWAYS**.

## Remarks

The stencil operation can be set differently based on the outcome of the stencil test by using the **StencilFunc** member. This can be done for the [stencil test](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) portion of depth-stencil testing.

The D3D10_DEPTH_STENCILOP_DESC structure is a member of the [D3D10_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_desc) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)