## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0082_0** structure contains configuration information for an H.264 codec.

## Members

### `ConfigurationFlags`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_flags_0080) value that defines the set of enabled features. Flags can be combined.

### `DirectModeConfig`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_DIRECT_MODES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_direct_modes_0080) value that specifies configuration information related to DIRECT modes.

### `DisableDeblockingFilterConfig`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODES_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_modes_0082_0) value that specifies configuration information related to *disable_deblocking_filter_idc* syntax in the H.264 specification.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0082_0)