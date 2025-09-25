# PFND3D12DDI_VIDEO_PROCESS_FRAME_0032 callback function

## Description

Performs a video processing operation on one or more input samples and writes the result to an output surface

## Parameters

### `hDrvCommandList`

The command list used to record this process frames command.

### `hDrvVideoProcessor`

The video processor instance to use for this video process call. The video processor holds state for a video processing session, including required intermediate memory, cached processing data, or other temporary working space.

### `pOutputParameters`

The output arguments for the video process. The available parameters are in the [D3D12DDIARG_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_output_stream_arguments_0032) structure.

### `pInputStreamParameters`

Specifies an array of input parameters. The available parameters are in the [D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_input_stream_arguments_0043) structure.

### `NumInputStreams`

The count of input streams.