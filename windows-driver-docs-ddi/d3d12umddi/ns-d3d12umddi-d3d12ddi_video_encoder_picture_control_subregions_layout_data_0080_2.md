## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_0080_2** structure defines picture control subregions as slices.

## Members

### `DataSize`

Size of the reference data, in bytes.

### `pSlicesPartition_H264`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_SLICES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_subregions_layout_data_slices_0080) structure that defines subregions as slices for H.264 encoding.

### `pSlicesPartition_HEVC`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_SLICES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_subregions_layout_data_slices_0080) structure that defines subregions as slices for HEVC encoding.

### `pTilesPartition_AV1`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_TILES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_subregions_layout_data_tiles_0095) structure that defines subregions as tiles for AV1 encoding. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_SLICES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_subregions_layout_data_slices_0080)

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0)