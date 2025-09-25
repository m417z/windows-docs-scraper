# CreatePen function

## Description

The **CreatePen** function creates a logical pen that has the specified style, width, and color. The pen can subsequently be selected into a device context and used to draw lines and curves.

## Parameters

### `iStyle` [in]

The pen style. It can be any one of the following values.

| Value | Meaning |
| --- | --- |
| **PS_SOLID** | The pen is solid. |
| **PS_DASH** | The pen is dashed. This style is valid only when the pen width is one or less in device units. |
| **PS_DOT** | The pen is dotted. This style is valid only when the pen width is one or less in device units. |
| **PS_DASHDOT** | The pen has alternating dashes and dots. This style is valid only when the pen width is one or less in device units. |
| **PS_DASHDOTDOT** | The pen has alternating dashes and double dots. This style is valid only when the pen width is one or less in device units. |
| **PS_NULL** | The pen is invisible. |
| **PS_INSIDEFRAME** | The pen is solid. When this pen is used in any GDI drawing function that takes a bounding rectangle, the dimensions of the figure are shrunk so that it fits entirely in the bounding rectangle, taking into account the width of the pen. This applies only to geometric pens. |

### `cWidth` [in]

The width of the pen, in logical units. If *nWidth* is zero, the pen is a single pixel wide, regardless of the current transformation.

**CreatePen** returns a pen with the specified width but with the PS_SOLID style if you specify a width greater than one for the following styles: PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT.

### `color` [in]

A color reference for the pen color. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) structure, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value is a handle that identifies a logical pen.

If the function fails, the return value is **NULL**.

## Remarks

After an application creates a logical pen, it can select that pen into a device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function. After a pen is selected into a device context, it can be used to draw lines and curves.

If the value specified by the *nWidth* parameter is zero, a line drawn with the created pen always is a single pixel wide regardless of the current transformation.

If the value specified by *nWidth* is greater than 1, the *fnPenStyle* parameter must be PS_NULL, PS_SOLID, or PS_INSIDEFRAME.

If the value specified by *nWidth* is greater than 1 and *fnPenStyle* is PS_INSIDEFRAME, the line associated with the pen is drawn inside the frame of all primitives except polygons and polylines.

If the value specified by *nWidth* is greater than 1, *fnPenStyle* is PS_INSIDEFRAME, and the color specified by the *crColor* parameter does not match one of the entries in the logical palette, the system draws lines by using a dithered color. Dithered colors are not available with solid pens.

When using an *iStyle* parameter of PS_DASH, PS_DOT, PS_DASHDOT or PS_DASHDOTDOT, in order to make the gaps between the dashes or dots transparent, use [SetBkMode](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-setbkmode) to set the mode to TRANSPARENT.

When you no longer need the pen, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

**ICM:** No color management is done at creation. However, color management is performed when the pen is selected into an ICM-enabled device context.

#### Examples

For an example, see [Creating Colored Pens and Brushes](https://learn.microsoft.com/windows/desktop/gdi/creating-colored-pens-and-brushes).

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[CreatePenIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpenindirect)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[Pen Functions](https://learn.microsoft.com/windows/desktop/gdi/pen-functions)

[Pens Overview](https://learn.microsoft.com/windows/desktop/gdi/pens)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)