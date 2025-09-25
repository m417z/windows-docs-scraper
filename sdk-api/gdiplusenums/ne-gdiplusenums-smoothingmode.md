# SmoothingMode enumeration

## Description

The **SmoothingMode** enumeration specifies the type of smoothing (antialiasing) that is applied to lines and curves. This enumeration is used by the [Graphics::GetSmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getsmoothingmode) and [Graphics::SetSmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setsmoothingmode) methods of the
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) class.

## Constants

### `SmoothingModeInvalid`

Reserved.

### `SmoothingModeDefault`

Specifies that smoothing is not applied.

### `SmoothingModeHighSpeed`

Specifies that smoothing is not applied.

### `SmoothingModeHighQuality`

Specifies that smoothing is applied using an 8 X 4 box filter.

### `SmoothingModeNone`

Specifies that smoothing is not applied.

### `SmoothingModeAntiAlias`

Specifies that smoothing is applied using an 8 X 4 box filter.

### `SmoothingModeAntiAlias8x4`

Specifies that smoothing is applied using an 8 X 4 box filter.

### `SmoothingModeAntiAlias8x8`

Specifies that smoothing is applied using an 8 X 8 box filter.

## Remarks

Smoothing performed by an 8 X 4 box filter gives better results for nearly vertical lines than it does for nearly horizontal lines. Smoothing performed by an 8 X 8 box filter gives equally good results for nearly vertical and nearly horizontal lines. The 8x8 algorithm produces higher quality smoothing but is slower than the 8 X 4 algorithm.

## See also

[Graphics::GetSmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getsmoothingmode)

[Graphics::SetSmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setsmoothingmode)