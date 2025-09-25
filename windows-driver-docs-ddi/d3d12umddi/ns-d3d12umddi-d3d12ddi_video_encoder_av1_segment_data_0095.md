## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_SEGMENT_DATA_0095** structure contains segmentation data for a segment within an AV1 frame.

## Members

### `EnabledFeatures`

A bit mask combination of [**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_mode_0095_flags) values that indicates the segmentation modes that are enabled for the segment.

### `FeatureValue[8]`

For the enabled features in the **EnabledFeatures** bit mask, the array **FeatureValue** is indexed by [**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_mode_0095) - 1 for its associated feature value.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_config_0095)