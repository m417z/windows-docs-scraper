## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_TILES_0095** structure contains the tile layout data for AV1 picture control subregions.

## Members

### `RowCount`

Number of tile rows in the frame.

### `ColCount`

Number of tile columns in the frame.

### `RowHeights[D3D12DDI_VIDEO_ENCODER_AV1_MAX_TILE_ROWS_0095]`

Array of tile row heights, where each element represents the height of the corresponding tile row in pixels.

### `ColWidths[D3D12DDI_VIDEO_ENCODER_AV1_MAX_TILE_COLS_0095]`

Array of tile column widths, where each element represents the width of the corresponding tile column in pixels.

### `ContextUpdateTileId`

Related to AV1 syntax context_update_tile_id.

## Remarks

This structure operates in different ways using different [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080) configurations.

* For **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0095_CONFIGURABLE_GRID_PARTITION**:

  * Input parameters: **RowCount**, **ColCount**, **RowHeights**, **ColWidths** within the reported tile caps. The integer values must match the AV1 codec standard expectations (ie. power of two, etc).
  * The driver honors exactly and copies the exact same structure after [*EncodeFrame*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) execution.

* For **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0095_UNIFORM_GRID_PARTITION**:

  * Input parameters: **RowCount**, **ColCount**. The integer values must match the AV1 codec standard expectations (ie. power of two, etc).
  * The driver copies **RowCount**/**ColCount** as passed by API Client, and returns also **RowHeights**, **ColWidths** after *EncodeFrame* execution.

For ContextUpdateTileId, is an input parameter from the API Client corresponding to the frame header context_update_tile_id AV1 syntax and if D3D12_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_FLAG_CONTEXT_UPDATE_TILE_ID was reported then the driver is able to overwrite the API client input after EncodeFrame execution, otherwise must be copied by the driver from the input to the post encode values.

Check the limitations for tile configuration returned in [**D3D12DDI_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_feature_data_video_encoder_frame_subregion_layout_config_0095) for AV1 codec.

**D3D12DDI_VIDEO_ENCODER_AV1_MAX_TILE_ROWS_0095** and **D3D12DDI_VIDEO_ENCODER_AV1_MAX_TILE_COLS_0095** are constants as defined in the AV1 codec specification. For the width and height parameter lists, make sure they fall under these AV1 codec standard-defined dimension limitations. The units of these arrays are measured in block of size [**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2)**.SubregionBlockPixelsSize**. For example if **ColHeights**[0] equals 2 and **SubregionBlockPixelsSize** equals 64,
then ```ColHeightInPixels**[0] = ColHeights[0] * SubregionBlockPixelsSize = 2 * 64 = 128```.

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_frame_subregion_layout_config_support_0095)

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_subregions_layout_data_0080_2)