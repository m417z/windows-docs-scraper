## Description

The **D3D12DDI_WORK_GRAPH_FLAGS_0108** enumeration specifies flags for the [**D3D12DDI_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_desc_0108) structure for configuring the behavior of the work graph.

## Constants

### `D3D12DDI_WORK_GRAPH_FLAG_NONE`

Default behavior.

### `D3D12DDI_WORK_GRAPH_FLAG_ADD_TO_EXISTING_WORK_GRAPH`

The work graph is being added to an existing one, so the **ProgramName** has been seen before. It is possible for [**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072) to be used without this flag, in which case an entirely new work graph is being added to the state object, such as making a new graph from some existing or new nodes in the state object. So this flag helps distinguish adding an entirely new state object versus adding to an existing one.

The driver could also deduce this by checking to see if **ProgramName** already exists in the state object, but the flag saves the trouble. Whether or not this flag is present, the work graph description lists the entire graph, with newly added nodes at the start of the list (reusing list entries for existing nodes). Newly added node definitions include pointers for how they are connected to the rest of the graph (just like existing nodes), and existing nodes provided in previous state objects are updated in-place to link back to the new nodes they are connected to. So there is one representation of all versions of the graph together, and the differences between versions can be seen by the **Version** number in each node. For the rules about valid additions, see [**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072).

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_desc_0108)