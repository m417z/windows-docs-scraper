## Description

Defines subregions as slices for codecs that support this partitioning mode.

## Members

### `MaxBytesPerSlice`

The maximum number of bytes per slice to be used. This field is used exclusively with [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_BYTES_PER_SUBREGION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_subregion_layout_mode).

### `NumberOfCodingUnitsPerSlice`

The number of squared blocks to be used per slice. The size in pixels of the squared regions can be calculated using the current resolution and [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS.SubregionBlockPixelsSize](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits) for the current frame resolution. This field is used exclusively with [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_SQUARE_UNITS_PER_SUBREGION_ROW_UNALIGNED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_subregion_layout_mode).

### `NumberOfRowsPerSlice`

The number of squared blocks rows per slice for the frame to be divided into. The size in pixels of the squared regions can be calculated using the current resolution and [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS.SubregionBlockPixelsSize](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits) for the current frame resolution. This field is used exclusively with [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_UNIFORM_PARTITIONING_ROWS_PER_SUBREGION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_subregion_layout_mode).

### `NumberOfSlicesPerFrame`

The number of slices to divide the frame into. This field is used exclusively with [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_UNIFORM_PARTITIONING_SUBREGIONS_PER_FRAME](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_subregion_layout_mode).

## Remarks

For modes that imply a fixed number of slices, the number of slices selected must be less than indicated by [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS.MaxSubregionsNumber](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits) and the selected resolution.

## See also