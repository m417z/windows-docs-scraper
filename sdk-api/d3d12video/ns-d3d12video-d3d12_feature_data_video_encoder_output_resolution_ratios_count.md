## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_OUTPUT_RESOLUTION_RATIOS_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the number of supported resolution ratios for the specified codec.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which the number of supported resolution ratios is being queried.

### `ResolutionRatiosCount`

Receives a UINT indicating the number of supported resolution ratios for the specified codec.

## Remarks

## See also