# BitmapBrushProperties1 function

## Description

Creates a [D2D1_BITMAP_BRUSH_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_brush_properties1) structure.

## Parameters

### `extendModeX`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)**

A value that specifies how the brush horizontally tiles those areas that extend past its bitmap. The default value is [D2D1_EXTEND_MODE_CLAMP](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode).

### `extendModeY`

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode)**

A value that specifies how the brush vertically tiles those areas that extend past its bitmap. The default value is [D2D1_EXTEND_MODE_CLAMP](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_extend_mode).

### `interpolationMode`

Type: **[D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode)**

A value that specifies the interpolation algorithm that is used when images are scaled or rotated. The default value is [D2D1_INTERPOLATION_MODE_LINEAR](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode).

## Return value

Type: **[D2D1_BITMAP_BRUSH_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_brush_properties1)**

A structure that describes the extend modes and the interpolation mode of an [ID2D1BitmapBrush1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmapbrush1).