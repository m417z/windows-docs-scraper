## Description

A client driver's **PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0** callback function records an encode frame operation to the command list.

## Parameters

### `hDrvCommandList` [in]

Handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `hDrvEncoder` [in]

Handle to a video encoder object. The handle was returned when the video encoder object was created.

### `hDrvVideoEncoderHeap` [in]

Handle to a video encoder heap object. The handle was returned when the video encoder heap object was created.

### `pInputStreamArguments` [in]

Pointer to a [**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_input_stream_arguments_0082_0) structure that contains the input sequence and picture control parameters for the encode operation.

### `pOutputStreamArguments` [out]

Pointer to a [**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_STREAM_ARGUMENTS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_output_stream_arguments_0080_2) structure in which the output of the encode operation is returned.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_input_stream_arguments_0082_0)

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_STREAM_ARGUMENTS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_output_stream_arguments_0080_2)

[**PFND3D12DDI_CREATE_COMMAND_LIST_0040**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_command_list_0040)

[**PFND3D12DDI_CREATEVIDEOENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoder_0082_0)

[**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2)