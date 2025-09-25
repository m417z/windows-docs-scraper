## Description

Specifies video encoder frame subregion layout modes.

## Constants

### `D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_FULL_FRAME`

Full frame output support.

### `D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_BYTES_PER_SUBREGION`

Frame subregions are set as a number of bytes per subregion.

### `D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_SQUARE_UNITS_PER_SUBREGION_ROW_UNALIGNED`

Frame subregions are set as a number of squared blocks per subregion. The number of squared blocks does not need to be multiple of a row size in squared blocks (e.g. if the subregions don't need to be row-aligned). To set row-aligned number of squared blocks per subregion, use the D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_UNIFORM_PARTITIONING_ROWS_PER_SUBREGION or D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_UNIFORM_PARTITIONING_SUBREGIONS_PER_FRAME mode.

### `D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_UNIFORM_PARTITIONING_ROWS_PER_SUBREGION`

Frames are divided into a number of slices determined by the number of rows per slice. The size in pixels of the rows can be calculated using the current resolution and [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS.SubregionBlockPixelsSize](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits) for the current frame resolution.

### `D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_UNIFORM_PARTITIONING_SUBREGIONS_PER_FRAME`

Frames are divided into the specified number of slices.

## Remarks

## See also