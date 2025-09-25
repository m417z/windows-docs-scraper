## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_AV1_QUANTIZATION_CONFIG_0095** structure contains configuration information related to the quantization settings within an AV1 video encoder.

## Members

### `BaseQIndex`

Related to AV1 syntax in quantization_params().

### `YDCDeltaQ`

Related to AV1 syntax in quantization_params().

### `UDCDeltaQ`

Related to AV1 syntax in quantization_params().

### `UACDeltaQ`

Related to AV1 syntax in quantization_params().

### `VDCDeltaQ`

Related to AV1 syntax in quantization_params().

### `VACDeltaQ`

Related to AV1 syntax in quantization_params().

### `UsingQMatrix`

Related to AV1 syntax in quantization_params().

### `QMY`

Related to AV1 syntax in quantization_params().

### `QMU`

Related to AV1 syntax in quantization_params().

### `QMV`

Related to AV1 syntax in quantization_params().

## Remarks

AV1 syntax separate_uv_delta_q will always be coded as 1.

AV1 syntax diff_uv_delta can be inferred if U and V AC/DC components are the same.

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095)