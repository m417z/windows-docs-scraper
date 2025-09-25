## Description

The **D3D12DDI_NODE_IO_KIND_0108** enumeration specifies the class of input or output for a node in a work graph.

## Constants

### `D3D12DDI_NODE_IO_KIND_INVALID`

The node I/O is invalid or uninitialized.

### `D3D12DDI_NODE_IO_KIND_EMPTY_INPUT_0108`

The node has an empty input.

### `D3D12DDI_NODE_IO_KIND_NODE_OUTPUT_0108`

The node produces an output that may be read from and written to.

### `D3D12DDI_NODE_IO_KIND_NODE_OUTPUT_ARRAY_0108`

Signifies an array of node outputs with read-write capabilities.

### `D3D12DDI_NODE_IO_KIND_EMPTY_OUTPUT_0108`

The node has an empty output (no data is produced).

### `D3D12DDI_NODE_IO_KIND_EMPTY_OUTPUT_ARRAY_0108`

Signifies an array of nodes with empty outputs.

### `D3D12DDI_NODE_IO_KIND_DISPATCH_NODE_INPUT_RECORD_0108`

Signifies a dispatch node input record.

### `D3D12DDI_NODE_IO_KIND_GROUP_NODE_INPUT_RECORDS_0108`

Signifies group node input records.

### `D3D12DDI_NODE_IO_KIND_THREAD_NODE_INPUT_RECORD_0108`

Signifies a thread node input record.

### `D3D12DDI_NODE_IO_KIND_READ_WRITE_DISPATCH_NODE_INPUT_RECORD_0108`

Signifies a read-write dispatch node input record.

### `D3D12DDI_NODE_IO_KIND_READ_WRITE_GROUP_NODE_INPUT_RECORDS_0108`

Signifies read-write group node input records.

### `D3D12DDI_NODE_IO_KIND_READ_WRITE_THREAD_NODE_INPUT_RECORD_0108`

Signifies a read-write thread node input record.

### `D3D12DDI_NODE_IO_KIND_GROUP_NODE_OUTPUT_RECORDS_0108`

Signifies group node output records.

### `D3D12DDI_NODE_IO_KIND_THREAD_NODE_OUTPUT_RECORDS_0108`

Signifies thread node output records.

## Remarks

Each enum definition is comprised of a set of [**D3D12DDI_NODE_IO_FLAGS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_node_io_flags_0108) flags, within **D3D12DDI_NODE_IO_FLAG_KIND_MASK**. This enum is a DDI copy of the NodeIOKind portion of the [NodeIOFlags and NodeIOKind encoding](https://github.com/microsoft/DirectX-Specs/blob/master/d3d/WorkGraphs.md#nodeioflags-and-nodeiokind-encoding) in DXIL metadata.

## See also

[**D3D12DDI_BROADCASTING_LAUNCH_NODE_PROPERTIES_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_broadcasting_launch_node_properties_0108)

[**D3D12DDI_COALESCING_LAUNCH_NODE_PROPERTIES_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_coalescing_launch_node_properties_0108)

[**D3D12DDI_NODE_OUTPUT_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_output_0108)

[**D3D12DDI_THREAD_LAUNCH_NODE_PROPERTIES_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_thread_launch_node_properties_0108)

[**D3D12DDI_SHADER_NODE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_node_0108)