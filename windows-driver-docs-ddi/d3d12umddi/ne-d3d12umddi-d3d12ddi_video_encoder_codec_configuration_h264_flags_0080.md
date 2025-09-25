## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAGS_0080** enumeration lists the possible set of enabled features for an H.264 codec.

## Constants

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_NONE_0080`

No flags are specified.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_USE_CONSTRAINED_INTRAPREDICTION_0080`

When set, this flag forces the encoding of each intra-coded block with residual data only from other intra-coded blocks in the frame (and not from inter-coded blocks, for example). Check the [**D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_FLAGS_H264_CONSTRAINED_INTRAPREDICTION_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080) flag for support. This flag refers to *constrained_intra_pred_flag* in the H.264 Picture Parameter Set (PPS).

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_USE_ADAPTIVE_8x8_TRANSFORM_0080`

When set, this flag enables the usage of adaptive 8x8 transforms. Check the [**D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_FLAGS_H264_ADAPTIVE_8x8_TRANSFORM_ENCODING_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080) flag for support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_ENABLE_CABAC_ENCODING_0080`

When set, this flag enables entropy coding using the context-adaptive binary arithmetic coding (CABAC) algorithm. When this flag is not set, the context-adaptive variable-length coding (CAVLC) algorithm is used. Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_CABAC_ENCODING_SUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080) flag for CABAC support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_ALLOW_REQUEST_INTRA_CONSTRAINED_SLICES_0080`

When set, the user can request, for each frame with a special flag in the picture control structure, that slices of such a frame be coded independent of each other. This mode restricts the motion vector search range to the region box of the current slice (for example, motion vectors cannot be used outside of the slice boundary).

## Remarks

Flags can be combined.

The host (D3D12 lower-level encoding API) sets these configuration flags based on the limits queried at the API level.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_0080_2)

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080)