# GRADIENT_TRIANGLE structure

## Description

The **GRADIENT_TRIANGLE** structure specifies the index of three vertices in the *pVertex* array in the **GradientFill** function. These three vertices form one triangle.

## Members

### `Vertex1`

The first point of the triangle where sides intersect.

### `Vertex2`

The second point of the triangle where sides intersect.

### `Vertex3`

The third point of the triangle where sides intersect.

## Remarks

The **GRADIENT_TRIANGLE** structure specifies the values in the *pVertex* array that are used when the *dwMode* parameter of the [GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill) function is GRADIENT_FILL_TRIANGLE. For related **GradientFill** structures, see [GRADIENT_RECT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_rect) and [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex).

The following image shows an example of a triangle with a gradient fill.

![Illustration of a triangle that fills from orange at the top point to magenta on the bottom line ](https://learn.microsoft.com/windows/win32/api/wingdi/images/GradientFillTriangle.png)

#### Examples

For an example, see [Drawing a Shaded Triangle](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-shaded-triangle).

## See also

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GRADIENT_RECT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_rect)

[GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill)

[TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex)