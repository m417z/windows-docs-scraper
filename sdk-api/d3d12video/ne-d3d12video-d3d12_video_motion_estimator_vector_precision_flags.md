## Description

Specifies the motion estimation vector precision that a video encoder supports.

## Constants

### `D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_FLAG_NONE:0`

Vector precision is not supported by the encoder.

### `D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_FLAG_QUARTER_PEL`

The vector precision is quarter-pixel motion.

## Remarks

Query for supported vector precision values by calling [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) and specifying the feature value of [D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

## See also