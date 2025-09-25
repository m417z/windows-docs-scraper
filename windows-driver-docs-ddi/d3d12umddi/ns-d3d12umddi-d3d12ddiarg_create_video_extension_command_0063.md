# D3D12DDIARG_CREATE_VIDEO_EXTENSION_COMMAND_0063 structure

## Description

Contains arguments used to create a video extension command.

## Members

### `NodeMask` [in]

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `CommandId` [in]

The unique identifier for the video extension command.

### `pCreationParameters` [in]

Pointer to the creation parameters structure. Parameters for this structure must match the parameter enumeration for [D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_CREATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_extension_command_parameter_stage_0063).

### `CreationParametersDataSizeInBytes`

The size of the creation parameters structure in bytes.

### `hDrvProtectedResourceSession`

Handle to the D3D12DDI_HPROTECTEDRESOURCESESSION_0030. Runtime has allocated space according to the result of PFND3D12DDI_CALC_PRIVATE_VIDEO_EXTENSION_COMMAND_SIZE for the driver to place its object.

## Remarks

## See also