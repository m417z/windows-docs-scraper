## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Checks the allocation size of a video extension command.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `CommandId`

The unique identifier for the video extension command for which size is queried.

### `pCreationParameters`

A pointer to the creation parameters structure, which is defined by the command. The parameters structure must match the parameters enumerated by a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with the feature value of [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) and a parameter stage value of [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_CREATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage).

### `CreationParametersSizeInBytes`

The size of the *pCreationParameters* parameter structure, in bytes.

### `MemoryPoolL0Size`

The allocation size of the video extension command in the L0 memory pool. L0 is the physical system memory pool. When the adapter is discrete/NUMA, this pool has greater bandwidth for the CPU and less bandwidth for the GPU. When the adapter is UMA, this pool is the only one which is valid. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `MemoryPoolL1Size`

The allocation size of the video extension command heap in the L1 memory pool. L1 is typically known as the physical video memory pool. L1 is only available when the adapter is discrete/NUMA, and has greater bandwidth for the GPU and cannot even be accessed by the CPU. When the adapter is UMA, this pool is not available. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

## Remarks

## See also