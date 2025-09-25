## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_INTRA_REFRESH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves a value indicating if the specified intra refresh mode is supported for the specified codec, profile, and level.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which intra refresh mode support is being queried.

### `Profile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) structure specifying the profile for which intra refresh mode support is being queried.

### `Level`

A [D3D12_VIDEO_ENCODER_LEVEL_SETTING](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_level_setting) structure specifying the level for which intra refresh mode support is being queried.

### `IntraRefreshMode`

A member of the [D3D12_VIDEO_ENCODER_INTRA_REFRESH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_intra_refresh_mode) enumeration specifying the intra refresh mode for which support is being queried.

### `IsSupported`

Receives a boolean value indicating if the specified intra refresh mode is supported for the specified codec, profile, and level.

## Remarks

## See also