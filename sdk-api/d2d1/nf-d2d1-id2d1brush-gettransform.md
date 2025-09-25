# ID2D1Brush::GetTransform

## Description

Gets the transform applied to this brush.

## Parameters

### `transform` [out]

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

The transform applied to this brush.

## Remarks

When the brush transform is the identity matrix, the brush appears in the same coordinate space as the render target in which it is drawn.

## See also

[ID2D1Brush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1brush)