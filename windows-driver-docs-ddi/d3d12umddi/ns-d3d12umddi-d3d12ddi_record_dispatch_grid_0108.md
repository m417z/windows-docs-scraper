## Description

The **D3D12DDI_RECORD_DISPATCH_GRID_0108** structure describes the [*SV_DispatchGrid*](https://github.com/microsoft/DirectX-Specs/blob/master/d3d/WorkGraphs.md#sv_dispatchgrid) field in a record.

## Members

### `ByteOffset`

Byte offset of *SV_DispatchGrid* in the record.

### `NumComponents`

Number of components in *SV_DispatchGrid*, [1...3]

### `b16BitsPerComponent`

If TRUE, the components in *SV_DispatchGrid* are ```uint16```, else ```uint32```.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_BROADCASTING_LAUNCH_NODE_PROPERTIES_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_broadcasting_launch_node_properties_0108)

[**D3D12DDI_NODE_OUTPUT_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_node_output_0108)