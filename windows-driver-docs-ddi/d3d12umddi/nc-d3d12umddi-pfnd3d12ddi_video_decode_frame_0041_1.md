# PFND3D12DDI_VIDEO_DECODE_FRAME_0041_1 callback function

## Description

Implemented by the client driver to decode a video frame.

## Parameters

### `hDrvCommandList`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `hDrvDecoder`

The video decoder that contains internal state for this decode session. Examples include motion vectors, internal temporary allocations, etc. See [Creating a Video Decoder](https://learn.microsoft.com/windows-hardware/drivers/display/creating-a-video-decode-device).

### `pOutputStreamParameters`

Specifies the output surface and output parameters. See [D3D12DDI_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_output_stream_arguments_0041_1).

### `pInputStreamParameters`

Specifies the input bit stream, parameters, reference frames, and other input parameters for the decode operation. See [D3D12DDI_VIDEO_DECODE_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_input_stream_arguments_0032).