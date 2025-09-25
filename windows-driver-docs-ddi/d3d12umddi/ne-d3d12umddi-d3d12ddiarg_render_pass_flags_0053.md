# D3D12DDIARG_RENDER_PASS_FLAGS_0053 enumeration

## Description

The **D3D12DDIARG_RENDER_PASS_FLAGS_0053** enumeration is a bitwise OR of flags that indicate the state of a render pass.

## Constants

### `D3D12DDI_RENDER_PASS_FLAG_0053_NONE:0x0`

No flags are specified.

### `D3D12DDI_RENDER_PASS_FLAG_0053_ALLOW_UAV_WRITES:0x1`

Used to specify whether the user will be issuing UAV writes within the render pass, allowing UMDs (user mode drivers) to opt out of tiling if necessary.

### `D3D12DDI_RENDER_PASS_FLAG_0053_SUSPENDING_PASS:0x2`

This render pass is suspending.

### `D3D12DDI_RENDER_PASS_FLAG_0053_RESUMING_PASS:0x4`

This render pass is resuming.

### `D3D12DDI_RENDER_PASS_FLAG_0101_BIND_READ_ONLY_DEPTH:0x8`

A depth stencil view (DSV) should be bound as read-only for the depth aspect during the render pass. This flag is set when the depth data will be read by the GPU, such as for depth comparison in shadow mapping, but not written to during the pass. This flag can only be specified for a depth surface that was initialized before the current pass (by a previous pass or some other way).

### `D3D12DDI_RENDER_PASS_FLAG_0101_BIND_READ_ONLY_STENCIL:0x10`

The stencil aspect of a DSV should be bound as read-only during the render pass. This is useful when the stencil data is needed for read operations like stencil testing but will not be modified by the pass. This flag can only be specified for a stencil surface that was initialized before the current pass (by a previous pass or some other way).

## Remarks

A render pass can be both resuming and suspending.

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053)