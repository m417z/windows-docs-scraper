## Description

The **D3D12DDICAPS_VIDEO_ENCODER_OUTPUT_RESOLUTION_DATA_0080_2** structure is used to return the list of supported resolutions based on codec, profile, and level.

## Members

### `NodeIndex`

[in] In a multi-adapter operation, **NodeIndex** indicates which physical adapter of the device that the operation applies to.

### `Codec`

[in] A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that specifies the codec to check support for.

### `ResolutionRatiosCount`

[in] The number of resolution ratios to retrieve. This value must match [**D3D12DDICAPS_VIDEO_ENCODER_OUTPUT_RESOLUTION_RATIOS_COUNT_DATA_0080_2.ResolutionRatiosCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_output_resolution_ratios_count_data_0080_2).

### `IsSupported`

[out] Indicates whether the adapter supports the current query inputs.

### `MinResolutionSupported`

[out] A [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structure in which to return the minimum supported resolution.

### `MaxResolutionSupported`

[out] A [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structure in which to return the maximum supported resolution.

### `ResolutionWidthMultipleRequirement`

[out] The resolution width must be divisible by this value.

### `ResolutionHeightMultipleRequirement`

[out] The resolution height must be divisible by this value.

### `pResolutionRatios`

[out] Pointer to a list of **ResolutionRatiosCount** caller-allocated [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_RATIO_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_ratio_desc_0080) structures in which to return the supported resolution ratios as irreducible fractions.

## Remarks

The D3D runtime calls [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with [**D3D12DDICAPS_TYPE_VIDEO_0080_ENCODER_OUTPUT_RESOLUTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) specified as the capability type.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)