## Description

The **D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0** structure represents the metadata of the output of an [encoding operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0).

## Members

### `EncodeErrorFlags`

A UINT64 value that represents flag(s) from the [**D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_encode_error_flags_0082_0) enumeration that specify information about the encode execution status.

### `EncodeStats`

A [**D3D12DDI_VIDEO_ENCODER_METADATA_STATISTICS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_metadata_statistics_0083_0) structure that provides statistics about the encode execution.

### `EncodedBitstreamWrittenBytesCount`

The number of bytes that were written into [**D3D12DDI_VIDEO_ENCODER_COMPRESSED_BITSTREAM_0080.hDrvBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_compressed_bitstream_0080) plus **D3D12DDI_VIDEO_ENCODER_COMPRESSED_BITSTREAM_0080.Offset**.

### `WrittenSubregionsCount`

The number of sub-regions used to encode the current frame. This value must be coherent with the settings specified in [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0.FrameSubregionsLayoutData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0); that is, if a number of sub-regions was previously specified, **WrittenSubregionsCount** should match that value. If another mode was used, the driver uses this field to report the final number of sub-regions. If the output is one full frame, then there is only one sub-region.

## Remarks

**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0** and its child structures are aligned to a 64-bit access boundary for use with [**PFND3D12DDI_SET_PREDICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_predication).

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolve_metadata_output_arguments_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_resolve_output_metadata_0082_0)

[**PFND3D12DDI_SET_PREDICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_predication)