## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_AV1_LOOP_FILTER_CONFIG_0095** structure describes the loop filter configuration for the AV1 encoder.

## Members

### `LoopFilterLevel[2]`

Related to AV1 syntax loop_filter_level[0], loop_filter_level[1].

### `LoopFilterLevelU`

Related to AV1 syntax loop_filter_level[2].

### `LoopFilterLevelV`

Related to AV1 syntax loop_filter_level[3].

### `LoopFilterSharpnessLevel`

Related to AV1 syntax loop_filter_sharpness.

### `LoopFilterDeltaEnabled`

Related to AV1 syntax loop_filter_delta_enabled. Requires that[**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAG_LOOP_FILTER_DELTAS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags) be supported/enabled.

### `UpdateRefDelta`

Related to AV1 syntax update_ref_delta.

### `RefDeltas[8]`

Related to AV1 syntax loop_filter_ref_deltas.

### `UpdateModeDelta`

Related to AV1 syntax update_mode_delta.

### `ModeDeltas[2]`

Related to AV1 syntax loop_filter_mode_deltas.

## Remarks

AV1 syntax loop_filter_delta_update is derived from members as (**UpdateRefDelta** || **UpdateModeDelta**).

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags)

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095)