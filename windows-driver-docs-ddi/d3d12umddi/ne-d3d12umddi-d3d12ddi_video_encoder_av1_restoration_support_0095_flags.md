## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_0095_FLAGS** enumeration is a bitwise OR of values that define the loop restoration tile sizes that the encoder supports.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_0095_FLAG_NOT_SUPPORTED:0`

Indicates that the encoder does not support loop restoration.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_0095_FLAG_32x32:0x1`

Indicates that the encoder supports a 32x32 loop restoration tile size.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_0095_FLAG_64x64:0x2`

Indicates that the encoder supports a 64x64 loop restoration tile size.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_0095_FLAG_128x128:0x4`

Indicates that the encoder supports a 128x128 loop restoration tile size.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_0095_FLAG_256x256:0x8`

Indicates that the encoder supports a 256x256 loop restoration tile size.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_support_0095)