# D3D12DDIARG_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS_0032 structure

## Description

**D3D12DDIARG_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS_0032** specifies output stream parameters for the output to be processed by [**PFND3D12DDI_VIDEO_PROCESS_FRAME_0043**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_process_frame_0043).

## Members

### `OutputStream`

An array of [**D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_output_stream_0020) structures that describe the output surfaces for the video process command. If stereo output is enabled, index zero contains the left output while index 1 contains the right input. If stereo output is not enabled, only index 0 is used to specify the output while index 1 should be set to nullptr.

### `TargetRectangle`

A [**D3DDDI_RECT**](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-rect) structure with the target rectangle, which is the area within the destination surface where the output will be drawn. The target rectangle is given in pixel coordinates, relative to the destination surface.

## See also

[**PFND3D12DDI_VIDEO_PROCESS_FRAME_0043**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_process_frame_0043)