## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_RATE_CONTROL_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves a value indicating if the specified rate control mode is supported for video encoding with the specified codec.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which rate control mode support is being queried.

### `RateControlMode`

A member of the [D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_mode) enumeration specifying the rate control mode for which support is being queried.

### `IsSupported`

Receives a boolean value indicating if the specified rate control mode is supported for the specified codec.

## Remarks

## See also