# D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_DESC_0032 structure

## Description

**D3D12DDI_VIDEO_PROCESS_OUTPUT_STREAM_DESC_0032** describes output stream properties for the video processor.

## Members

### `Format`

The DXGI format of the output texture.

### `ColorSpace`

The color space for the video processor output surface as a [**DXGI_COLOR_SPACE_TYPE**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) value.

### `AlphaFillMode`

The alpha fill mode for data that the video processor writes to the render target. See [**D3D12DDI_VIDEO_PROCESSOR_ALPHA_FILL_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_alpha_fill_mode_0020).

### `AlphaFillModeSourceStreamIndex`

The zero-based index of an input stream. This field is used if **AlphaFillMode** has the value **D3D12DDI_VIDEO_PROCESS_ALPHA_FILL_MODE_SOURCE_STREAM**. Otherwise, it is ignored.

### `BackgroundColor`

The video processor uses the background color to fill areas of the target rectangle that don't contain a video image. Areas outside the target rectangle aren't affected. The meaning of the values is specified by the **ColorSpace** member.

| Value | YCbCrA | RGBA |
| ----- | ------ | ---- |
| BackgroundColor[0] | Y | R |
| BackgroundColor[1] | Cb | G |
| BackgroundColor[2] | Cr | B |
| BackgroundColor[3] | A | A |

### `FrameRate`

The frame rate of the output video stream, specified as a [**DXGI_RATIONAL**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure.

### `EnableStereo`

If TRUE, stereo output is enabled. Otherwise, the video processor produces mono video frames.

## See also

[**PFND3D12DDI_VIDEO_PROCESS_FRAME_0043**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_process_frame_0043)