# D3D12_RENDER_PASS_RENDER_TARGET_DESC structure

## Description

Describes bindings (fixed for the duration of the render pass) to one or more render target views (RTVs), as well as their beginning and ending access characteristics.

## Members

### `cpuDescriptor`

A [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle). The CPU descriptor handle corresponding to the render target view(s) (RTVs).

### `BeginningAccess`

A [D3D12_RENDER_PASS_BEGINNING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_beginning_access). The access to the RTV(s) requested at the transition into a render pass.

### `EndingAccess`

A [D3D12_RENDER_PASS_ENDING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_ending_access). The access to the RTV(s) requested at the transition out of a render pass.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)