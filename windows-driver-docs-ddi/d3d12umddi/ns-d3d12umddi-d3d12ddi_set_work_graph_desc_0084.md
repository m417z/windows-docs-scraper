## Description

A **D3D12DDI_SET_WORK_GRAPH_DESC_0084** structure describes a work graph to set when the **Type** field of a [**D3D12DDI_SET_PROGRAM_DESC_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_program_desc_0108) structure is **D3D12DDI_PROGRAM_TYPE_WORK_GRAPH_0084**.

## Members

### `ProgramIdentifier`

A [**D3D12DDI_PROGRAM_IDENTIFIER_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_program_identifier_0108) structure that identifies the program to set.

### `Flags`

A [**D3D12DDI_SET_WORK_GRAPH_FLAGS_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_set_work_graph_flags_0084) enumeration that specifies flags for setting the work graph.

### `BackingMemory`

A [**D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_gpu_virtual_address_range) structure that specifies the backing memory for the work graph. The address must be 8-byte aligned.

### `NodeLocalRootArgumentsTable`

A [**D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_gpu_virtual_address_range) structure that specifies the node-local root arguments table for the work graph. The address must be 8-byte aligned.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_SET_PROGRAM_DESC_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_program_desc_0108)

[**PFND3D12DDI_SET_PROGRAM_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_program_0084)