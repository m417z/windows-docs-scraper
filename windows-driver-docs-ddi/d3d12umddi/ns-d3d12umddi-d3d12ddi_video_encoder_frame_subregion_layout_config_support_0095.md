## Description

The **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095** structure describes support for the video encoder frame subregion layout configuration, particularly for the AV1 codec.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pAV1Support`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_frame_subregion_layout_config_support_0095) structure that describes the AV1 codec support for the video encoder frame subregion layout configuration.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_feature_data_video_encoder_frame_subregion_layout_config_0095)