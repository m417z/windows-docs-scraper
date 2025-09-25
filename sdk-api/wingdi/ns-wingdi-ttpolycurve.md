# TTPOLYCURVE structure

## Description

The **TTPOLYCURVE** structure contains information about a curve in the outline of a TrueType character.

## Members

### `wType`

The type of curve described by the structure. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| TT_PRIM_LINE | Curve is a polyline. |
| TT_PRIM_QSPLINE | Curve is a quadratic Bézier spline. |
| TT_PRIM_CSPLINE | Curve is a cubic Bézier spline. |

### `cpfx`

The number of [POINTFX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfx) structures in the array.

### `apfx`

Specifies an array of [POINTFX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfx) structures that define the polyline or Bézier spline.

## Remarks

When an application calls the [GetGlyphOutline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphoutlinea) function, a glyph outline for a TrueType character is returned in a [TTPOLYGONHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolygonheader) structure, followed by as many **TTPOLYCURVE** structures as are required to describe the glyph. All points are returned as [POINTFX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfx) structures and represent absolute positions, not relative moves. The starting point specified by the **pfxStart** member of the **TTPOLYGONHEADER** structure is the point at which the outline for a contour begins. The **TTPOLYCURVE** structures that follow can be either polyline records or spline records.

Polyline records are a series of points; lines drawn between the points describe the outline of the character. Spline records represent the quadratic curves (that is, quadratic b-splines) used by TrueType.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetGlyphOutline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphoutlinea)

[POINTFX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfx)

[TTPOLYGONHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolygonheader)