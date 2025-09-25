# Matrix3x2F::Skew

## Description

Creates a skew transformation that has the specified x-axis and y-axis values and center point.

## Parameters

### `angleX`

Type: **FLOAT**

The x-axis skew angle, which is measured in degrees counterclockwise from the y-axis.

### `angleY`

Type: **FLOAT**

The y-axis skew angle, which is measured in degrees clockwise from the x-axis.

### `center`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The point about which the skew is performed.

## Return value

Type: **[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)**

The new skew transformation.

## Remarks

The typical y-axis skew means skews the angle in degrees counterclockwise from the x-axis. However, because the y-axis in Direct2D is inverted, the y-axis skew angle in Direct2D means skew the angle in degrees clockwise from the x-axis.

For example, the following illustration shows the rectangle skewed with y-axis skew angle of 30 degrees. Notice that the angle is 30 degrees clockwise from the x-axis.

![Illustration of a rectangle that is skewed along the y-axis for 30 degrees](https://learn.microsoft.com/windows/win32/api/d2d1helper/images/skewy.png)

#### Examples

For an example, see [How to Skew an Object](https://learn.microsoft.com/windows/desktop/Direct2D/how-to-skew).

## See also

[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)