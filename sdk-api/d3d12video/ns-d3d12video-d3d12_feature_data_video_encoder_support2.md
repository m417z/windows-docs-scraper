## Description

Extends D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT1 for the driver to report support details when enabling QPMap, dirty regions, and/or motion search hints features. If the driver does not support a given combination, it must report D3D12_VIDEO_ENCODER_SUPPORT_FLAG_NONE and specify conflicting features in [D3D12_VIDEO_ENCODER_VALIDATION_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_validation_flags).

## Members

### `NodeIndex`

Input parameter. In multi-adapter operation, indicates which physical adapter of the device this operation applies to.

### `Codec`

Input parameter. A [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) value specifying the codec.

### `InputFormat`

Input parameter. A DXGI_FORMAT value specifying the input format.

### `CodecConfiguration`

Input parameter. A [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration) specifying the codec configuration.

### `CodecGopSequence`

Input parameter. A [D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_gop_structure) specifying the GOP structure.

### `RateControl`

Input parameter. A [D3D12_VIDEO_ENCODER_RATE_CONTROL](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control) specifying the rate control.

### `IntraRefresh`

Input parameter. A [D3D12_VIDEO_ENCODER_INTRA_REFRESH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_intra_refresh_mode) specifying the intra refresh mode.

### `SubregionFrameEncoding`

Input parameter. A [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_subregion_layout_mode) value specifying the subregion layout mode.

### `ResolutionsListCount`

Input parameter. The number of resolutions in pResolutionList.

### `pResolutionList`

Input parameter. Pointer to an array of [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) structures specifying the resolutions.

### `MaxReferenceFramesInDPB`

Input parameter. The maximum number of reference frames in the decoded picture buffer.

### `ValidationFlags`

Output parameter. A combination of [D3D12_VIDEO_ENCODER_VALIDATION_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_validation_flags) indicating unsupported features.

### `SupportFlags`

Output parameter. A combination of [D3D12_VIDEO_ENCODER_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) indicating support.

### `SuggestedProfile`

Output parameter. A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) with the suggested profile.

### `SuggestedLevel`

Output parameter. A [D3D12_VIDEO_ENCODER_LEVEL_SETTING](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_level_setting) with the suggested level.

### `pResolutionDependentSupport`

Output parameter. Pointer to a caller-allocated array of [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits1) structures the driver fills for each resolution in pResolutionList.

### `SubregionFrameEncodingData`

A [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_subregions_layout_data) specifying the subregion layout data.

### `MaxQualityVsSpeed`

Output parameter. Maximum quality versus speed value.

### `QPMap`

Input parameter. A [D3D12_VIDEO_ENCODER_QPMAP_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_qpmap_configuration) specifying the intended QPMap configuration.

### `DirtyRegions`

Input parameter. A [D3D12_VIDEO_ENCODER_DIRTY_REGIONS_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_dirty_regions_configuration) specifying the intended dirty regions configuration.

### `MotionSearch`

Input parameter. A [D3D12_VIDEO_ENCODER_MOTION_SEARCH_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_motion_search_configuration) specifying the intended motion search configuration.

## Remarks

## See also