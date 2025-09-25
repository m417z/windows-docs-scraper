## Description

The **D3D12DDI_DISPATCH_MODE_0108** enumeration identifies a work graph's dispatch mode and which union member in [**D3D12DDI_DISPATCH_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_dispatch_graph_desc_0108) to use.

## Constants

### `D3D12DDI_DISPATCH_MODE_NODE_CPU_INPUT_0108`

The dispatch is a single node configured from the CPU. Use the **NodeCPUInput** union member.

### `D3D12DDI_DISPATCH_MODE_NODE_GPU_INPUT_0108`

The dispatch is a single node configured from the GPU. Use the **NodeGPUInput** union member.

### `D3D12DDI_DISPATCH_MODE_MULTI_NODE_CPU_INPUT_0108`

The dispatch is a multi-node configured from the CPU. Use the **MultiNodeCPUInput** union member.

### `D3D12DDI_DISPATCH_MODE_MULTI_NODE_GPU_INPUT_0108`

The dispatch is a multi-node configured from the GPU. Use the **MultiNodeGPUInput** union member.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_DISPATCH_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_dispatch_graph_desc_0108)

[**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108)