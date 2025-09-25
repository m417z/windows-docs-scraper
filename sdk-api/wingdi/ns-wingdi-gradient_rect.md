# GRADIENT_RECT structure

## Description

The **GRADIENT_RECT** structure specifies the index of two vertices in the *pVertex* array in the **GradientFill** function. These two vertices form the upper-left and lower-right boundaries of a rectangle.

## Members

### `UpperLeft`

The upper-left corner of a rectangle.

### `LowerRight`

The lower-right corner of a rectangle.

## Remarks

The **GRADIENT_RECT** structure specifies the values of the *pVertex* array that are used when the *dwMode* parameter of the [GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill) function is GRADIENT_FILL_RECT_H or GRADIENT_FILL_RECT_V. For related **GradientFill** structures, see [GRADIENT_TRIANGLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_triangle) and [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex).

The following images shows examples of a rectangle with a gradient fill - one in horizontal mode, the other in vertical mode.

![Illustration of a rectangle that shades from dark on the left side to light on the right side](https://learn.microsoft.com/windows/win32/api/wingdi/images/GradientFillRectangle.png)
![Illustration of a rectangle that shades from dark on the top to light on the bottom](https://learn.microsoft.com/windows/win32/api/wingdi/images/GradientFillRectangle2.png)

#### Examples

For an example, see [Drawing a Shaded Rectangle](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-shaded-rectangle).

## See also

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GRADIENT_TRIANGLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_triangle)

[GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill)

[TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex)