## Description

A driver's **PFND3D12DDI_BARRIER_0094** (**pfnBarrier**) callback function synchronizes multiple accesses to resources. This callback supports enhanced barriers.

## Parameters

### `hDrvCommandList`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `NumBarriers`

The number of [**D3D12DDIARG_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0094) structures that **pBarriers** points to.

### `pBarriers`

Pointer to an array of [**D3D12DDIARG_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0094) structures that contain the enhanced barriers. The array size is specified by **NumBarriers**.

## Remarks

Drivers that [report support for enhanced barriers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0089) must implement this function. How drivers implement the function is up to the hardware vendor, as long as they meet the design specifications and pass all related conformance tests.

A driver supporting enhanced barriers must expect that legacy ResourceBarrier calls will also use the **pfnBarrier** function. The legacy PFND3D12DDI_RESOURCEBARRIER_* (**pfnResourceBarrier**) table entry can be left as NULL.

Access **pfnBarrier** by using a command list functions structure such as [**D3D12DDI_COMMAND_LIST_FUNCS_3D_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_command_list_funcs_3d_0094).

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDI_COMMAND_LIST_FUNCS_3D_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_command_list_funcs_3d_0094)

[**D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_DECODE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_command_list_funcs_video_decode_0088)

[**D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_ENCODE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_command_list_funcs_video_encode_0088)

[**D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_PROCESS_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_command_list_funcs_video_process_0088)

[**D3D12DDI_D3D12_OPTIONS_DATA_0089**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0089)

[**D3D12DDIARG_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0094)