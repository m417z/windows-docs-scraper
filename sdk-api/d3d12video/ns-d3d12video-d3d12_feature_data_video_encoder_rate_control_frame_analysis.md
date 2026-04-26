## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Queries driver support for lower resolution two pass frame analysis at a given downscale factor and encode configuration.

## Members

### `NodeIndex`

Input parameter. In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

Input parameter. A [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) specifying the codec.

### `Profile`

Input parameter. A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) specifying the profile.

### `Level`

Input parameter. A [D3D12_VIDEO_ENCODER_LEVEL_SETTING](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_level_setting) specifying the level.

### `InputFormat`

Input parameter. A DXGI_FORMAT specifying the input format.

### `InputResolution`

Input parameter. A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) specifying the input resolution.

### `CodecConfiguration`

Input parameter. A [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration) specifying the codec configuration.

### `SubregionFrameEncoding`

Input parameter. A [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_subregion_layout_mode) specifying the subregion frame encoding mode.

### `SubregionFrameEncodingData`

Input parameter. A [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_subregions_layout_data) specifying the subregion frame encoding data.

### `QPMap`

Input parameter. A D3D12_VIDEO_ENCODER_QPMAP_CONFIGURATION specifying the QP map configuration.

### `DirtyRegions`

Input parameter. A D3D12_VIDEO_ENCODER_DIRTY_REGIONS_CONFIGURATION specifying the dirty regions configuration.

### `MotionSearch`

Input parameter. A D3D12_VIDEO_ENCODER_MOTION_SEARCH_CONFIGURATION specifying the motion search configuration.

### `Pow2DownscaleFactor`

Input parameter. Indicates the downscaling ratio to be used for the two pass downscaled texture passed to the driver. The full resolution input dimensions must be exactly divisible by 2^*Pow2DownscaleFactor*. The drivers must also enforce this by reporting no support where the division is not exact.

### `SupportFlags`

Output parameter. A bitwise or combination of [D3D12_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_frame_analysis_support_flags) values indicating support for the given input parameters.

## Remarks

## See also

[D3D12_VIDEO_ENCODER_RATE_CONTROL_FRAME_ANALYSIS_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_rate_control_frame_analysis_support_flags)