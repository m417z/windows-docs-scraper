# D3D12DDI_VIDEO_EXTENSION_COMMAND_CAPS_DATA_0063 structure

## Description

D3D12DDI_VIDEO_EXTENSION_COMMAND_CAPS_DATA is the data structure used in the query for video extension command capabilities. Input and output structures are defined by the particular video command extension. These structures may only be used for querying capabilities and only support print on demand (POD) data types.

## Members

### `NodeIndex` [in]

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `CommandId` [in]

The unique identifier for the video extension command.

### `pInputData` [in]

Input data for the capability query allocated by the caller with a size of **InputDataSizeInBytes**. This struct is enumerable as the **D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_CAPS_INPUT** parameter stage of the [D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_extension_command_parameter_stage_0063) enumeration.

### `InputDataSizeInBytes` [in]

The byte size of the input data allocation.

### `pOutputData` [out]

Output data for the capability query allocated by the caller with a size of OutputDataSizeInBytes. This struct is enumerable as the **D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_CAPS_OUTPUT** parameter stage of the [D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_extension_command_parameter_stage_0063) enumeration.

### `OutputDataSizeInBytes` [out]

The byte size of the output data allocation.

## Remarks

## See also