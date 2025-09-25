# D2D1_STROKE_TRANSFORM_TYPE enumeration

## Description

Defines how the world transform, dots per inch (dpi), and stroke width affect the shape of the pen used to stroke a primitive.

## Constants

### `D2D1_STROKE_TRANSFORM_TYPE_NORMAL:0`

The stroke respects the currently set world transform, the dpi, and the stroke width.

### `D2D1_STROKE_TRANSFORM_TYPE_FIXED:1`

The stroke does not respect the world transform but it does respect the dpi and stroke width.

### `D2D1_STROKE_TRANSFORM_TYPE_HAIRLINE:2`

The stroke is forced to 1 pixel wide (in device space) and does not respect the world transform, the dpi, or the stroke width.

### `D2D1_STROKE_TRANSFORM_TYPE_FORCE_DWORD:0xffffffff`

## Remarks

If you specify **D2D1_STROKE_TRANSFORM_TYPE_FIXED** the stroke isn't affected by the world transform.

If you specify **D2D1_STROKE_TRANSFORM_TYPE_FIXED** the application has the same behavior in Windows 7 and later.

If you specify **D2D1_STROKE_TRANSFORM_TYPE_HAIRLINE** the stroke is always 1 pixel wide.

Apart from the stroke, any value derived from the stroke width is not affected when the transformType is either fixed or hairline. This includes miters, line caps and so on.

It is important to distinguish between the geometry being stroked and the shape of the stroke pen. When D2D1_STROKE_TRANSFORM_TYPE_FIXED or D2D1_STROKE_TRANSFORM_TYPE_HAIRLINE is specified, the geometry still respects the transform and dpi, but the pen that traces the geometry will not.

Here is an illustration of a stroke with dashing and a skew and stretch transform.

![An illustration of a stroke with dashing and a skew and stretch transform.](https://learn.microsoft.com/windows/win32/api/d2d1_1/images/skewedstroke.png)
And here is an illustration of a fixed width stroke which does not get transformed.

![An illustration of a fixed width stroke which does not get transformed.](https://learn.microsoft.com/windows/win32/api/d2d1_1/images/fixedwidthstroke.png)

## See also

[ID2D1StrokeStyle1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1strokestyle1)