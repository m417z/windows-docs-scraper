# D3D11_VIDEO_COLOR structure

## Description

Defines a color value for Microsoft Direct3D 11 video.

## Members

### `YCbCr`

A [D3D11_VIDEO_COLOR_YCbCrA](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_color_ycbcra) structure that contains a YCbCr color value.

### `RGBA`

A [D3D11_VIDEO_COLOR_RGBA](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_color_rgba) structure that contains an RGB color value.

## Remarks

The anonymous union can represent both RGB and YCbCr colors. The interpretation of the union depends on the context.

## See also

[About YUV Video](https://learn.microsoft.com/windows/desktop/medfound/about-yuv-video)

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)