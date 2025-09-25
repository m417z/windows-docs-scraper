# D2D1_BITMAP_BRUSH_PROPERTIES structure

## Description

Describes the extend modes and the interpolation mode of an [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush).

## Members

### `extendModeX`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode)**

A value that describes how the brush horizontally tiles those areas that extend past its bitmap.

### `extendModeY`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode)**

A value that describes how the brush vertically tiles those areas that extend past its bitmap.

### `interpolationMode`

Type: **[D2D1_BITMAP_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode)**

A value that specifies how the bitmap is interpolated when it is scaled or rotated.

## See also

[D2D1_BITMAP_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode)

[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode)