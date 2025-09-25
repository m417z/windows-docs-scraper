# D3D12DDI_VIDEO_EXTENSION_COMMANDS_DATA_0063 structure

## Description

Retrieves the array of video extension command info for a parameter stage.

## Members

### `NodeIndex` [in]

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `CommandCount` [in]

The number of video extension commands supported. This count must match the **CommandCount** returned by [D3D12DDI_VIDEO_EXTENSION_COMMAND_COUNT_DATA_0063](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_extension_command_count_data_0063).

### `pCommandInfos` [out]

An array allocated by the runtime for the driver to fill with command info. **CommandCount** indicates the number of array elements.

## Remarks

## See also