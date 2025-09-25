## Description

The **D3D12DDICAPS_VIDEO_ENCODER_SUPPORT1_DATA_0096** structure provides the driver's support details for the requested input configurations.

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

[out] A [**D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_validation_flags_0082_0) value

### `SupportFlags`

[out] A [**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) value that specifies the support details for the requested configuration.

### `SuggestedProfile`

[out] A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure in which the driver returns the matching profile for the requested configuration.

### `SuggestedLevel`

[out] A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure in which the driver returns the matching profile for the requested configuration.

### `pResolutionDependentSupport`

[out] Pointer to a list of [**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) structures in which the driver returns the resolution-dependent support limits.

### `SubregionFrameEncodingData`

[in] A [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_subregions_layout_data_0080_2) structure that specifies the subregion layout data for the frame. The driver uses this value to calculate **SuggestedLevel** in codecs that have subregion constraints per level. It's also used for related validation with the [**D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAG_0095_SUBREGION_LAYOUT_DATA_NOT_SUPPORTED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_validation_flags_0082_0) flag.

### `MaxQualityVsSpeed`

[out] The maximum quality vs speed trade-off value that the driver supports. This value is used as the maximum value allowed for the **QualityVsSpeed** parameter in the rate control structures. This value must be reported as zero if the driver doesn't set [**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0096_RATE_CONTROL_QUALITY_VS_SPEED_AVAILABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0).

## Remarks

**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT1_DATA_0096** extends on the previous [**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support_data_0083_0) query, with new parameters added at the bottom of it. This new query can be used with all H264, HEVC and AV1 codecs and must behave exactly as **D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**'s semantics.

The previous **D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0** structure doesn't work for AV1 codec input.

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)