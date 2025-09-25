## Description

The **D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0** structure contains the input sequence and picture control parameters for a video encode operation.

## Members

### `SequenceControlDesc`

A [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0) structure that defines the configuration for the video sequence.

### `PictureControlDesc`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0) structure that defines the configuration for the video picture.

### `hDrvInputTexture2D`

Handle to the input frame to encode. This input frame is a D3D12 resource that can be consumed by other portions of the pipeline and therefore must not have the [**D3D12DDI_RESOURCE_FLAG_0080_VIDEO_ENCODE_REFERENCE_ONLY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_flags_0003) flag set.

### `InputFrameSubresource`

The sub-resource index for the **hDrvInputTexture2D** resource.

### `CurrentFrameBitstreamMetadataSize`

Number of bytes added to the final bitstream between the end of the last [**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) compressed bitstream output and the current call output. This member is intended to capture the size of any headers or metadata messages added by the client to the final bitstream. It is intended to be used as a hint by the rate control algorithms to keep track of the full bitstream size.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_STREAM_ARGUMENTS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_output_stream_arguments_0080_2)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)