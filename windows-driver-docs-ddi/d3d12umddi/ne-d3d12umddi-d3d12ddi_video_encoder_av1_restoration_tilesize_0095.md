## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE_0095** corresponds to the size of loop restoration units, in units of samples in the current plane.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE_0095_DISABLED:0`

Indicates that no loop restoration is to be applied.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE_0095_32x32:1`

Indicates that the loop restoration tile size is 32x32.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE_0095_64x64:2`

Indicates that the loop restoration tile size is 64x64.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE_0095_128x128:3`

Indicates that the loop restoration tile size is 128x128.

### `D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE_0095_256x256:4`

Indicates that the loop restoration tile size is 256x256.

## Remarks

The enum values are based on lr_unit_shift and lr_uv_shift in lr_params() AV1 syntax and the RESTORATION_TILESIZE_MAX(256) AV1 spec constant.

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_restoration_config_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TYPE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_restoration_type_0095)