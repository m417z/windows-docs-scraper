## Description

The **D3D12DDI_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_H264_0080** structure represents a reference picture descriptor for H.264 video encoding.

## Members

### `ReconstructedPictureResourceIndex`

Maps the current reference picture described by this structure to a resource in the [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0) array.

### `IsLongTermReference`

Set when the described reference frame is being used as a long-term reference picture.

### `LongTermPictureIdx`

If **IsLongTermReference** is set, this value specifies the long-term reference index number.

### `PictureOrderCountNumber`

Indicates the described reference frame display order.

### `FrameDecodingOrderNumber`

The frame *decode* order with semantics as indicated by the slice header *frame*num* syntax element associated with the encoded reference picture.

### `TemporalLayerIndex`

Picture layer number in temporal hierarchy. Check [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0082_0) for the maximum number of layers.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0)

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_0082_0)