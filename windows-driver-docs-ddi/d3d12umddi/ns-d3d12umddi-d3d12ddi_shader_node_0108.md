## Description

The **D3D12DDI_SHADER_NODE_0108** structure describes a shader node in a work graph.

## Members

### `Shader`

Name of the shader for the node, after any renaming that might have been done when exporting shaders into a state object.

### `PropertiesType`

A [**D3D12DDI_NODE_PROPERTIES_TYPE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_node_properties_type_0108) enumeration that specifies the type of the node properties and which union member is valid.

### `pBroadcastingLaunchNodeProperties`

Pointer to a [**D3D12DDI_BROADCASTING_LAUNCH_NODE_PROPERTIES_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_broadcasting_launch_node_properties_0108) structure that describes the properties of a broadcasting launch node.

### `pCoalescingLaunchNodeProperties`

Pointer to a [**D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_coalescing_launch_node_properties_0108) structure that describes the properties of a coalescing launch node.

### `pThreadLaunchNodeProperties`

Pointer to a [**D3D12DDI_THREAD_LAUNCH_NODE_PROPERTIES_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_thread_launch_node_properties_0108) structure that describes the properties of a thread launch node.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_0108)