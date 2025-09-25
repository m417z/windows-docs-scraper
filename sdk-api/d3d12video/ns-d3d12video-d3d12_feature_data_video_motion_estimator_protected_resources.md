## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR_PROTECTED_RESOURCES](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the protected resources support for video motion estimation.

## Members

### `NodeIndex`

In multi-adapter operation, identifies the physical adapter of the device this operation applies to.

### `SupportFlags`

A member of the [D3D12_VIDEO_PROTECTED_RESOURCE_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_protected_resource_support_flags) enumeration specifying support for protected resources.

## Remarks

## See also