## Description

The **D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_STREAM_ARGUMENTS_0080_2** structure contains the parameters for the output of a video encode operation.

## Members

### `CompressedBitstream`

A [**D3D12DDI_VIDEO_ENCODER_COMPRESSED_BITSTREAM_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_compressed_bitstream_0080) structure that encapsulates the compressed bitstream output for the encoding operation.

### `ReconstructedPicture`

A [**D3D12DDI_VIDEO_ENCODE_RECONSTRUCTED_PICTURE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encode_reconstructed_picture_0080) structure that encapsulates the reconstructed picture generated from the input frame passed to the encode operation. This resource is only needed if the encoded picture is marked to be used as a reference picture in the corresponding [picture control structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_0082_0) for this encode operation. Otherwise, this member can be set to NULL because the reconstructed picture will not be written in the output.

### `HWLayoutEncoderMetadataDrvBuffer`

A [**D3D12DDI_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encode_operation_metadata_buffer_0080_2) structure that contains metadata returned by the encoder regarding the hardware-specific layout of the output. This data needs to be resolved into a readable format using [**PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_resolve_output_metadata_0082_0).

## Remarks

Check for alignment requirements for the output resources used for the encoding operation.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_input_stream_arguments_0082_0)

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_resolve_output_metadata_0082_0)