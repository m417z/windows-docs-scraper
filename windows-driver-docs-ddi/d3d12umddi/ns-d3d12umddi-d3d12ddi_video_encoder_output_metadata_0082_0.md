## Description

The **D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0082_0** structure represents the metadata of the output of an [encoding operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0). Use [**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## Members

### `EncodeErrorFlags`

A UINT64 value that represents flag(s) from the [**D3D12DDI_VIDEO_ENCODER_ENCODE_ERROR_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_encode_error_flags_0082_0) enumeration that specify information about the encode execution status.

### `EncodedBitstreamWrittenBytesCount`

The number of bytes that were written into [**D3D12DDI_VIDEO_ENCODER_COMPRESSED_BITSTREAM_0080.hDrvBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_compressed_bitstream_0080) plus **D3D12DDI_VIDEO_ENCODER_COMPRESSED_BITSTREAM_0080.Offset**.

### `WrittenSubregionsCount`

The number of sub-regions used to encode the current frame. This value must be coherent with the settings specified in [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0.FrameSubregionsLayoutData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0); that is, if a number of sub-regions was previously specified, **WrittenSubregionsCount** should match that value. If another mode was used, the driver uses this field to report the final number of sub-regions. If the output is one full frame, then there is only one sub-region.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0) for full video encoding feature support for Windows 11 (WDDM 3.0).