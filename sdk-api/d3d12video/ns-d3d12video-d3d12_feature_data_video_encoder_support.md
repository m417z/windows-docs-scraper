## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves values indicating support for the specified video encoding features and configuration values.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which support is being queried.

### `InputFormat`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) structure specifying the profile for which support is being queried.

### `CodecConfiguration`

A [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration) structure representing the codec configuration for which support is being queried.

### `CodecGopSequence`

A [D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_gop_structure) structure representing the GOP structure for which support is being queried.

### `RateControl`

A [D3D12_VIDEO_ENCODER_RATE_CONTROL](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_rate_control) representing the rate control settings for which support is being queried.

### `IntraRefresh`

A member of the [D3D12_VIDEO_ENCODER_INTRA_REFRESH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_intra_refresh_mode) enumeration specifying the intra refresh mode for which support is being queried.

### `SubregionFrameEncoding`

A member of the [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_subregion_layout_mode) enumeration, specifying the subregion layout mode for which support is being queried.

### `ResolutionsListCount`

A UINT specifying the number of resolutions provided in the *pResolutionList* field.

### `pResolutionList`

A pointer to an array of [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) specifying the picture resolutions for which support is being queried.

### `MaxReferenceFramesInDPB`

A UINT specifying Maximum number of previous reference frames to be used when calling [EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) for inter-frames. This value is used to calculate the suggested level returned in the *SuggestedLevel* field.

### `ValidationFlags`

Receives a bitwise OR combination of flags from the [D3D12_VIDEO_ENCODER_VALIDATION_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_validation_flags) enumeration that provide additional details if the [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_GENERAL_SUPPORT_OK](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) flag is not set in the *SupportFlags* field. See **Remarks** for more information.

### `SupportFlags`

Receives a bitwise OR combination of flags from the [D3D12_VIDEO_ENCODER_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) enumeration specifying support details for the specified encoder features and configuration values.

### `SuggestedProfile`

Receives a [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) specifying the recommended profile for the specified encoder features and configuration values.

### `SuggestedLevel`

Receives a [D3D12_VIDEO_ENCODER_LEVEL_SETTING](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_level_setting) specifying the recommended profile for the specified encoder features and configuration values. The recommended level assumes the maximum resolution from the list provided in *pResolutionList*.

### `pResolutionDependentSupport`

Receives a pointer to an array of [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits) structures specifying resolution-dependent support limits corresponding to the resolutions provided in *pResolutionList*.

## Remarks

The support granted or rejected by this query indicates simultaneous support for all the features selected to be used in the same encoding session. There can be features that are supported individually when queried with individual query calls but not supported simultaneously.

For example, there can be support for intra refresh when checking [D3D12_FEATURE_VIDEO_ENCODER_INTRA_REFRESH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) and there can be support for B frames when checking [D3D12_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT_H264.MaxL1ReferencesForB](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_picture_control_support_h264) > 0. But it can be the case that intra refresh and B frames are not supported simultaneously. In this case, querying **D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT** with CodecGopSequence containing B frames and intra refresh row-based mode, the **D3D12_VIDEO_ENCODER_SUPPORT_FLAG_GENERAL_SUPPORT_OK** flag will be set off.

## See also