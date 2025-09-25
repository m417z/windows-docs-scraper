# D3D12DDI_VIDEO_PROCESS_TRANSFORM_0032 structure

## Description

The **D3D12DDI_VIDEO_PROCESS_TRANSFORM_0032** structure specifies the flip, rotation, scale, and destination translation for the video input.

## Members

### `SourceRectangle`

The source rectangle is the portion of the input surface that is blitted (bit block transferred) to the destination surface. The source rectangle is given in pixel coordinates, relative to the input surface. Stereo format after orientation is applied.

### `DestinationRectangle`

The destination rectangle is the portion of the output surface that receives the blt for this stream. The destination rectangle is given in pixel coordinates, relative to the output surface.

### `Orientation`

A [**D3D12DDI_VIDEO_PROCESS_ORIENTATION_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_orientation_0020) value that specifies the rotation and flip operation to apply to the source. Source and Destination rectangles are specified in post orientation coordinates.

## See also

[**D3D12DDIARG_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS_0043**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_process_input_stream_arguments_0043)