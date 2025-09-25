## Description

Represents a reference picture descriptor for HEVC video encoding.

## Members

### `ReconstructedPictureResourceIndex`

A **UINT** that maps the current reference picture described by this structure to a resource in the [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC.ReferenceFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_desc) array.

### `IsRefUsedByCurrentPic`

A **BOOL** indicating whether this descriptor entry is being used by the current picture by being indexed from either L0 and/or L1 lists.

### `IsLongTermReference`

A **BOOL** that is set to true when the described reference frame is being used as a long-term reference picture.

### `PictureOrderCountNumber`

A **UINT** specifying the described reference frame display order.

### `TemporalLayerIndex`

A **UINT** specifying the picture layer number in temporal hierarchy. Check for maximum number of layers in [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration_support_hevc).

## Remarks

## See also