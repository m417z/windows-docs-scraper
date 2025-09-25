# GradientFill function

## Description

The **GradientFill** function fills rectangle and triangle structures.

## Parameters

### `hdc` [in]

A handle to the destination device context.

### `pVertex` [in]

A pointer to an array of [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structures that each define a vertex.

### `nVertex` [in]

The number of vertices in *pVertex*.

### `pMesh` [in]

An array of [GRADIENT_TRIANGLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_triangle) structures in triangle mode, or an array of [GRADIENT_RECT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_rect) structures in rectangle mode.

### `nMesh` [in]

The number of elements (triangles or rectangles) in *pMesh*.

### `ulMode` [in]

The gradient fill mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GRADIENT_FILL_RECT_H** | In this mode, two endpoints describe a rectangle. The rectangle is defined to have a constant color (specified by the [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structure) for the left and right edges. GDI interpolates the color from the left to right edge and fills the interior. |
| **GRADIENT_FILL_RECT_V** | In this mode, two endpoints describe a rectangle. The rectangle is defined to have a constant color (specified by the [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structure) for the top and bottom edges. GDI interpolates the color from the top to bottom edge and fills the interior. |
| **GRADIENT_FILL_TRIANGLE** | In this mode, an array of [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structures is passed to GDI along with a list of array indexes that describe separate triangles. GDI performs linear interpolation between triangle vertices and fills the interior. Drawing is done directly in 24- and 32-bpp modes. Dithering is performed in 16-, 8-, 4-, and 1-bpp mode. |

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

To add smooth shading to a triangle, call the **GradientFill** function with the three triangle endpoints. GDI will linearly interpolate and fill the triangle. Here is the drawing output of a shaded triangle.

![Illustration of a triangle that fills from orange at the top point to magenta on the bottom line ](https://learn.microsoft.com/windows/win32/api/wingdi/images/GradientFillTriangle.png)
To add smooth shading to a rectangle, call **GradientFill** with the upper-left and lower-right coordinates of the rectangle. There are two shading modes used when drawing a rectangle. In horizontal mode, the rectangle is shaded from left-to-right. In vertical mode, the rectangle is shaded from top-to-bottom. Here is the drawing output of two shaded rectangles - one in horizontal mode, the other in vertical mode:

![Illustration of a rectangle that shades from dark on the left side to light on the right side](https://learn.microsoft.com/windows/win32/api/wingdi/images/GradientFillRectangle.png)
![Illustration of a rectangle that shades from dark on the top to light on the bottom](https://learn.microsoft.com/windows/win32/api/wingdi/images/GradientFillRectangle2.png)
The **GradientFill** function uses a mesh method to specify the endpoints of the object to draw. All vertices are passed to **GradientFill** in the *pVertex* array. The *pMesh* parameter specifies how these vertices are connected to form an object. When filling a rectangle, *pMesh* points to an array of [GRADIENT_RECT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_rect) structures. Each **GRADIENT_RECT** structure specifies the index of two vertices in the *pVertex* array. These two vertices form the upper-left and lower-right boundary of one rectangle.

In the case of filling a triangle, *pMesh* points to an array of [GRADIENT_TRIANGLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_triangle) structures. Each **GRADIENT_TRIANGLE** structure specifies the index of three vertices in the *pVertex* array. These three vertices form one triangle.

To simplify hardware acceleration, this routine is not required to be pixel-perfect in the triangle interior.

Note that GradientFill does not use the Alpha member of the [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structure. To use GradientFill with transparency, call GradientFill and then call [AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend) with the desired values for the alpha channel of each vertex.

For more information, see [Smooth Shading](https://learn.microsoft.com/windows/desktop/gdi/smooth-shading), [Drawing a Shaded Triangle](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-shaded-triangle), and [Drawing a Shaded Rectangle](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-shaded-rectangle).

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[EMRGRADIENTFILL](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emrgradientfill)

[GRADIENT_RECT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_rect)

[GRADIENT_TRIANGLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_triangle)

[TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex)