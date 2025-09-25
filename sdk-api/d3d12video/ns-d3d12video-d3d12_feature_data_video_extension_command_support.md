## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves video extension command support using command-defined input and output structures.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `CommandId`

The unique identifier for the video extension command for which support is queried.

### `pInputData`

Input data for the capability query allocated by the caller with a size of *InputDataSizeInBytes*. This struct is enumerable as the [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_CAPS_INPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage) parameter stage.

### `InputDataSizeInBytes`

The byte size of the input data allocation.

### `pOutputData`

Output data for the capability query allocated by the caller with a size of *OutputDataSizeInBytes*. This struct is enumerable as the [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_CAPS_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage) parameter stage.

### `OutputDataSizeInBytes`

The byte size of the output data allocation.

## Remarks

## See also