## Description

Specifies the motion estimation search block sizes that a video encoder supports.

## Constants

### `D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAG_NONE:0`

Search block size is not supported by the encoder.

### `D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAG_8X8`

The encoder supports a search block size of 8x8 pixels.

### `D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAG_16X16`

The encoder supports a search block size of 16x16 pixels.

## Remarks

Query for supported block sizes by calling [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) and specifying the feature value of [D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

## See also