## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_SLICES_0080** structure defines subregions as slices for codecs that support this partitioning mode.

## Members

### `MaxBytesPerSlice`

This member is used exclusively with [**VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_BYTES_PER_SUBREGION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080). **MaxBytesPerSlice** specifies the maximum number of bytes per slice to be used.

### `NumberOfCodingUnitsPerSlice`

This member is used exclusively with [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_SQUARE_UNITS_PER_SUBREGION_ROW_UNALIGNED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080). **NumberOfCodingUnitsPerSlice** specifies the number of squared blocks to be used per slice. The size in pixels of the squared regions can be calculated using the current resolution and [**SubregionBlockPixelsSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) for the current frame resolution.

### `NumberOfRowsPerSlice`

This member is used exclusively with [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_UNIFORM_PARTITIONING_ROWS_PER_SUBREGION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080). **NumberofRowsPerSlice** specifies the number of squared blocks rows per slice for the frame to be divided into. The size in pixels of the squared regions can be calculated using the current resolution and [**SubregionBlockPixelsSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) for the current frame resolution.

### `NumberOfSlicesPerFrame`

This member is used exclusively with [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_UNIFORM_PARTITIONING_SUBREGIONS_PER_FRAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080). **NumberOfSlicesPerFrame** specifies the number of slices to divide the frame into.

## Remarks

For modes that imply a fixed number of slices, the number of slices selected must be less than [**MaxSubregionsNumber**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) and the selected resolution.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080)

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_subregions_layout_data_0080_2)

[**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2)