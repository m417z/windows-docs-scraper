## Description

The **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080** enumeration lists the possible frame subregion encoding modes.

## Constants

### `D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_FULL_FRAME:0`

Full frame output support.

### `D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_BYTES_PER_SUBREGION:1`

Indicates support for frame subregions to be set as a number of bytes per subregion.

### `D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_SQUARE_UNITS_PER_SUBREGION_ROW_UNALIGNED:2`

Indicates support for frame subregions to be set as a number of squared blocks per subregion. The number of squared blocks does not need to be a multiple of a row size in squared blocks; that is, the subregions do not need to be row-aligned. Use **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_UNIFORM_PARTITIONING_ROWS_PER_SUBREGION** or **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_UNIFORM_PARTITIONING_SUBREGIONS_PER_FRAME** if you need to set a row-aligned number of squared blocks.

### `D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_UNIFORM_PARTITIONING_ROWS_PER_SUBREGION:3`

Divides the frame into a number of slices, determined by the number of rows per slice. The size of the row, in pixels, can be calculated using the current resolution and [**SubregionBlockPixelsSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) for the current frame resolution.

### `D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_UNIFORM_PARTITIONING_SUBREGIONS_PER_FRAME:4`

Specifies the number of slices to divide the frame into.

### `D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0095_UNIFORM_GRID_PARTITION:5`

Added in Windows 11, version 24H2 (WDDM 3.2). Allows the driver to uniformly partition the frame into a grid with only input from the API Client being number of rows and columns. Driver will return the heights and widths of each cell in the partitioned grid after the execution of the EncodeFrame command in resolved metadata buffer.

For the AV1 codec, This corresponds to the AV1 spec syntax uniform_tile_spacing_flag equal to 1, when using D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_UNIFORM_GRID_PARTITION, tiles are uniformly partitioned except the right and bottom edges. When the dimensions cannot be partitioned exactly, the last tile can have smaller size.

### `D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0095_CONFIGURABLE_GRID_PARTITION:6`

Added in Windows 11, version 24H2 (WDDM 3.2). Allows the API Client to fully customize a grid partition of the frame. API Client will pass a list of rows and columns along with the heights and widths of each cell in the partitioned grid in the EncodeFrame command and they have to be honored exactly.

For the AV1 codec, this corresponds to uniform_tile_spacing_flag equal to 0 means that the tile sizes are coded.

## Remarks

For further tile support details, please check the associated tile details support cap D3D12_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2)

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0)