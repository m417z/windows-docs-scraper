# D3D11_1DDI_VIDEO_COLOR structure

## Description

Defines a color value for Microsoft Direct3D 11 video.

## Members

### `YCbCr`

A [D3D11_1DDI_VIDEO_COLOR_YCbCrA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_color_ycbcra) structure that contains a YCbCr color value.

### `RGBA`

A [D3D11_1DDI_VIDEO_COLOR_RGBA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_color_rgba) structure that contains an RGB color value.

## Remarks

The anonymous union can represent both RGB and YCbCr colors. The interpretation of the union depends on the context.

## See also

[D3D11_1DDI_VIDEO_COLOR_RGBA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_color_rgba)

[D3D11_1DDI_VIDEO_COLOR_YCbCrA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_color_ycbcra)