## Description

Defines vector precision values for video motion estimation.

## Constants

### `D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_QUARTER_PEL:0`

The vector precision is quarter-pixel motion.

## Remarks

Query for supported vector precision values by calling [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) and specifying the feature value of [D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

Set the desired vector precision for video motion estimation with the [D3D12_VIDEO_MOTION_ESTIMATOR_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_motion_estimator_desc) passed into [ID3D12VideoDevice1::CreateVideoMotionEstimator](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice1-createvideomotionestimator).

## See also