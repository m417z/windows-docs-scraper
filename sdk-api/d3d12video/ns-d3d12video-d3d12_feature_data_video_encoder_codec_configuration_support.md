## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves a value indicating if the specified codec configuration support parameters are supported for the provided HEVC encoding configuration or retrieves the supported configuration for H.264 encoding.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which rate control mode support is being queried.

### `Profile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) structure specifying the profile for which intra refresh mode support is being queried.

### `IsSupported`

Receives a boolean value indicating if the specified configuration parameters are supported for the specified codec.

### `CodecSupportLimits`

A [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration_support) structure. For HEVC, the caller populates this structure with the desired encoder configuration. For H.264, the **CheckFeatureSupport** call populates the structure with the supported configuration.

## Remarks

## See also