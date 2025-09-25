## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095** structure contains configuration information for segmentation for an AV1 frame.

## Members

### `UpdateMap`

A flag indicating whether the segmentation map should be updated for the current frame. If set, the encoder will use the new segmentation map provided in the [**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MAP_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_map_0095) structure.

### `TemporalUpdate`

A flag indicating whether the segmentation map is updated based on temporal information. If set, segments may be predicted from previous frames.

### `UpdateData`

A flag indicating whether the data for the segments should be updated. If set, the encoder will use the new data provided in the **SegmentsData** array.

### `NumSegments`

When using [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_FRAME_SEGMENTATION_AUTO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_0095_flags) and the driver writes it back on post encode values, a value of **NumSegments** = 0 indicated that segmentation_enabled must be 0 in the frame header. Otherwise, the API client codes segmentation_params() in the frame header accordingly with the other parameters in this structure.

When using [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_FRAME_SEGMENTATION_CUSTOM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_0095_flags), indicates the input number of segments.

### `SegmentsData[8]`

Array of [**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENT_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_segment_data_0095) structures that contain the data for each segment. The number of elements in the array is specified by **NumSegments**.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095)