# ID2D1Brush::SetOpacity

## Description

Sets the degree of opacity of this brush.

## Parameters

### `opacity`

Type: **FLOAT**

A value between zero and 1 that indicates the opacity of the brush. This value is a constant multiplier that linearly scales the alpha value of all pixels filled by the brush. The opacity values are clamped in the range 0–1 before they are multiplied together.

## See also

[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)