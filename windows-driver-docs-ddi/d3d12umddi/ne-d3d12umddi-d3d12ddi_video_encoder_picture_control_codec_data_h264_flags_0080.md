## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAGS_0080** enumeration specifies flags for the H.264-specific picture control properties.

## Constants

### `D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAG_0080_NONE`

No flags.

### `D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAG_0080_REQUEST_INTRA_CONSTRAINED_SLICES`

Requests slice-constrained encoding for this frame, in which every slice in a frame is encoded independently from other slices in the same frame. Check [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080) for support. This mode restricts the motion vector search range to the region box of the current slice; that is, motion vectors cannot be used outside the slice boundary.

### `D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAG_0099_0_REQUEST_NUM_REF_IDX_ACTIVE_OVERRIDE_FLAG_SLICE`

Requests an override of the number of active reference indices for slice encoding. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080)

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_0082_0)