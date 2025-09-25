# D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETERS_DATA_0063 structure

## Description

Retrieves the array of parameter info for a parameter stage.

## Members

### `CommandId` [in]

The unique identifier for the video extension command.

### `Stage` [in]

 The parameter stage to query.

### `ParameterCount` [in]

This must match the **ParameterCount** returned by the [D3D12DDICAPS_TYPE_VIDEO_ENUMERATE_EXTENSION_COMMAND_PARAMETER_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_extension_command_parameter_count_data_0063) query.

### `pParameterInfos` [out]

An array allocated by the runtime for the driver to fill with parameter info. **ParameterCount** indicates the number of array elements.

## Remarks

## See also