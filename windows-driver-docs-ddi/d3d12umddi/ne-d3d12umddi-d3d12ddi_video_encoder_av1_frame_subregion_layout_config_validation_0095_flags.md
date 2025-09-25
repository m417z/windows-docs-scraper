## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAGS** enumeration specifies the flags for the AV1 frame subregion layout configuration validation.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_NONE:0x0`

No flags are specified.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_NOT_SPECIFIED:0x1`

When this flag is set, indicates that the requested tiles configuration is not supported due to a reason not specified by any of the other flag categories.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_CODEC_CONSTRAINT:0x2`

When this flag is set, indicates that the requested tiles configuration is not supported due to codec constraints. An example on this for AV1 would be [**D3D12DDI_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_feature_data_video_encoder_frame_subregion_layout_config_0095)**.Level**.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_HARDWARE_CONSTRAINT:0x4`

When this flag is set, indicates that the requested tiles configuration is not supported due to hardware constraints.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_ROWS_COUNT:0x8`

When this flag is set, indicates that the number of tile rows requested is not supported.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_COLS_COUNT:0x10`

When this flag is set, indicates that the number of tile columns requested is not supported.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_WIDTH:0x20`

When this flag is set, indicates that one or more tiles widths in the requested configuration is not supported.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_AREA:0x40`

When this flag is set, indicates that one or more tiles areas in the requested configuration is not supported.

### `D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAG_TOTAL_TILES:0x80`

When this flag is set, indicates that the total number of tiles in the requested partition exceeds the total supported tiles count. Please see [**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2)**.MaxSubregionsNumber**.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_frame_subregion_layout_config_support_0095)