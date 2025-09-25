## Description

Represents a reference picture descriptor for H.264 video encoding.

## Members

### `ReconstructedPictureResourceIndex`

Maps the current reference picture described by this structure to a resource in the [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC.ReferenceFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_desc) array.

### `IsLongTermReference`

Set when the described reference frame is being used as a long-term reference picture.

### `LongTermPictureIdx`

If used as a long term reference, indicates the long-term reference index number.

### `PictureOrderCountNumber`

The described reference frame display order.

### `FrameDecodingOrderNumber`

The frame decode order with semantic as indicated by the slice header *frame_num* syntax element associated with the encoded reference picture.

### `TemporalLayerIndex`

Picture layer number in temporal hierarchy. Please check for maximum number of layers in [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration_support_h264).

## Remarks

## See also