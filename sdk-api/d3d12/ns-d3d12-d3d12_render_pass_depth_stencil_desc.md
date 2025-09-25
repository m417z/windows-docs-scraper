# D3D12_RENDER_PASS_DEPTH_STENCIL_DESC structure

## Description

Describes a binding (fixed for the duration of the render pass) to a depth stencil view (DSV), as well as its beginning and ending access characteristics.

## Members

### `cpuDescriptor`

A [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle). The CPU descriptor handle corresponding to the depth stencil view (DSV).

### `DepthBeginningAccess`

A [D3D12_RENDER_PASS_BEGINNING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_beginning_access). The access to the depth buffer requested at the transition into a render pass.

### `StencilBeginningAccess`

A [D3D12_RENDER_PASS_BEGINNING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_beginning_access). The access to the stencil buffer requested at the transition into a render pass.

### `DepthEndingAccess`

A [D3D12_RENDER_PASS_ENDING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_ending_access). The access to the depth buffer requested at the transition out of a render pass.

### `StencilEndingAccess`

A [D3D12_RENDER_PASS_ENDING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_ending_access). The access to the stencil buffer requested at the transition out of a render pass.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)