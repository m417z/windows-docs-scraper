## Description

The **D3D12DDI_VIDEO_ENCODER_COMPRESSED_BITSTREAM_0080** structure encapsulates the compressed bitstream output for the encoding operation.

## Members

### `hDrvBuffer`

Resource handle for the buffer that contains the compressed bitstream. The resource buffer size is not the available size for this encoding operation. Specifically, the available size for the current frame output in this buffer is the size of this buffer minus **Offset**.

### `Offset`

The offset into the compressed bitstream where the encoder can start adding the current frame output, in bytes.

## Remarks

The output bitstream is expected to contain the sub-region headers but not the picture, sequence, video, or other headers. It is the host's responsibility to code these other headers and generate the complete bitstream.

In sub-region frame partitioning, all sub-regions for a given frame encoding operation output must be placed in top/down, left/right order and must be contiguous.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_STREAM_ARGUMENTS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_output_stream_arguments_0080_2)