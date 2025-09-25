# D3D12DDI_VIDEO_EXTENSION_COMMAND_COUNT_DATA_0063 structure

## Description

Retrieves the number of supported video extension commands.

## Members

### `NodeIndex` [in]

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `CommandCount` [out]

The number of video extension commands supported.

## Remarks

## See also