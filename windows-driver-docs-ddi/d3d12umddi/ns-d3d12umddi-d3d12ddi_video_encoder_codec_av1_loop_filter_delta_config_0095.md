## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_AV1_LOOP_FILTER_DELTA_CONFIG_0095** structure contains configuration information related to the loop filter delta settings within an AV1 video encoder.

## Members

### `DeltaLFPresent`

Related to AV1 syntax delta_lf_params(). Requires that [**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAG_DELTA_LF_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags) be supported/enabled.

### `DeltaLFMulti`

Related to AV1 syntax delta_lf_params().

### `DeltaLFRes`

Related to AV1 syntax delta_lf_params().

## Remarks

This structure is related to AV1 syntax delta_lf_params().

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags)

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095)