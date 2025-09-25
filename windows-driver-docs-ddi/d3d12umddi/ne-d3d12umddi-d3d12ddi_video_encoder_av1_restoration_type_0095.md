## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TYPE_0095** enumeration defines the list of distinct restoration filter types that can be used in the AV1 video encoding process, where each value represents a specific restoration filter.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TYPE_0095_DISABLED:0`

Indicates that no restoration filter is to be applied.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TYPE_0095_SWITCHABLE:1`

Indicates that the encoder can choose between the Wiener and Sgrproj restoration filters.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TYPE_0095_WIENER:2`

Indicates that the Wiener restoration filter should be applied.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TYPE_0095_SGRPROJ:3`

Indicates that the Self-Guided Restoration (Sgrproj) restoration filter should be applied.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_restoration_config_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)