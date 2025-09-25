# D3D12DDIARG_RENDER_PASS_DEPTH_STENCIL_DESC_0053 structure

## Description

Describes the Render Pass depth-stencil state.

## Members

### `cpuDescriptor`

The [D3D12DDI_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_cpu_descriptor_handle) structure that defines the depth buffer bindings.

### `DepthBeginningAccess`

A [D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_0053) structure that specifies the access mode for the depth, when a Render Pass is beginning.

### `StencilBeginningAccess`

A [D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_0053) structure that specifies the access mode for the stencil, when a Render Pass is beginning.

### `DepthEndingAccess`

A [D3D12DDI_RENDER_PASS_ENDING_ACCESS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_0053) structure that specifies the access mode for the depth, when a Render Pass is ending.

### `StencilEndingAccess`

A [D3D12DDI_RENDER_PASS_ENDING_ACCESS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_0053) structure that specifies the access mode for the stencil, when a Render Pass is ending.

## Remarks

## See also