# Matrix3x2F::Scale

## Description

Creates a scale transformation that has the specified scale factors and center point.

## Parameters

### `size`

Type: **[D2D1_SIZE_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-f)**

The x-axis and y-axis scale factors of the scale transformation.

### `center`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The point about which the scale is performed.

## Return value

Type: **[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)**

The new scale transformation.

## Remarks

This method creates a scale transformation for the specified *centerPoint* and scale factors. The scale factors are stored as an ordered pair in the
[D2D1_SIZE_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-f) structure. If you prefer to list each scale factor as a parameter, call the other [Scale](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-matrix3x2f-scale(float_float_d2d1_point_2f)) method.

The following illustration shows the size of the square increased
to 130% in each dimension.
The center point for the scaling is the upper-left corner of the square.

![Illustration of a square scaled by 130% in the x-direction and y-direction](https://learn.microsoft.com/windows/win32/api/d2d1helper/images/scale_ovw.png)

 For an example, see [How to Scale an Object](https://learn.microsoft.com/windows/desktop/Direct2D/how-to-scale).

## See also

[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)