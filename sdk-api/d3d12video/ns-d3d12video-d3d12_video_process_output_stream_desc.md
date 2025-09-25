# D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC structure

## Description

Specifies output stream arguments for the output passed to [ID3D12VideoProcessCommandList::ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes).

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) structure specifying the format of the output resources.

### `ColorSpace`

A [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) value that specifies the colorspace for the video processor output surface.

### `AlphaFillMode`

A value from the [D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_alpha_fill_mode) enumeration specifying the alpha fill mode for data that the video processor writes to the render target.

### `AlphaFillModeSourceStreamIndex`

The zero-based index of an input stream. This parameter is used if *AlphaFillMode* is [D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE_SOURCE_STREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_alpha_fill_mode). Otherwise, the parameter is ignored.

### `BackgroundColor`

The video processor uses the background color to fill areas of the target rectangle that do not contain a video image. Areas outside the target rectangle are not affected. The meaning of the values are specified by the *ColorSpace* parameter.

| BackgroundColor | YCbCrA | RGBA |
|-------------------|----------|---------|
| BackgroundColor[0]| Y | R |
| BackgroundColor[1]| Cb | G |
| BackgroundColor[2]| Cr | B |
| BackgroundColor[3]| A | A |

### `FrameRate`

A [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure specifying the frame rate of the output video stream.

### `EnableStereo`

If TRUE, stereo output is enabled. Otherwise, the video processor produces mono video frames.

## Remarks

## See also