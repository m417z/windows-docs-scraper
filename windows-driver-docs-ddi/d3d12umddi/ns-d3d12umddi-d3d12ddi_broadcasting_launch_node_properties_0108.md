## Description

The **D3D12DDI_BROADCASTING_LAUNCH_NODE_PROPERTIES_0108** structure describes the properties of a broadcasting launch node in a work graph.

## Members

### `FinalName`

A [**D3D12DDI_NODE_ID_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_id_0108) structure that specifies the final name of the node after any optional renames done at the application level.

### `bProgramEntry`

When TRUE, the current node is a program entry and is listed in the **pEntrypoints** list in [**D3D12DDI_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_desc_0108). As such this parameter is redundant, but it's present for clarity. The shader might not have declared that the node is an entrypoint but the runtime might have determined it must be one, or at the API the choice might have been overridden in some way. This member is always TRUE for a node that isn't targeted by any other nodes in the graph.

### `InputNodeIOKind`

A [**D3D12DDI_NODE_IO_KIND_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_node_io_kind_0108) enumeration that specifies the class of input. See [Node input declaration](https://github.com/microsoft/DirectX-Specs/blob/master/d3d/WorkGraphs.md#node-input-declaration).

### `InputNodeIOFlags`

Flags that provide additional information about the node's input I/O. See the flags within **D3D12DDI_NODE_IO_FLAGS_FLAG_MASK** in [**D3D12DDI_NODE_IO_FLAGS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_node_io_flags_0108). For an input, the only flag that applies is **D3D12DDI_NODE_IO_FLAG_TRACK_RW_INPUT_SHARING**.

### `InputRecordSizeInBytes`

Size of the input record, in bytes. Can be 0 if **InputNodeIOKind** is **D3D12DDI_NODE_IO_KIND_EMPTY_INPUT_0108**.

### `GroupSharedUsageInBytes`

Size of group shared usage by the node, in bytes.

### `MaxRecursionDepth`

Max recursion declared by shader. A value of 0 means no recursion.

### `pLocalRootArgumentsTableIndex`

If a local root signature has been associated with the shader and/or the shader explicitly declared a local root argument table index it wants to use, the 0-based index is pointed to here. The runtime may have auto-assigned a location. If no local root signature has been associated with the shader, this will be ```nullptr```.

### `pShareInputOfNode`

Optional pointer to a node that shares the same input with this node, or ```nullptr``` if the current node isn't sharing another node's input. If this node is sharing its input from another node in the work graph, **pShareInputOfNode** points to that node, represented by a [**D3D12DDI_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0108) structure. If multiple nodes are in an input sharing set, all but the source node point to the source node, and the source node instead sets the **pNodesSharingInputWithThisNode** parameter to point to the others.

### `pDispatchGrid`

If the node has a fixed dispatch grid size, it is specified here as a 3-component value. Otherwise this is ```nullptr```.

### `pMaxDispatchGrid`

If the node gets its dispatch grid size as part of its input record, the max dispatch grid size is specified here as a 3-component value. Otherwise this is ```nullptr```.

### `pRecordDispatchGrid`

If ```nullptr```, the output record doesn't contain [*SV_DispatchGrid*](https://github.com/microsoft/DirectX-Specs/blob/master/d3d/WorkGraphs.md#sv_dispatchgrid). Else, points to a description of how *SV_DispatchGrid* appears in the output record. See [**D3D12DDI_RECORD_DISPATCH_GRID_0108**].

### `pInputNodes`

Pointer to a list ([**D3D12DDI_NODE_LIST_ENTRY_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_list_entry_0108)) of nodes ([**(D3D12DDI_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0108)) that target the current node. **pInputNodes** is ```nullptr``` if no nodes target this node.

### `pNodesSharingInputWithThisNode`

Pointer to a list ([**D3D12DDI_NODE_LIST_ENTRY_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_list_entry_0108)) of nodes ([**(D3D12DDI_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0108)) that share input with the current node. **pNodesSharingInputWithThisNode** is ```nullptr``` if no nodes share input with this node.

### `NumOutputs`

Number of nodes that this node outputs to.

### `pOutputs`

Pointer to an array of **NumOutputs** [**D3D12DDI_NODE_OUTPUT_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_output_0108) structures that contain output definitions. **pOutputs** is ```nullptr``` if this node doesn't output to other nodes.

## Remarks

Any properties listed here take precedence over (override) what might have been declared in the shader for the node. The driver must always use the properties listed here as the final property selections. If a driver happens to care about whether something was overridden, it can compare any setting here against what the shader declared.

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_SHADER_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_node_0108)