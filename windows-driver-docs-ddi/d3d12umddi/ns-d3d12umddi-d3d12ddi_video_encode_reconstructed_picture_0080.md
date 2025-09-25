## Description

The**D3D12DDI_VIDEO_ENCODE_RECONSTRUCTED_PICTURE_0080** structure encapsulates the reconstructed picture generated from the input frame passed to the encode operation.

## Members

### `hDrvTexture2D`

Handle to the reconstructed picture generated from the input frame.

### `InputFrameSubresource`

The sub-resource index for **hDrvTexture2D**.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_input_stream_arguments_0082_0)

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_STREAM_ARGUMENTS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_output_stream_arguments_0080_2)