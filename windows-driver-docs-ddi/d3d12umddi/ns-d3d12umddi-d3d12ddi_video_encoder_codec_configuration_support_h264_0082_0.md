## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0** structure specifies the encoder codec support configuration limits for H.264 encoding.

## Members

### `SupportFlags`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080) value that indicates which optional feature(s) are supported for the codec.

### `DisableDeblockingFilterSupportedModes`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) value that indicates the allowed modes supported for *_disable_deblocking_filter_idc_syntax* in the H.264 specification.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_0083_0)