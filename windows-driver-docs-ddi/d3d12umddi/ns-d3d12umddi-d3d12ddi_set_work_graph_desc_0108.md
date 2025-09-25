## Description

A **D3D12DDI_SET_WORK_GRAPH_DESC_0108** structure describes a work graph to set when the **Type** field of a [**D3D12DDI_SET_PROGRAM_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_program_desc_0108) structure is **D3D12DDI_PROGRAM_TYPE_WORK_GRAPH_0108**.

## Members

### `ProgramIdentifier`

A [**D3D12DDI_PROGRAM_IDENTIFIER_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_program_identifier_0108) structure that identifies the program to set.

### `Flags`

A [**D3D12DDI_SET_WORK_GRAPH_FLAGS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_set_work_graph_flags_0108) enumeration that specifies flags for setting the work graph.

### `BackingMemory`

A [**D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_gpu_virtual_address_range) structure that specifies the backing memory for the work graph. The address must be 8-byte aligned.

### `NodeLocalRootArgumentsTable`

A [**D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_gpu_virtual_address_range_and_stride) structure that specifies the location of the local root arguments table. See the members of [**D3D12DDI_SHADER_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_node_0108) in a work graph definition at the DDI indicating what the local root argument table index for a given node in a work graph is, if any.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_SET_PROGRAM_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_program_desc_0108)

[**PFND3D12DDI_SET_PROGRAM_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_program_0108)