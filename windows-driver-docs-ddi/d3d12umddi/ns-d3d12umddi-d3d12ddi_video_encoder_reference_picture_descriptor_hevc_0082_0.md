## Description

The **D3D12DDI_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_HEVC_0082_0** structure represents a reference picture descriptor for HEVC video encoding.

## Members

### `ReconstructedPictureResourceIndex`

Maps the current reference picture described by this structure to a resource in the [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0) array.

### `IsRefUsedByCurrentPic`

Set when this descriptor entry is being used by the current picture by being indexed from the L0 and/or L1 lists.

### `IsLongTermReference`

Set when the described reference frame is being used as a long-term reference picture.

### `PictureOrderCountNumber`

Indicates the described reference frame display order.

### `TemporalLayerIndex`

Picture layer number in temporal hierarchy. Check [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0) for the maximum number of layers.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_hevc_0082_0)