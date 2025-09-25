# Matrix3x2F::Translation(FLOAT,FLOAT)

## Description

Creates a translation transformation that has the specified x and y displacements.

## Parameters

### `x`

Type: **FLOAT**

The distance to translate along the x-axis.

### `y`

Type: **FLOAT**

The distance to translate along the y-axis.

## Return value

Type: **[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)**

A transformation matrix that translates an object the specified horizontal and vertical distance.

## Remarks

 Translation is an affine transformation, which moves every point by a fixed distance in the same direction. It is similar to shifting the origin of the coordinate space. You can translate an object along the x-axis, the y-axis, or both.

When calling this method, specify the x and y displacements. If you prefer to define both displacements in an ordered pair by using the [D2D1_SIZE_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-size-f) structure, call the other [Translation](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-matrix3x2f-translation(d2d1_size_f)) method. The following illustration shows a square moved 20 pixels to the right along the x-axis, and 10 pixels downward along the y-axis.

![Illustration of the square moved to the right and downward](https://learn.microsoft.com/windows/win32/api/d2d1helper/images/translation_ovw.png)
For an example, see [How to Translate an Object](https://learn.microsoft.com/windows/desktop/Direct2D/how-to-translate).

## See also

[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)