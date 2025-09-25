## Description

The **D3D12DDI_WORK_GRAPH_DESC_0084** structure defines the state subobject of type [**D3D12DDI_STATE_SUBOBJECT_TYPE_WORK_GRAPH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_subobject_type).

## Members

### `ProgramName`

Name of the work graph. This name is unique in the given state object.

### `NumNodes`

The number of nodes in the work graph, including already existing ones if an addition is happening. This value determines the elements in the **pNodes** array.

### `ppNodes`

Pointer to a pointer to an array of [**D3D12DDI_NODE_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0084) structures that describe the nodes in the work graph.

### `NumEntrypoints`

Number of entrypoints including already existing ones if an addition is happening. This value determines the number of elements in the **pEntrypoints** array.

### `pEntrypointNodeIndices`

Pointer to an array of indices into the **pNodes** array that specify the entrypoints for the work graph.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_NODE_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0084)

[**D3D12DDI_STATE_SUBOBJECT_TYPE_WORK_GRAPH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_subobject_type)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)

[**PFND3D12DDI_DISPATCH_GRAPH_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0084)