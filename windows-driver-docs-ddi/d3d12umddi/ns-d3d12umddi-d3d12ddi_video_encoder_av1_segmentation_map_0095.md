## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MAP_0095** structure contains segmentation map information for an AV1 frame.

## Members

### `SegmentsMapByteSize`

Size in bytes of the **pSegmentsMap** buffer.

### `pSegmentsMap`

In raster order, contains the AV1 syntax segment_id between [0..7] for each block in the frame. The block size is **SegmentationBlockSize** as reported by the driver in [**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_support_0095).

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)