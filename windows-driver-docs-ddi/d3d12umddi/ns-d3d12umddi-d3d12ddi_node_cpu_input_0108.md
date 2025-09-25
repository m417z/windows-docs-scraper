## Description

The **D3D12DDI_NODE_CPU_INPUT_0108** structure describes the input data for a single node within a work graph where the input is provided by the CPU.

## Members

### `EntrypointIndex`

The index of a given entry to a work graph.

### `NumRecords`

The number of records to add. **NumRecords** is always used; that is, even with empty records the count of empty work items still drives node invocations.

### `pRecords`

Pointer to the record definitions, laid out with the same member packing and struct size rules that C uses. The driver should copy/save this data during command list recording.

### `RecordStrideInBytes`

Distance between the start of each record, in bytes. This value must be aligned to the largest scalar member size and be a multiple of 4 bytes.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_DISPATCH_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_dispatch_graph_desc_0108)

[**PFND3D12DDI_DISPATCH_GRAPH_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_graph_0108)