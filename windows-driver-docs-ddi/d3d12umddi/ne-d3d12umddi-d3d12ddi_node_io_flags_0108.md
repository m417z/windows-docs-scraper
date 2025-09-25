## Description

The **D3D12DDI_NODE_IO_FLAGS_0108** enumeration specifies flags used to describe the I/O behavior of a node in a work graph.

## Constants

### `D3D12DDI_NODE_IO_FLAG_INPUT`

The node is designed to receive input data.

### `D3D12DDI_NODE_IO_FLAG_OUTPUT`

The node produces output data.

### `D3D12DDI_NODE_IO_FLAG_READ_WRITE`

The node can be read from and written to.

### `D3D12DDI_NODE_IO_FLAG_EMPTY_RECORD`

The node has an empty record.

### `D3D12DDI_NODE_IO_FLAG_NODE_ARRAY`

The node is a part of an array of nodes.

### `D3D12DDI_NODE_IO_FLAG_THREAD_RECORD`

The node is a thread record.

### `D3D12DDI_NODE_IO_FLAG_GROUP_RECORD`

The node is a group record.

### `D3D12DDI_NODE_IO_FLAG_DISPATCH_RECORD`

The node is a dispatch record.

### `D3D12DDI_NODE_IO_FLAG_RECORD_GRANULARITY_MASK`

A mask that can be used to extract the record granularity from the flags.

### `D3D12DDI_NODE_IO_FLAG_KIND_MASK`

A mask that can be used to extract the node's I/O kind from the flags.

### `D3D12DDI_NODE_IO_FLAG_TRACK_RW_INPUT_SHARING`

The node tracks read-write input sharing.

### `D3D12DDI_NODE_IO_FLAG_NODE_FLAGS_MASK`

A mask for extracting node-specific flags.

### `D3D12DDI_NODE_IO_FLAG_RECORD_FLAGS_MASK`

A mask for extracting flags related to the node's record behavior.

## Remarks

These flags are a DDI copy of the flags in [NodeIOFlags and NodeIOKind encoding](https://github.com/microsoft/DirectX-Specs/blob/master/d3d/WorkGraphs.md#nodeioflags-and-nodeiokind-encoding) in DXIL metadata.

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_NODE_IO_KIND_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_node_io_kind_0108)