## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_COMP_PREDICTION_TYPE_0095** enumeration defines the compound prediction types for an AV1 encoder.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_COMP_PREDICTION_TYPE_0095_SINGLE_REFERENCE:0`

Indicates that all inter blocks will use single prediction. Thie value is equivalent to AV1 syntax reference_select equal to 0.

### `D3D12DDI_VIDEO_ENCODER_AV1_COMP_PREDICTION_TYPE_0095_COMPOUND_REFERENCE:1`

Indicates that the mode info for inter blocks contains the syntax element comp_mode that indicates whether to use single or compound reference prediction. This value is equivalent to AV1 syntax reference_select equal to 1.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_AV1_PICTURE_CONTROL_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_av1_picture_control_support_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095)