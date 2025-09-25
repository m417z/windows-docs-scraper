## Description

The **D3D12DDI_NODE_LIST_ENTRY_0108** structure is used as part of a linked list to represent individual nodes in a work graph. Each node represents a unit of work or operation that can be executed on the GPU.

## Members

### `pNode`

Pointer to a [**D3D12DDI_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0108) structure that describes the node.

### `pNext`

Pointer to the next node in the list.

## Remarks

This linked list structure enables the definition of complex execution flows where each node can depend on the completion of others, forming a directed acyclic graph (DAG) of operations.

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_desc_0108)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)

[**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108)