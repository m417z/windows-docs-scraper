# Matrix3x2F::Scale(FLOAT,FLOAT,D2D1_POINT_2F)

## Description

Creates a scale transformation that has the specified scale factors and center point.

## Parameters

### `x`

Type: **FLOAT**

The x-axis scale factor of the scale transformation.

### `y`

Type: **FLOAT**

The y-axis scale factor of the scale transformation.

### `center`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The point about which the scale is performed.

## Return value

Type: **[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)**

The new scale transformation.

## Remarks

This method creates a scale transformation for the specified *centerPoint* and the
x-axis and y-axis scale factors. If you prefer to create a
[D2D1_SIZE_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-f) structure to store the scale factors, call the other [Scale](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-matrix3x2f-scale(d2d1_size_f_d2d1_point_2f)) method.

The following illustration shows the size of the square increased
to 130% in both dimensions.
The center point of the scaling is the upper-left corner of the square.

![Illustration of a square scaled by 130% in the x-direction and y-direction](https://learn.microsoft.com/windows/win32/api/d2d1helper/images/scale_ovw.png)

 For an example, see [How to Scale an Object](https://learn.microsoft.com/windows/desktop/Direct2D/how-to-scale).

## See also

[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)