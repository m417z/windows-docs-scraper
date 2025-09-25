## Description

The **D3D12DDI_NODE_0108** structure describes a node in a work graph.

## Members

### `VersionAdded`

Version number that the node was added to the state object, starting at 0 for the initial work graph. This value only becomes relevant when [**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072) starts being used to add nodes to a work graph, in which case the version number distingushes when the node was added. The structure of a graph at any given version can be identified by considering any version less or equal to the relevant version number.

### `NodeType`

A [**D3D12DDI_NODE_TYPE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_node_type_0108) enumeration that specifies the type of the node and which union member is valid.

### `Shader`

A [**D3D12DDI_SHADER_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_node_0108) structure that describes a shader node.

## Remarks

Pointers to this structure at the DDI level (for example, from other node descriptions) are stable, which is of particular importance across [**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072) additions.

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_NODE_LIST_ENTRY_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_list_entry_0108)

[**D3D12DDI_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_desc_0108)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)

[**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108)