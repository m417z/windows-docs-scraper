# StrokeStyleProperties function

## Description

Creates a [D2D1_STROKE_STYLE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_stroke_style_properties) structure.

## Parameters

### `startCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style)**

The shape at the beginning of a stroke. The default value is [D2D1_CAP_STYLE_FLAT](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style).

### `endCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style)**

The shape at the end of a stroke. The default value is [D2D1_CAP_STYLE_FLAT](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style).

### `dashCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style)**

The shape at either end of each dash segment. The default value is [D2D1_CAP_STYLE_FLAT](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_cap_style).

### `lineJoin`

Type: **[D2D1_LINE_JOIN](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_line_join)**

A value that describes how segments are joined. The default value is [D2D1_LINE_JOIN_MITER](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_line_join).

### `miterLimit`

Type: **FLOAT**

The limit of the thickness of the join on a mitered corner. This value is always treated as though it is greater than or equal to 1.0f.

The default value is 10.0f.

### `dashStyle`

Type: **[D2D1_DASH_STYLE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_dash_style)**

A value that specifies whether the stroke has a dash pattern and, if so, the dash style.

The default value is [D2D1_DASH_STYLE_SOLID](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_dash_style).

### `dashOffset`

Type: **FLOAT**

A value that specifies how far in the dash sequence the stroke will start.

The default value is 0.0f.

## Return value

Type: **[D2D1_STROKE_STYLE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_stroke_style_properties)**

The new stroke style.