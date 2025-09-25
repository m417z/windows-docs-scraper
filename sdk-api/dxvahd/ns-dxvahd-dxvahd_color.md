## Description

Defines a color value for DXVA-HD.

## Members

### `RGB`

A [DXVAHD_COLOR_RGBA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_color_rgba) structure that contains an RGB color value.

### `YCbCr`

A [DXVAHD_COLOR_YCbCrA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_color_ycbcra) structure that contains a YCbCr color value.

## Remarks

This union can represent both RGB and YCbCr colors. The interpretation of the union depends on the context.

## See also