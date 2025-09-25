## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095** structure describes the AV1 frame subregion layout configuration support settings for the AV1 encoder.

## Members

### `Use128SuperBlocks`

Input parameter. Boolean that indicates whether the encoder uses 128x128 superblocks. Otherwise the superblock default size 64x64 must be used.

### `TilesConfiguration`

Input parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_TILES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_subregions_layout_data_tiles_0095) structure that specifies the tile configuration to check for support for.

### `ValidationFlags`

Input parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_frame_subregion_layout_config_validation_0095_flags) enumeration that specifies the flags for the AV1 frame subregion layout configuration validation. Indicates more details when [**D3D12DDI_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_feature_data_video_encoder_frame_subregion_layout_config_0095)**.IsSupported** is false.

### `MinTileRows`

Output parameter. Minimum number of horizontal partitions.

### `MaxTileRows`

Output parameter. Maximum number of horizontal partitions.

### `MinTileCols`

Output parameter. Minimum number of vertical partitions.

### `MaxTileCols`

Output parameter. Maximum number of vertical partitions.

### `MinTileWidth`

Output parameter. Minimum width of any tile, in superblock units.

### `MaxTileWidth`

Output parameter. Maximum width of any tile, in superblock units.

### `MinTileArea`

Output parameter. Minimum dimension of any tile, in superblock units.

### `MaxTileArea`

Output parameter. Maximum dimension of any tile, in superblock units.

### `TileSizeBytesMinus1`

Output parameter. Specifies the number of bytes needed to code each tile size. Related to the driver writing the [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_metadata_0083_0)**.bSize** elements in the resolved metadata. The API Client will write tile_size_bytes_minus_1 = (TileSizeBytesMinus1) in frame_header_obu/uncompressed_header/tile_info when writing the frame header OBU, and when writing le(TileSizeBytes) tile_size_minus_1 in tile_group_obu().

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_config_support_0095)