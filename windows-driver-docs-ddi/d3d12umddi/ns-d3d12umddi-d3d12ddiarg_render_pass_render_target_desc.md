# D3D12DDIARG_RENDER_PASS_RENDER_TARGET_DESC structure

## Description

Describes the Render Target. This is declared at the start of a Render Pass.

## Members

### `cpuDescriptor`

The [D3D12DDI_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_cpu_descriptor_handle) structure that defines the Render Target.

### `BeginningAccess`

A [D3D12DDI_RENDER_PASS_BEGINNING_ACCESS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_beginning_access_0053) structure that specifies the Render Target, when a Render Pass is beginning.

### `EndingAccess`

A [D3D12DDI_RENDER_PASS_ENDING_ACCESS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_0053) structure that specifies the Render Target, when a Render Pass is ending.

## Remarks

## See also