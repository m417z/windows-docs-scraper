## Description

The **D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0** structure provides the driver's support details for the requested input configurations.

## Members

### `NodeIndex`

[in] In a multi-adapter operation, **NodeIndex** indicates which physical adapter of the device that the operation applies to.

### `Codec`

[in] A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that specifies the encode codec to use.

### `InputFormat`

[in] A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) value that specifies the input format of the input frames.

### `CodecConfiguration`

[in] A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0082_0) structure that specifies the requested configuration for the selected codec. The codec-specific structure within this structure should match the codec type specified by **Codec**.

### `CodecGopSequence`

[in] A [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_gop_structure_0082_0) structure that specifies the requested group of pictures (GOP) configuration for the selected codec. The codec-specific structure within this structure should match the codec type specified by **Codec**.

### `RateControl`

[in] A [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_0080_2) structure that specifies the requested rate control configuration.

### `IntraRefresh`

[in] A [**D3D12DDI_VIDEO_ENCODER_INTRA_REFRESH_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_intra_refresh_mode_0080) value that specifies the requested intra refresh mode.

### `SubregionFrameEncoding`

[in] A [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080) value that specifies the requested subregion partitioning mode.

### `ResolutionsListCount`

[in] Indicates the number of resolutions in the list that **pResolutionList** points to.

### `pResolutionList`

[in] Pointer to an array of [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structures that specifies the list of resolutions requested to be supported.

### `MaxReferenceFramesInDPB`

[in] The maximum number of previous reference frames to be used when calling [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) for inter-frames. This value is used to calculate the suggested level.

### `ValidationFlags`

[out] A [**D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_validation_flags_0082_0) value that provides more details if the cap query returns with the[**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0083_0_GENERAL_SUPPORT_OK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) bit not set.

### `SupportFlags`

[out] A [**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) value that specifies the support details for the requested configuration.

### `SuggestedProfile`

[out] A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure in which the driver returns the matching profile for the requested configuration.

### `SuggestedLevel`

[out] A [**D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_level_setting_0080_2) structure in which the driver returns the matching level for the requested configuration for each resolution present in **pResolutionList**.

### `pResolutionDependentSupport`

[out] Pointer to a list of [**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) structures in which the driver returns the resolution-dependent support limits.

## Remarks

The D3D runtime calls [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with [**D3D12DDICAPS_TYPE_VIDEO_0080_ENCODER_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) specified as the capability type.

The support granted or rejected by this query indicates simultaneous support for all the features selected to be used in the same encoding session. There can be features that are supported individually when queried with individual query calls but not supported simultaneously.

For example, there can be support for intra refresh when checking **D3D12DDICAPS_TYPE_VIDEO_0080_ENCODER_INTRA_REFRESH_MODE** and there can be support for B frames when checking that [**D3D12_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT_H264.MaxL1ReferencesForB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_picture_control_support_h264_0080_2) is greater than 0. However, there can be the case that intra refresh and B frames are not supported simultaneously. In this case, querying **D3D12DDICAPS_TYPE_VIDEO_0080_ENCODER_SUPPORT** with **CodecGopSequence** containing B frames and intra refresh row-based mode, the D3D12_VIDEO_ENCODER_SUPPORT_FLAG_GENERAL_SUPPORT_OK flag must be set off.

This structure doesn't work for AV1 codec input. Use [**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT1_DATA_0096**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support1_data_0096) for AV1 codec support instead.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)