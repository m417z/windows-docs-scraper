## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_PROFILE_LEVEL](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves a value indicating if the specified profile is supported for video encoding.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which the supported profile level is being queried.

### `Profile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) structure specifying the profile for which support is being queried.

### `IsSupported`

Receives a boolean value indicating if the specified profile is supported for the specified codec.

### `MinSupportedLevel`

Output field that receives the minimum supported level for the selected codec and profile if supported.

### `MaxSupportedLevel`

Output field that receives the maximum supported level for the selected codec and profile if supported.

## Remarks

## See also