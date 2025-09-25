## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_DESCRIPTOR_0095** structure describes a reference picture used in AV1 encoding.

## Members

### `ReconstructedPictureResourceIndex`

Maps the current reference picture described by this structure to a resource in the [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0)**.ReferenceFrames** array.

If the associated slot in [**ReferenceFramesReconPictureDescriptors**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095) containing this structure has a valid **ReconstructedPictureResourceIndex** reference to the **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames** array then the allowed range of values is [0..254]. Otherwise, if it corresponds to an empty/unused slot in the decoded picture buffer (DPB), then the value must be set to D3D12_VIDEO_ENCODER_AV1_INVALID_DPB_RESOURCE_INDEX.

### `TemporalLayerIndexPlus1`

The temporal layer index of the reference picture incremented by one of the previously encoded frame now used as reference.

### `SpatialLayerIndexPlus1`

Picture spatial layer index plus one of the previously encoded frame now used as reference.

### `FrameType`

A [**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_TYPE_0095](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_frame_type_0095) value that specifies the type of frame used to encode the described reference frame associated to this entry.

### `WarpedMotionInfo`

A [**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_reference_picture_warped_motion_info_0095) structure that contains the global motion parameters. Only used if supported in [**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_reference_warped_motion_transformation_0095_flags).

### `OrderHint`

The reference ref_order_hint AV1 syntax. Even when reference order hints are not coded in the AV1 bitstream, **OrderHint** here must be set to the value used in [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)**.OrderHint** for the previously encoded frame that is now being held as reference by this descriptor. This information hints to the driver, in a frame type that allows frame references, which are from past frames and which are from future frames (in display order) when comparing against the current frame value of **D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095.OrderHint**.

### `PictureIndex`

The unique picture index of the previously encoded frame that is stored in this entry as a reference. This parameter is not related in any way to the AV1 standard syntax, but merely used for API client implementation tracking instead.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)