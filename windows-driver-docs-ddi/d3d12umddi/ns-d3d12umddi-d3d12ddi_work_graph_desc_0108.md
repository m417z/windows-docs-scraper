## Description

The **D3D12DDI_WORK_GRAPH_DESC_0108** structure defines the state subobject of type [**D3D12DDI_STATE_SUBOBJECT_TYPE_WORK_GRAPH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_subobject_type).

## Members

### `ProgramName`

Name of the work graph. This name is unique in the given state object and is used to identify the work graph.

### `Version`

The version number of this work graph, starting at 0. When [**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072) is being used, this value increments for new versions.

If a state object that has had a few additions in it to other parts of it (perhaps other work graphs) gets a newly created work graph added, Version will be 0 for the initial appearance of the new work graph, even though the state object itself has had a few iterations. Similarly if additions are made to other parts of a state object but a particular work graph in it is left alone, its version doesn't change until the next time an addition is made to the work graph itself. The Version value is the same numbering used in the **VersionAdded** field of [**D3D12DDI_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0108).

### `Flags`

A [**D3D12DDI_WORK_GRAPH_FLAGS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_work_graph_flags_0108) enumeration that specifies flags that control the behavior of the work graph.

### `NumNodes`

The number of nodes within the work graph, including already existing ones if an addition is happening. This value determines the number of elements in the **pNodes** array.

### `pNodes`

Pointer to an array of [**D3D12DDI_NODE_LIST_ENTRY_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_list_entry_0108) structures, where each entry represents a node definition in the work graph.

Even with the **D3D12DDI_WORK_GRAPH_FLAG_ADD_TO_EXISTING_WORK_GRAPH** flag, **pNodes** points to a list of all nodes in the graph. New nodes appear at the start of the list.

### `NumEntrypoints`

Number of entrypoints including already existing ones if an addition is happening. This value determines the number of elements in the **pEntrypoints** array.

### `pEntrypoints`

Pointer to an array of [**D3D12DDI_NODE_LIST_ENTRY_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_list_entry_0108) structures, where each entry represents an entry point in the work graph.

Even with the **D3D12DDI_WORK_GRAPH_FLAG_ADD_TO_EXISTING_WORK_GRAPH** flag, **pEntryPoints** points to a list of all entrypoints. New entrypoints appear at the start of the list and continue entrypoint index numbering after previous versions. For example, suppose the initial version of a graph has two entrypoints. This list would have two entries, and the driver must infer that they have entry point indices [0] and [1] respectively for record assignments from [**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108). If an addition happens, with 3 new entrypoints, the list for the new graph version would have 5 entry point entries, with the new entries at the start of the list. The driver must infer the entrypoint indices of the 3 new entries at the start of the list (the entries with the new Version), so the full list would be [2], [3], [4], [0], [1]. Ideally these assignments would have been provided by the runtime in the DDI so the driver wouldn't have to figure this out, but this was missed and deemed not important enough to fix.

## Remarks

The **D3D12DDI_WORK_GRAPH_DESC_0108** structure describes a work graph. The work graph itself is a collection of nodes, where each node represents a unit of work or a task. Nodes can have dependencies on one another, which define the execution order. Entry points are the nodes where execution can begin and are typically the nodes without dependencies or those that can be run immediately.

The runtime provides conveniences at the API level, like being able to define a work graph just by listing entrypoints or even by asking for all available nodes to be used. The runtime takes the API work graph definition, validates it, and gives the driver the final set of nodes in the graph, depicted in this **D3D12DDI_WORK_GRAPH_DESC_0108** structure.

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_NODE_LIST_ENTRY_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_list_entry_0108)

[**D3D12DDI_STATE_SUBOBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_subobject_type)

[**D3D12DDI_WORK_GRAPH_FLAGS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_work_graph_flags_0108)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)

[**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108)