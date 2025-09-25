# D2D1_STROKE_STYLE_PROPERTIES structure

## Description

Describes the stroke that outlines a shape.

## Members

### `startCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_cap_style)**

The cap applied to the start of all the open figures in a stroked geometry.

### `endCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_cap_style)**

The cap applied to the end of all the open figures in a stroked geometry.

### `dashCap`

Type: **[D2D1_CAP_STYLE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_cap_style)**

The shape at either end of each dash segment.

### `lineJoin`

Type: **[D2D1_LINE_JOIN](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_line_join)**

A value that describes how segments are joined. This value is ignored for a vertex if the segment flags specify that the segment should have a smooth join.

### `miterLimit`

Type: **FLOAT**

The limit of the thickness of the join on a mitered corner. This value is always treated as though it is greater than or equal to 1.0f.

### `dashStyle`

Type: **[D2D1_DASH_STYLE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_dash_style)**

A value that specifies whether the stroke has a dash pattern and, if so, the dash style.

### `dashOffset`

Type: **FLOAT**

A value that specifies an offset in the dash sequence. A positive dash offset value shifts the dash pattern, in units of stroke width, toward the start of the stroked geometry. A negative dash offset value shifts the dash pattern, in units of stroke width, toward the end of the stroked geometry.

## Remarks

The following illustration shows different *dashOffset* values for the same custom dash style.

![Illustration of four dashes with the same style and different dashOffset values](https://learn.microsoft.com/windows/win32/api/d2d1/images/StrokeStyle_DashOffset.png)