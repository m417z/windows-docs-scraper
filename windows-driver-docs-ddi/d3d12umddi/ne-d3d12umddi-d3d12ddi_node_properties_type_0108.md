## Description

The **D3D12DDI_NODE_PROPERTIES_TYPE_0108** enumeration specifies the type of properties associated with a node in a work graph.

## Constants

### `D3D12DDI_NODE_PROPERTIES_TYPE_BROADCASTING_LAUNCH_0108`

Indicates that the node properties are related to a broadcasting launch node (one input seen by many thread groups).

### `D3D12DDI_NODE_PROPERTIES_TYPE_COALESCING_LAUNCH_0108`

Indicates that the node properties are related to a coalescing launch node (variable inputs seen by each thread group).

### `D3D12DDI_NODE_PROPERTIES_TYPE_THREAD_LAUNCH_0108`

Indicates that the node properties are related to a thread launch node (one input per thread).

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_SHADER_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_node_0108)