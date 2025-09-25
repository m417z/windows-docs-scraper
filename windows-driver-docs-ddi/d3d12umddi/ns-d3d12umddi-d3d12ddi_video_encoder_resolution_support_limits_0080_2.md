## Description

The **D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2** structure represents the video encoder resolution support limits for a [**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) structure.

## Members

### `MaxSubregionsNumber`

For H264 and HEVC, indicates the maximum number of subregions per frame supported by the encoder for the associated resolution. **MaxSubregionsNumber** is expected to be an absolute maximum limit of subregions per frame to be coded when mode is [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080_BYTES_PER_SUBREGION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080)

For AV1, indicates the maximum number of tiles supported by the hardware for the associated resolution.

### `MaxIntraRefreshFrameDuration`

Indicates the maximum number that can be used in [**D3D12DDI_VIDEO_ENCODER_INTRA_REFRESH_0080.IntraRefreshDuration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_intra_refresh_0080) for the associated resolution.

### `SubregionBlockPixelsSize`

For H264 and HEVC, indicates, for the associated resolution, the size in pixels of the squared regions that will be used to partition the frame for the subregion layout (slices) semantics. The resolution of the frame will be rounded up to be aligned to this value when the frame is partitioned in blocks. The configuration of the subregion partitioning will use a number of squared subregions that have their size in pixels according to the value of this member.

For AV1, indicates the tiles block sizes in pixels for the associated resolution. This value must be equal or a multiple of the superblock size, which is passed in the input **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION** parameter.

> [!NOTE]
>
> For HEVC encoding, this member indicates the resolution block alignment for the compressed bitstream. For example, if **SubregionBlockPixelsSize** equals 32, then *SPS.pic_width/height_in_luma_samples* must be aligned to this value and *SPS.conf_win_\*_offset/conformance_window_flag* indicate the difference between this aligned resolution and the current frame resolution indicated by [D3D12_RESOURCE_DESC.Dimension](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc) of the input video texture. **SubregionBlockPixelsSize** must be aligned to [D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0.MinLumaCodingUnitSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0) (minCUSize), so *SPS.pic_width/height_in_luma_samples* ends up aligned to minCUSize as required by the HEVC codec spec.

### `QPMapRegionPixelsSize`

For H264 and HEVC, indicates the size in pixels of the squared regions for the associated resolution that will be affected by each of the values in the QP map buffer in absolute or delta QP modes. The resolution of the frame will be rounded up to be aligned to this value when it's partitioned in blocks for QP maps and the number of QP values in those maps will be the number of blocks of these indicated pixel size that comprise a full frame.

For AV1, indicates for the associated resolution, the size in pixels of the squared regions that will be affected by each of the values in the QP map buffer in absolute or delta QP modes. The resolution of the frame will be rounded up to be aligned to this value when it’s partitioned in blocks for QP maps and the number of QP values in those maps will be the number of blocks of these indicated pixel size that comprise a full frame. This value must be equal or a multiple of the superblock size, which is passed in the input **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION** parameter.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)

[**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support_data_0083_0)