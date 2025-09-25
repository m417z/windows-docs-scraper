# LOGPEN structure

## Description

The **LOGPEN** structure defines the style, width, and color of a pen. The [CreatePenIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpenindirect) function uses the **LOGPEN** structure.

## Members

### `lopnStyle`

The pen style, which can be one of the following values.

| Value | Meaning |
| --- | --- |
| PS_SOLID | The pen is solid. |
| PS_DASH | The pen is dashed. |
| PS_DOT | The pen is dotted. |
| PS_DASHDOT | The pen has alternating dashes and dots. |
| PS_DASHDOTDOT | The pen has dashes and double dots. |
| PS_NULL | The pen is invisible. |
| PS_INSIDEFRAME | The pen is solid. When this pen is used in any GDI drawing function that takes a bounding rectangle, the dimensions of the figure are shrunk so that it fits entirely in the bounding rectangle, taking into account the width of the pen. This applies only to geometric pens. |

### `lopnWidth`

The [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the pen width, in logical units. If the **x** member is **NULL**, then the pen is one pixel wide on raster devices. The **y** member in the **POINT** structure for **lopnWidth** isn't used.

### `lopnColor`

The pen color. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Remarks

If the width of the pen is greater than 1 and the pen style is PS_INSIDEFRAME, the line is drawn inside the frame of all GDI objects except polygons and polylines. If the pen color does not match an available RGB value, the pen is drawn with a logical (dithered) color. If the pen width is less than or equal to 1, the PS_INSIDEFRAME style is identical to the PS_SOLID style.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[CreatePenIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpenindirect)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[Pen Structures](https://learn.microsoft.com/windows/desktop/gdi/pen-structures)

[Pens Overview](https://learn.microsoft.com/windows/desktop/gdi/pens)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)