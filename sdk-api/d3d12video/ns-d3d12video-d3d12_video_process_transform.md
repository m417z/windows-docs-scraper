# D3D12_VIDEO_PROCESS_TRANSFORM structure

## Description

Specifies transform parameters for video processing. Used by the [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments) structure.

## Members

### `SourceRectangle`

Specifies the source rectangle of the transform. This is the portion of the input surface that is blitted to the destination surface. The source rectangle is given in pixel coordinates, relative to the input surface.

### `DestinationRectangle`

Specifies the destination rectangle of the transform. This is the portion of the output surface that receives the blit for this stream. The destination rectangle is given in pixel coordinates, relative to the output surface.

### `Orientation`

The rotation and flip operation to apply to the source. Source and Destination rectangles are specified in post orientation coordinates.

## Remarks

For stereo formats, the orientation is applied before the stereo format is applied.

## See also