# PFND3D12DDI_VIDEO_PROCESS_FRAME_0043 callback function

## Description

The **PFND3D12DDI_VIDEO_PROCESS_FRAME_0043** callback function performs a video processing operation on one or more input samples and writes the result to an output surface.

## Parameters

### `hDrvCommandList`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `hDrvVideoProcessor`

The video processor instance to use for this video process call.

### `pOutputParameters`

A [**D3D12DDIARG_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_output_stream_arguments_0032) structure to hold the output arguments for the video process.

### `pInputStreamParameters`

A [**D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS_0043**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_input_stream_arguments_0043) structure with the input arguments for the video process.

### `NumInputStreams`

The number of input streams.