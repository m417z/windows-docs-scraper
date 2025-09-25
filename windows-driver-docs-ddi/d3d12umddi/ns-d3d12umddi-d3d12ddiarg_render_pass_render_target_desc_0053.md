# D3D12DDIARG_RENDER_PASS_RENDER_TARGET_DESC_0053 structure

## Description

The **D3D12DDIARG_RENDER_PASS_RENDER_TARGET_DESC_0053** structure describes the bindings to one or more render target views (RTVs), as well as their beginning and ending access characteristics.

## Members

### `cpuDescriptor`

The [**D3D12DDI_CPU_DESCRIPTOR_HANDLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_cpu_descriptor_handle) structure that is the CPU descriptor handle corresponding to the render target view(s) (RTVs).

### `BeginningAccess`

A [**D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_0053) structure that identifies the requested access to the RTV(s) at the transition into a render pass.

### `EndingAccess`

A [**D3D12DDI_RENDER_PASS_ENDING_ACCESS_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_0053) structure that identifies the requested access to the RTV(s) at the transition out of a render pass.

## Remarks

This structure is declared at the start of a Render Pass.

For more information, see [D3D12 Render Passes](https://learn.microsoft.com/windows-hardware/drivers/display/d3d12-render-passes).

## See also

[**pfnBeginRenderPass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_render_pass_0053)