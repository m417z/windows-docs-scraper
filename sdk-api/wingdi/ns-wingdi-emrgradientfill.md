# EMRGRADIENTFILL structure

## Description

The **EMRGRADIENTFILL** structure contains members for the [GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

The bounding rectangle, in device units.

### `nVer`

The number of vertices.

### `nTri`

The number of rectangles or triangles to be passed to [GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill).

### `ulMode`

The gradient fill mode. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GRADIENT_FILL_RECT_H** | In this mode, two endpoints describe a rectangle. The rectangle is defined to have a constant color (specified by the [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structure) for the left and right edges. GDI interpolates the color from the left to right edge and fills the interior. |
| **GRADIENT_FILL_RECT_V** | In this mode, two endpoints describe a rectangle. The rectangle is defined to have a constant color (specified by the [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structure) for the top and bottom edges. GDI interpolates the color from the top to bottom edge and fills the interior. |
| **GRADIENT_FILL_TRIANGLE** | In this mode, an array of [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structures is passed to GDI along with a list of array indexes that describe separate triangles. GDI performs linear interpolation between triangle vertices and fills the interior. Drawing is done directly in 24- and 32-bpp modes. Dithering is performed in 16-, 8-, 4-, and 1-bpp mode. |

### `Ver`

An array of [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structures that each define a vertex.

## Remarks

This is a variable-length structure. The **Ver** member designates the beginning of the variable-length area. First comes an array of **nVer** [TRIVERTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-trivertex) structures to pass the vertices. Next comes an array of either **nTri** [GRADIENT_TRIANGLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_triangle) structures or **nTri** [GRADIENT_RECT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_rect) structures, depending on the value of **ulMode** (triangles or rectangles).

This structure is to be used during metafile playback.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[GRADIENT_RECT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_rect)

[GRADIENT_TRIANGLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gradient_triangle)

[GradientFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gradientfill)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

Metafiles

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)