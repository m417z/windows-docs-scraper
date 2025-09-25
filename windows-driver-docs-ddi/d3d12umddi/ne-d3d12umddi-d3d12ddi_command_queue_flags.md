# D3D12DDI_COMMAND_QUEUE_FLAGS enumeration

## Description

The **D3D12DDI_COMMAND_QUEUE_FLAGS** enumeration specifies the type of command list to use on the command queue being created.

## Constants

### `D3D12DDI_COMMAND_QUEUE_FLAG_NONE:0x00000000`

No flags are specified.

### `D3D12DDI_COMMAND_QUEUE_FLAG_3D:0x00000001`

Indicates a command queue compatible with graphics pipelines.

### `D3D12DDI_COMMAND_QUEUE_FLAG_COMPUTE:0x00000002`

Indicates a command queue compatible with compute pipelines.

### `D3D12DDI_COMMAND_QUEUE_FLAG_COPY:0x00000004`

Indicates a command queue compatible with a copy engine.

### `D3D12DDI_COMMAND_QUEUE_FLAG_PAGING:0x00000008`

Reserved; do not use.

### `D3D12DDI_COMMAND_QUEUE_FLAG_0020_VIDEO_LEGACY:0x00000010`

Deprecated; do not use.

### `D3D12DDI_COMMAND_QUEUE_FLAG_0022_VIDEO_DECODE:0x00000010`

Indicates a command queue compatible with video decoding.

### `D3D12DDI_COMMAND_QUEUE_FLAG_0022_VIDEO_PROCESS:0x00000020`

Indicates a command queue compatible with video processing.

### `D3D12DDI_COMMAND_QUEUE_FLAG_0053_VIDEO_ENCODE:0x00000040`

Indicates a command queue compatible with video encoding.

## Remarks

There are separate queue types for video decode and video processing. The video decode command queue only supports submitting video decode command lists and the video process command queue only supports submitting video process command lists. Both video decode and video process share the same DDI table definition, but separate table instances are retrieved from the driver for each type, see [**D3D12DDI_TABLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type).

Because video decode and video processing are separate queue types, they are necessarily separate queue instances. Applications are required to synchronize between separate queue instances; therefore, drivers must not implicitly synchronize between decode and video process queues.

## See also

[**D3D12DDI_D3D12_OPTIONS_DATA_0089**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0089)

[**D3D12DDIARG_CREATECOMMANDQUEUE_0050**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createcommandqueue_0050)

[**Pfnd3d12ddiCreatecommandqueue0050**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createcommandqueue_0050)