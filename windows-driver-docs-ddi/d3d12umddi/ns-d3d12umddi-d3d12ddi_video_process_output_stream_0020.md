# D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_0020 structure

## Description

The output stream for video processing commands, which points to a target surface.

## Members

### `hDrvTexture2D`

The output surfaces for the video process command.

### `Subresource`

The subresource indexes to use with the associated **hDrvTexture2D** member.

## See also

[**D3D12DDIARG_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_output_stream_arguments_0032)

[**PFND3D12DDI_VIDEO_PROCESS_FRAME_0043**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_process_frame_0043)