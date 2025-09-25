## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the motion estimation capabilities for a video encoder.

## Members

### `NodeIndex`

In multi-adapter operation, identifies the physical adapter of the device this operation applies to.

### `InputFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) structure specifying the format of the input resources.

### `BlockSizeFlags`

A bitwise OR combination of values from the [D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_search_block_size_flags) enumeration specifying the encoder's supported search block sizes for motion estimation.

### `PrecisionFlags`

A bitwise OR combination of values from the [D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_vector_precision_flags) enumeration specifying the encoder's supported vector precision for motion estimation.

### `SizeRange`

A [D3D12_VIDEO_SIZE_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_size_range) structure representing the minimum and maximum input size supported by the driver. The driver sets the fields of this structure to zero if motion estimation is unsupported.

## Remarks

When the format is not supported with motion estimation, *BlockSizeFlags* will be set to [D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAG_NONE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_search_block_size_flags), *PrecisionFlags* will be set to [D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_FLAG_NONE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_vector_precision_flags), and the *SizeRange* will be set to all zeros.

## See also