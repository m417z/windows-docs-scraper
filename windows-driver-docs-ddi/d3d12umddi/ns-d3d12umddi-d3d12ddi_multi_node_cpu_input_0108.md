## Description

The **D3D12DDI_MULTI_NODE_CPU_INPUT_0108** structure describes the input data for multiple nodes within a work graph where the input is provided by the CPU.

## Members

### `NumNodeInputs`

The number of entries in the array that **pNodeInputs** points to.

### `pNodeInputs`

Pointer to an array of [**D3D12DDI_NODE_CPU_INPUT_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_cpu_input_0108) structures.

### `NodeInputStrideInBytes`

Distance between each **D3D12DDI_NODE_CPU_INPUT_0108** structure in the array that **pNodeInputs** points to, in bytes.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_DISPATCH_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_dispatch_graph_desc_0108)

[**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108)