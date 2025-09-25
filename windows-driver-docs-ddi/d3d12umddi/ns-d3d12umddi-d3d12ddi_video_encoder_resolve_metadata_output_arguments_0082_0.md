## Description

The **D3D12DDI_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS_0082_0** structure represents output arguments from a call to [**PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_resolve_output_metadata_0082_0).

## Members

### `ResolvedLayoutEncoderMetadataDrvBuffer`

A [**D3D12DDI_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encode_operation_metadata_buffer_0080_2) structure in which the driver should store the resolved metadata. The caller needs to read back this buffer to the CPU and cast it to [**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0). The remaining data in the buffer is **D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0.WrittenSubregionsCount** *packed* entries of type [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_metadata_0083_0).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_metadata_0083_0)

[**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0)

[**PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_resolve_output_metadata_0082_0)