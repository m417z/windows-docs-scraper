## Description

Specifies the parameter stages for video extension commands.

## Constants

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_CREATION:0`

The parameter stage is in video extension command creation.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_INITIALIZATION:1`

The parameter stage is in video extension command initialization.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_EXECUTION:2`

The parameter stage is in video extension command execution.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_CAPS_INPUT:3`

The parameter stage is input parameters passed to capabilities queries.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_CAPS_OUTPUT:4`

The parameter stage is output parameters passed to capabilities queries.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_DEVICE_EXECUTE_INPUT:5`

The parameter stage is device execution input.

### `D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_DEVICE_EXECUTE_OUTPUT:6`

The parameter stage is device execution output.

## Remarks

Values from this enumeration are used when querying for video extension parameter information with calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with the feature specified as [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) or [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). The results of these parameter queries may be different for different parameter stages.

## See also