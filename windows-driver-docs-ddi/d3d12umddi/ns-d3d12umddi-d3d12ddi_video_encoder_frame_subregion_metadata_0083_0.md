## Description

The **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0083_0** structure represents subregion metadata of a video encoder frame.

## Members

### `bSize`

Output field in which to store the sizes of each sub-region, in bytes. Sub-regions sizes must include the sub-region initial padding, header, and payload.

### `bStartOffset`

Output field in which to store the padding size that needs to be skipped at the beginning of every subregion, in bytes. This padding size is included in **bSize**.

For example, let *pFrameSubregionsSizes* be an array of **bSize** bytes for each slice. With **bStartOffset** and *pFrameSubregionsSizes*, the user can extract individual subregions from the output bitstream buffer by calculating the *i*th sub-region start offset as ```pBuffer + FrameStartOffset + sum j = (0, (i-1)){pFrameSubregionsSizes[j]} + pFrameSubregionsStartOffsets[i]``` and reading ```pFrameSubregionsSizes[i]``` bytes.

### `bHeaderSize`

Output field in which to write the sizes in bits of each sub-region header.

With **bHeaderSize**, in addition to extracting the full sub-region from the bitstream as explained above, the user can extract the sub-regions payload and headers directly without needing to parse the full sub-region bitstream.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolve_metadata_output_arguments_0082_0)