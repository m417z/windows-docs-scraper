## Description

The **D3D12DDI_DISPATCH_GRAPH_DESC_0108** structure is the input parameter for [**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108). It describes the work graph to dispatch.

## Members

### `Mode`

A [**D3D12DDI_DISPATCH_MODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_dispatch_mode_0108) enumeration that specifies the work graph's mode and which entry in the union to use.

### `NodeCPUInput`

The [**D3D12DDI_NODE_CPU_INPUT_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_cpu_input_0108) structure to use when **Mode** is **D3D12DDI_DISPATCH_MODE_NODE_CPU_INPUT_0108**.

### `NodeGPUInput`

A **D3D12DDI_GPU_VIRTUAL_ADDRESS** to use when **Mode** is **D3D12DDI_DISPATCH_MODE_NODE_GPU_INPUT_0108**.

### `MultiNodeCPUInput`

A [**D3D12DDI_MULTI_NODE_CPU_INPUT_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_multi_node_cpu_input_0108) structure to use when **Mode** is **D3D12DDI_DISPATCH_MODE_MULTI_NODE_CPU_INPUT_0108**.

### `MultiNodeGPUInput`

A **D3D12DDI_GPU_VIRTUAL_ADDRESS** to use when **Mode** is **D3D12DDI_DISPATCH_MODE_MULTI_NODE_GPU_INPUT_0108**.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_DISPATCH_MODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_dispatch_mode_0108)

[**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108)